#include <iostream>
#include <algorithm>
typedef long long ll;

using namespace std;

ll* pref;


ll suma(int l, int r)
{
    return pref[r] - pref[l];
}

int main()
{                           
    int n, k;
    cin >> n >> k;
    int a[100000];
    for (int i = 0; i < n; ++i) cin >> a[i];
    sort(a, a + n);
    pref = new ll[100000];
    pref[0] = 0;                   
    for (int i = 1; i <= n; ++i)
        pref[i] = pref[i - 1] + a[i - 1];
    int maxx = 0;
    int maxi = 0;       
    for (int i = 0; i < n; ++i)
    {
        int L = 0, R = i + 1;
        while (R - L > 1)
        {
            int M = (R + L) / 2;
            if (suma(i - M, i) + k >= 1LL * M * a[i])
                L = M;
            else
                R = M;
        }
        if (L + 1 > maxx)
        {
            maxx = L + 1;
            maxi = a[i];
        }
    }                
    cout << maxx << ' ' << maxi;
}