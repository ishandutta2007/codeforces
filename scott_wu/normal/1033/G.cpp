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
const int MAXN = 110;

int N, M;
ll v[MAXN];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    
    cin >> N >> M;
    for (int i = 0; i < N; i++)
        cin >> v[i];

    ll anst = 0, ansf = 0, anss = 0;
    for (int tsum = 2; tsum <= 2 * M; tsum++)
    {
        int lo = max (1, tsum - M);
        int hi = (tsum - 1) / 2; // add even mids later

        int wlo = lo - 1; // all #s <= wlo lose
        int pbig = 0;
        int fmax = 0, smax = 0;

        for (int i = 0; i < N; i++)
        {
            int cv = v[i] % tsum;
            if (cv <= hi)
                wlo = max (wlo, cv);
            else
            {
                wlo = max (wlo, tsum - cv - 1);
                pbig = 1 - pbig;

                if (cv > smax)
                {
                    smax = cv;
                    if (smax > fmax)
                        swap (smax, fmax);
                }
            }
        }
        wlo = max (wlo, smax / 2);
        anst += (wlo - lo + 1);
        int nf = max (wlo, fmax / 2);
        if (pbig % 2 == 0)
        {
            anst += nf - wlo;
            anss += hi - nf;
        }
        else
        {
            ansf += nf - wlo;
            ansf += hi - nf;
        }

        //cout << tsum << " " << lo << " " << hi << " " << wlo << " " << nf << " " << pbig << "\n";
    }
    ansf *= 2;
    anss *= 2;

    for (int i = 1; i <= M; i++)
    {
        int ntot = 0;
        for (int j = 0; j < N; j++)
        {
            if (v[j] % (2 * i) >= i)
                ntot = 1 - ntot;
        }
        if (ntot)
            ansf++;
        else
            anss++;
    }

    cout << anst << " " << anst << " " << ansf << " " << anss << "\n";
}