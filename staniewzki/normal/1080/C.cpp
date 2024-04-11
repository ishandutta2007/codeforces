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
    
    int t;
    cin >> t;
    REP(_t, t)
    {
        LL n, m;
        cin >> n >> m;

        LL b = n * m / 2;
        LL w = n * m - b;

        LL x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        LL s;
        //get black
        LL q = (x2 - x1 + 1) * (y2 - y1 + 1) / 2; //lower
        LL r = (x2 - x1 + 1) * (y2 - y1 + 1) - q; //higher
        if((x1 + y1) % 2 == 0) // is corner white
            s = q;
        else
            s = r;
        b -= s;
        w += s;

        LL x3, y3, x4, y4;
        cin >> x3 >> y3 >> x4 >> y4;

        //get white
        q = (x4 - x3 + 1) * (y4 - y3 + 1) / 2; //lower
        r = (x4 - x3 + 1) * (y4 - y3 + 1) - q; //higher
        if((x3 + y3) % 2 == 0) // is corner white
            s = r;
        else
            s = q;
        w -= s;
        b += s;

        LL x5 = max(x1, x3);
        LL y5 = max(y1, y3);
        LL x6 = min(x2, x4);
        LL y6 = min(y2, y4);

        if(x5 <= x6 && y5 <= y6)
        {
            //get black
            q = (x6 - x5 + 1) * (y6 - y5 + 1) / 2;
            r = (x6 - x5 + 1) * (y6 - y5 + 1) - q;
            if((x5 + y5) % 2 == 0)
                s = q;
            else
                s = r;
            w -= s;
            b += s;
        }

        cout << w << " " << b << "\n";
    }
}