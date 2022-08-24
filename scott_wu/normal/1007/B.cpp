#include <iostream>
#include <iomanip>
#include <map>
#include <algorithm>
#include <vector>
#include <string>
#include <set>

using namespace std;
typedef long long ll;
const int MAXN = 100100;

int T;
int A, B, C;
int D, E, F, G;

int pfac[MAXN];

int nfac (int x)
{
    int ans = 1;
    int cfac = -1, cc = 0;
    while (x > 1)
    {
        int nfac = pfac[x];
        if (nfac == cfac)
        {
            cc++;
        }
        else
        {
            ans *= (cc + 1);
            cc = 1;
            cfac = nfac;
        }
        x /= nfac;
    }
    ans *= cc + 1;
    return ans;
}

int gcf (int x, int y)
{
    if (y == 0)
        return x;
    return gcf (y, x % y);
}

set <int> s;
vector <int> t;
int nc[3][4];
int p[7];
int hv[3];

int get_res()
{
    D = gcf (B, C);
    E = gcf (A, C);
    F = gcf (A, B);
    G = gcf (D, E);

    int a = nfac (A), b = nfac (B), c = nfac (C), d = nfac (D), e = nfac (E), f = nfac (F), g = nfac (G);
    d -= g;
    e -= g;
    f -= g;
    a -= e + f + g;
    b -= d + f + g;
    c -= d + e + g;
    //cout << a << b << c << d << e << f << g << "\n";
    p[0] = a;
    p[1] = b;
    p[2] = c;
    p[3] = d;
    p[4] = e;
    p[5] = f;
    p[6] = g;
    int res = 0;
    for (set <int>::iterator it = s.begin(); it != s.end(); it++)
    {
        int b = *it;
        //cout << b << "\n";
        int ans = 1;
        int nl = -1, nc = 0;
        for (int i = 0; i < 3; i++)
        {
            int cv = b % 10;
            //cout << p[cv] << "\n";
            if (cv == nl)
            {
                //cout << nc << " " << i << " " << ans << " ";
                ans *= (p[cv] + nc);
                ans /= (nc + 1);
                //cout << ans << "\n";
                nc++;
            }
            else
            {
                ans *= p[cv];
                nl = cv;
                nc = 1;
            }
            b/=10;
        }
        res += ans;
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(0);
    for (int i = 0; i < 3; i++)
    {
        nc[i][0] = i;
        nc[i][1] = (i + 1) % 3 + 3;
        nc[i][2] = (i + 2) % 3 + 3;
        nc[i][3] = 6;
    }

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            for (int k = 0; k < 4; k++)
            {
                hv[0] = nc[0][i];
                hv[1] = nc[1][j];
                hv[2] = nc[2][k];
                sort (hv, hv + 3);
                int ssum = hv[0] * 100 + hv[1] * 10 + hv[2];
                if (s.find(ssum) != s.end())
                {
                    t.push_back(ssum);
                }
                s.insert(hv[0] * 100 + hv[1] * 10 + hv[2]);
            }
        }
    }


    for (int i = 0; i < MAXN; i++)
    {
        pfac[i] = -1;
    }
    for (int i = 2; i < MAXN; i++)
    {
        if (pfac[i] == -1)
        {
            for (int j = i; j < MAXN; j += i)
                pfac[j] = i;
        }
    }

    cin >> T;
    for (int i = 0; i < T; i++)
    {
        cin >> A >> B >> C;
        cout << get_res() << "\n";
    }
}