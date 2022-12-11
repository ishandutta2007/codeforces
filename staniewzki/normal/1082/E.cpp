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

    int n, c;
    cin >> n >> c;
    VI a(n), q(n);
    VVI p(5e5);
    REP(i, n)
    {
        cin >> a[i];
        q[i] = (i != 0 ? q[i - 1] : 0) + (a[i] == c);
        p[a[i] - 1].EB(i);
    }

    int C = S(p[c - 1]);
    int mx = 0;
    REP(i, 5e5)
    {
        if(i == c - 1)
        {
            mx = max(mx, C);
            continue;
        }

        int g = 0;
        REP(j, S(p[i]))
        {
            g = min(g, j - q[p[i][j]]);
            int s = 1 + j - q[p[i][j]];
            mx = max(mx, C + s - g);
            g = min(g, s);
        }
    }
    cout << mx << "\n";
}