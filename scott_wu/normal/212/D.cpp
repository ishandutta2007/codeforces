#include <iostream>
#include <iomanip>
#include <algorithm>
#include <queue>
#include <cmath>
#include <vector>
#include <string>

using namespace std;
typedef long long ll;
const int MAXN = 1000100;
const int INF = 1e8;

int N, M;
int query[MAXN];
ll num[MAXN];
int l[MAXN], r[MAXN];
deque <pair <int, int> > q;
ll change[MAXN];
double ans[MAXN];

int main()
{
    for (int i = 0; i < MAXN; i++)
        change[i] = 0;
    
    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> num[i];
    cin >> M;
    for (int i = 0; i < M; i++)
        cin >> query[i];
    
    q.push_front (make_pair (-INF, -1));
    for (int i = 0; i < N; i++)
    {
        while (q.back().first >= num[i])
            q.pop_back();
        l[i] = i - q.back().second;
        q.push_back (make_pair (num[i], i));
    }
    
    while (!q.empty())
        q.pop_back();
    
    q.push_front (make_pair (-INF, N));
    for (int i = N - 1; i >= 0; i--)
    {
        while (q.back().first > num[i])
            q.pop_back();
        r[i] = q.back().second - i;
        q.push_back (make_pair (num[i], i));
    }
    
    for (int i = 0; i < N; i++)
    {
        change[0] += num[i];
        change[l[i]] -= num[i];
        change[r[i]] -= num[i];
        change[l[i]+r[i]] += num[i];
    }
    
    //for (int i = 0; i < N; i++)
    //    cout << l[i] << " " << r[i] << "\n";
    
    ll slope = 0, tot = 0;
    for (int i = 0; i < N; i++)
    {
        slope += change[i];
        tot += slope;
        //cout << slope << " " << tot << "\n";
        ans[i+1] = ((double) tot) / ((double) N - i);
    }
    //cout << "\n";
    
    cout << fixed << setprecision (10);
    for (int i = 0; i < M; i++)
        cout << ans[query[i]] << "\n";
    //system ("Pause");
    return 0;
}