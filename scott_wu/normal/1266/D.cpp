#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int MAXN = 300100;

int N, M;
ll d[MAXN];
vector <pair <pair <int, int>, ll> > ans;

int main()
{
    ios_base::sync_with_stdio(0);

    cin >> N >> M;
    for (int i = 0; i < M; i++)
    {
        int a, b, nd;
        cin >> a >> b >> nd;
        a--, b--;
        d[a] += nd;
        d[b] -= nd;
    }

    vector <int> l, r;
    for (int i = 0; i < N; i++)
    {
        if (d[i] < 0)
        {
            l.push_back(i);
            d[i] = -d[i];
        }
        else if (d[i] > 0)
            r.push_back(i);
    }

    int cr = 0;
    for (int x : l)
    {
        while (d[x])
        {
            ll dv = min (d[x], d[r[cr]]);
            if (dv)
            {
                ans.push_back(make_pair (make_pair (r[cr], x), dv));
                d[x] -= dv;
                d[r[cr]] -= dv;
            }
            if (!d[r[cr]])
                cr++;
        }
    }

    cout << ans.size() << "\n";
    for (auto x : ans)
    {
        cout << x.first.first + 1 << " " << x.first.second + 1 << " " << x.second << "\n";
    }
}