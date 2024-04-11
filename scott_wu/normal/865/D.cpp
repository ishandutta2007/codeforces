#include <iostream>
#include <iomanip>
#include <fstream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <queue>

using namespace std;
typedef long long ll;
const int MAXN = 300100;

int N;
ll p[MAXN];
priority_queue <ll> q; // -score

int main()
{
    ios_base::sync_with_stdio(0);
    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> p[i];

    ll ans = 0;
    for (int i = 0; i < N; i++)
    {
        //cout << ans << " " << p[i] << " " << (q.empty() ? 0 : -q.top()) << "\n";
        if (!q.empty() && -q.top() < p[i])
        {
            ans += p[i] + q.top();
            q.pop();
            q.push(-p[i]);
            q.push(-p[i]);
        }
        else
        {
            q.push(-p[i]);
        }
    }
    cout << ans << "\n";
    return 0;
}