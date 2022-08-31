#include <iostream>
#include <iomanip>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <set>

using namespace std;
typedef long long ll;
const int MAXN = 3100;

int N, M;
pair <int, int> x[MAXN];

ll ans;
vector <int> v;

ll gval (int k)
{
    v.clear();

    int ctot = 0;
    int cc = 0;
    ll res = 0;
    for (int i = N - 1; i >= 0; i--)
    {
        if (x[i].first == 1)
        {
            ctot++;
            continue;
        }

        if (i < N - 1 && x[i].first != x[i+1].first)
            cc = 0;
        cc++;
        if (cc >= k)
        {
            ctot++;
            res += x[i].second;
        }
        else
        {
            v.push_back(x[i].second);
        }
    }
    sort (v.begin(), v.end());
    for (int i = 0; i + ctot < k; i++)
    {
        res += v[i];
    }
    //cout << ctot << " " << res << " " << v.size() << " " << k << "\n";
    return res;
}

int main()
{
    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        cin >> x[i].first >> x[i].second;
    }

    sort (x, x + N);
    ans = 1e15;
    for (int i = 1; i <= N; i++)
        ans = min (ans, gval (i));

    cout << ans << "\n";
}