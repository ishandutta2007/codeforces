#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <cmath>
#include <queue>

using namespace std;
typedef long long ll;
const int MAXN = 12;

int N;
ll num[MAXN];
int nprime[MAXN];
int res;

ll cpow[MAXN];

int xval[MAXN];
int xcount[MAXN];

int main()
{
    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> num[i];
    
    sort (num, num + N);
    for (int i = 0; i < N / 2; i++)
        swap (num[i], num[N-1-i]);
    
    for (int i = 0; i < N; i++)
    {
        ll temp = num[i];
        
        nprime[i] = 0;
        while (temp % 2 == 0)
        {
            temp /= 2;
            nprime[i]++;
        }
        for (ll j = 3; j * j <= temp; j += 2)
        {
            while (temp % j == 0)
            {
                temp /= j;
                nprime[i]++;
            }
        }
        
        if (temp > 1)
            nprime[i]++;
    }
    
    for (int i = 0; i < N; i++)
        xval[i] = i;
    
    res = 1e9;
    
    do
    {
        for (int i = N - 1; i >= 0; i--)
        {
            xcount[i] = 0;
            for (int j = i + 1; j < N; j++)
                if (xval[i] > xval[j])
                    xcount[i]++;
        }
        for (int i = 0; i < N / 2; i++)
            swap (xcount[i], xcount[N-1-i]);
        
        bool bad = false;
        for (int i = 0; i < N; i++)
            cpow[i] = 1;
        
        for (int i = 0; i < N; i++)
            if (xcount[i])
            {
                if (cpow[xcount[i]-1] * (double) num[i] > 1e18)
                    bad = true;
                else
                    cpow[xcount[i]-1] *= num[i];
            }
        
        for (int i = 0; i < N; i++)
            if (num[i] % cpow[i] != 0)
                bad = true;
        
        if (bad) continue;
        
        int tot = 0;
        int ccount = 0;
        for (int i = 0; i < N; i++)
            if (!xcount[i])
            {
                tot += nprime[i];
                ccount++;
            }
        
        if (ccount > 1) tot++;
        for (int i = 0; i < N; i++)
            if (nprime[i] > 1)
                tot++;
        res = min (res, tot);
    } while (next_permutation (xval, xval + N));
    
    cout << res << "\n";
    //system ("Pause");
    return 0;
}