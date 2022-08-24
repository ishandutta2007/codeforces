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
const int MAXN = 100100;

int N;
ll L[MAXN];
char ct[MAXN];
ll cval[MAXN];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> L[i];
    for (int i = 0; i < N; i++)
        cin >> ct[i];

    bool wseen = false;
    ll gc = 0, wc = 0;
    ll ncharge = 0, ntime = 0;
    for (int i = 0; i < N; i++)
    {
        if (ct[i] == 'L')
        {
            if (ncharge >= L[i])
            {
                ncharge -= L[i];
                ntime += L[i];
            }
            else
            {
                ll ndiff = (L[i] - ncharge);
                ntime += L[i];
                ncharge = 0;
                if (wseen)
                {
                    ntime += 3 * ndiff;
                    wc += ndiff;
                }
                else
                {
                    ntime += 5 * ndiff;
                    gc += ndiff;
                }
            }
        }
        else if (ct[i] == 'W')
        {
            wseen = true;
            ncharge += L[i];
            ntime += 3 * L[i];
        }
        else
        {
            ncharge += L[i];
            ntime += 5 * L[i];
        }
    }

    ncharge = 0;
    for (int i = 0; i < N; i++)
    {
        cval[i] = ncharge;
        if (ct[i] == 'L')
        {
            if (ncharge >= L[i])
            {
                ncharge -= L[i];
            }
            else
            {
                ncharge = 0;
            }
        }
        else if (ct[i] == 'W')
        {
            if (wc)
            {
                ncharge += wc;
                wc = 0;
            }
            ncharge += L[i];
        }
        else
        {
            if (gc)
            {
                ncharge += gc;
                gc = 0;
            }
            ncharge += L[i];
        }
    }

    ll ng = 0;
    for (int i = N - 1; i >= 0; i--)
    {
        if (ct[i] == 'G')
            ng += 2 * L[i];

        if (cval[i] < ncharge)
        {
            ll ndiff = ncharge - cval[i];
            if (ng >= ndiff)
            {
                ng -= ndiff;
                ntime -= 2 * ndiff;
            }
            else
            {
                ntime -= ndiff + ng;
                ng = 0;
            }
            ncharge = cval[i];
        }
    }
    cout << ntime << "\n";
}