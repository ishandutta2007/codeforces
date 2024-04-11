#include <iostream>
#include <iomanip>
#include <algorithm>
#include <map>
#include <vector>
#include <string>
#include <set>
#include <cmath>

using namespace std;
typedef long long ll;
const int MAXN = 1000100;
const int P = 918357;
const int MOD1 = 1e9 + 7, MOD2 = 1e9 + 9;

int N, M;
int n0, n1;
string s;
string t;

ll hval1[MAXN], hval2[MAXN];
ll cpow1[MAXN], cpow2[MAXN];

ll ghash (int cloc, int len)
{
    ll h1 = ((hval1[cloc+len] - cpow1[len] * hval1[cloc]) % MOD1 + MOD1) % MOD1;
    ll h2 = ((hval2[cloc+len] - cpow2[len] * hval2[cloc]) % MOD2 + MOD2) % MOD2;
    return h1 * MOD2 + h2;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    cpow1[0] = cpow2[0] = 1;
    for (int i = 1; i < MAXN; i++)
    {
        cpow1[i] = (cpow1[i-1] * P) % MOD1;
        cpow2[i] = (cpow2[i-1] * P) % MOD2;
    }

    cin >> s >> t;
    N = s.length();
    M = t.length();

    hval1[0] = hval2[0] = 0;
    for (int i = 0; i < M; i++)
    {
        hval1[i+1] = (hval1[i] * P + t[i]) % MOD1;
        hval2[i+1] = (hval2[i] * P + t[i]) % MOD2;
    }

    n0 = n1 = 0;
    for (int i = 0; i < N; i++)
    {
        if (s[i] == '0')
            n0++;
        else
            n1++;
    }

    int ans = 0;
    for (int nleft = 1; nleft * n0 <= M; nleft++)
    {
        int nright = (M - nleft * n0) / n1;
        if (nright >= 1 && nleft * n0 + nright * n1 == M)
        {
            ll h0 = -1, h1 = -1;
            bool bad = false;
            int cloc = 0;
            for (int i = 0; i < N; i++)
            {
                if (s[i] == '0')
                {
                    ll hnew = ghash (cloc, nleft);
                    if (h0 == -1)
                        h0 = hnew;
                    else if (h0 != hnew)
                        bad = true;
                    cloc += nleft;
                }
                else
                {
                    ll hnew = ghash (cloc, nright);
                    if (h1 == -1)
                        h1 = hnew;
                    else if (h1 != hnew)
                        bad = true;
                    cloc += nright;
                }
            }

            if (nleft == nright && h0 == h1)
                bad = true;

            if (!bad)
            {
                ans++;
                //cout << nleft << " " << nright << " " << h0 << " " << h1 << endl;
            }
        }
    }
    cout << ans << "\n";
}