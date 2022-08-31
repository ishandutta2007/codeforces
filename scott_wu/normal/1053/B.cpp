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
const int MAXN = 300100;
const int MAXD = 63;

int N;
ll arr[MAXN];
ll nc[MAXN];
ll ps[2][MAXN];
ll nlast[MAXD];
ll ans;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        ll x; cin >> x;
        arr[i] = __builtin_popcountll(x);
    }

    for (int i =0 ; i < MAXD; i++)
        nlast[i] = -1;
    ps[0][1] = 1;
    ans = 0;
    ll ctot = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j <= arr[i]; j++)
            nlast[j] = i;
        ctot += arr[i];

        ll npar = ctot % 2;
        ll res = 0;
        for (int j = 0; j < MAXD - 1; j++)
        {
            if (nlast[j] > nlast[j+1])
            {
                int start = nlast[j+1] + 1, end = nlast[j];
                //cout << j << " " << start << " " << end << "\n";
                int nend = end;
                if (ctot - nc[end] >= 2 * j)
                {

                }
                else
                {
                    int lo = start, hi = end;
                    while (lo < hi)
                    {
                        int mid = (lo + hi + 1) / 2;
                        if (ctot - nc[mid] >= 2 * j)
                            lo = mid;
                        else
                            hi = mid - 1;
                    }
                    nend = lo;
                }

                if (ctot - nc[start] < 2 * j) continue;
                //cout << i << " " << start << " " << nend << " " << npar << "\n";
                res += ps[npar][nend+1] - ps[npar][start];
            }
        }
        ans += res;

        nc[i+1] = ctot;
        ps[0][i+2] = ps[0][i+1];
        ps[1][i+2] = ps[1][i+1];
        ps[npar][i+2]++;
    }

    cout << ans << "\n";
}