#include<bits/stdc++.h>
using namespace std;
#define FOR(i, a, b) for(int i = a; i <= b; i++)
#define REP(i, a) FOR(i, 0, a - 1)
#define ST first
#define ND second
#define V vector
#define RS resize
#define EB emplace_back
#define ALL(a) a.begin(), a.end()
#define S(a) (int)a.size()
using LL = long long;
using PII = pair<int, int>;
using VI = V<int>;
using VLL = V<LL>;
using VVI = V<VI>;
using VPII = V<PII>;
using VB = V<bool>;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    VVI p(m);
    REP(i, n)
    {
        int s, r;
        cin >> s >> r;
        p[s - 1].EB(r);
    }

    REP(i, m)
        sort(p[i].rbegin(), p[i].rend());

    VLL ans(n);
    LL mx = 0;
    REP(i, m)
    {
        REP(j, S(p[i]))
        {
            if(p[i][j] > 0)
                ans[j] += p[i][j];
            mx = max(mx, ans[j]);
            if(j + 1 < S(p[i]))
                p[i][j + 1] += p[i][j];
        }
    }

    cout << mx << "\n";
}