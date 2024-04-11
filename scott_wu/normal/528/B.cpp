#include <iostream>
#include <cstdio>
#include <algorithm>
#include <map>
#include <vector>
#include <string>
#include <queue>

using namespace std;
typedef long long ll;
const int MAXN = 200100;

int N;
pair<int, int> crange[MAXN];

bool cmp (pair<int, int> left, pair<int, int> right)
{
    return left.second < right.second;
}

int main()
{
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int x, w;
        cin >> x >> w;
        crange[i] = make_pair (x - w, x + w);
    }
    
    sort (crange, crange + N, cmp);
    
    int ans = 1, lval = crange[0].second;
    for (int i = 1; i < N; i++)
    {
        if (crange[i].first >= lval)
        {
            lval = crange[i].second;
            ans++;
        }
    }
    cout << ans << "\n";
    return 0;
}