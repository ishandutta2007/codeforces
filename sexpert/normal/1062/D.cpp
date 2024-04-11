#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 2;
/*int sv[MAXN];

void sieve()
{
    for(int p = 2; p < MAXN; p++)
    {
        if(!sv[p])
        {
            for(int q = 2*p; q < MAXN; q += p)
                sv[q] = p;
        }
    }
}*/

int main()
{
    //sieve();
    long long n, ans = 0;
    cin >> n;
    for(long long k = 2; k < n; k++)
    {
        long long d = n / k;
        ans += d*(d + 1)/2 - 1;
    }
    cout << 4ll*ans << endl;
}