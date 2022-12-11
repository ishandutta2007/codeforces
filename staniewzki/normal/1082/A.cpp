#include<bits/stdc++.h>
using namespace std;
#define FOR(i, a, b) for(long long i = a; i <= b; i++)
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

    int t;
    cin >> t;
    REP(i, t)
    {
        int n, x, y, d;
        cin >> n >> x >> y >> d;

        if(abs(y - x) % d == 0)
        {
            cout << abs(y - x) / d << "\n";
            continue;
        }

        LL a1 = 1e18;
        if(y % d == 1)
            a1 = (x - 1) / d + (x - 1 % d != 0) + (y - 1) / d;

        x = n + 1 - x;
        y = n + 1 - y;

        LL a2 = 1e18;
        if(y % d == 1)
            a2 = (x - 1) / d + (x - 1 % d != 0) + (y - 1) / d;

        LL a3 = min(a1, a2);
        if(a3 == 1e18)
            a3 = -1;
        cout << a3 << "\n";
    }
}