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

ll N, K, L, R;
ll G, A;
ll ans;

void run (int use, ll ntot)
{
    if (N <= 500000)
    {
        for (int nplus = 0; nplus <= N - 1; nplus++)
        {
            ll rr = (N + nplus + use);
            ll rv = G + (1 + use);
            ll nbefore = ((ntot - rv) % rr + rr) % rr;
            ll nafter = nplus - nbefore;

            if (nbefore >= 0 && nbefore <= G && nafter >= 0 && nafter <= A)
                ans = max (ans, (ll) nplus + use);
        }
    }
    else
    {
        if (G + 1 + use <= ntot)
        {
            ll rv = ntot - G - 1 - use;
            if (rv <= G)
                ans = max (ans, rv + use + A);
        }

        for (int nrun = 1; nrun * N <= ntot; nrun++)
        {
            ll nstart = (nrun * (N + use)) + (G + 1 + use);
            // nrun+1 of before, nrun of after
            ll nleft = ntot - nstart;
            if (nleft >= 0)
            {
                ll nbefore = nleft % nrun;
                ll nafter = (nleft - ((nrun + 1) * (nbefore))) / nrun;
                if (nafter > A)
                {
                    ll ndrop = (nafter - A + nrun) / (nrun + 1);
                    nafter -= ndrop * (nrun + 1);
                    nbefore += ndrop * nrun;
                }
                if (nafter >= 0 && nafter <= A && nbefore >= 0 && nbefore <= G)
                    ans = max (ans, nbefore + nafter + use);
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin >> N >> L >> R >> K;

    G = (R - L + N) % N;
    A = (N - 1 - G);
    ans = -1;
    for (int i = 0; i <= 1; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            run (i, K + j);
        }
    }
    cout << ans << "\n";
}