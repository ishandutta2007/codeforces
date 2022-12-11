#include <bits/stdc++.h>

using namespace std;
using ll = long long;
constexpr ll MOD = 1000000007;

/* SOLVE NOTES
(S + a) / n >= (T - b) / m
then
S / n < T / m

we have 
S / n - T / m >= - a / n - b / m
S / n - T / m < 0 

  3 -3      
1 5 -5 2 => 1 0 0 2
            1/2 1/2 0 2
            1/2 1/4 1/4 2
            1/3 1/3 1/3 2

A x y
P: A A+x A+x+y

[x > y]
A x+y/2 x+y/2
P: A A+(x+y)/2 A+x+y

YOU TAKE THE LOWER HULL!
*/

int main() {
    int n; scanf("%d", &n);
    vector<int> c(n), b(n-1);
    for (int i = 0; i < n; ++i) scanf("%d", &c[i]);
    for (int i = 0; i < n - 1; ++i) scanf("%d", &b[i]);
    vector<int> bDeduction(n);
    for (int i = 0; i < n - 1; ++i) bDeduction[i + 1] = bDeduction[i] + b[i];
    for (int i = 0; i < n - 1; ++i) bDeduction[i + 1] += bDeduction[i];
    int q; scanf("%d", &q);
    ll maxSum = accumulate(begin(c), end(c), 0LL);
    while (q--) {
        int x; scanf("%d", &x);
        // count the number of ways to be at i, with a partial sum of P,
        // without going below the (0, 0) - (1, x) line

        // consider a[0], a[1] - b[0], a[2] - b[0] - b[1], ...
        // so we only have to average points
        // then consider the partial sums of these
        // so 0, a[0], a[0] + a[1] - b[0], ...
        // so an average becomes a take-the-midpoint
        // but this ONLY works if you're bumping down a concave section
        // maxsum here is without bDeduction

        // x y z
        // 0, x, x + y - 2, x + y + z - 5
        // 0 1 4
        // 0 -1 1
        // 0 0 -1 0
        // 0 -1/2 -1 0
        // 0 -1/2 -1/2 1
        vector<vector<ll>> waysToBeAt(n + 1, vector<ll>(maxSum + 1));
        waysToBeAt[0][0] = 1;
        for (int elem = 1; elem <= n; ++elem) {
            for (int s = 0; s <= maxSum; ++s) {
                int actualYC = s - bDeduction[elem-1];
                if (actualYC < x * elem) continue;
                for (int vTaken = 0; vTaken <= c[elem-1]; ++vTaken) {
                    if (s - vTaken < 0) continue;
                    waysToBeAt[elem][s] = (waysToBeAt[elem][s] + 
                            waysToBeAt[elem-1][s-vTaken]) % MOD;
                }
            }
        }
        printf("%lld\n", accumulate(begin(waysToBeAt[n]), end(waysToBeAt[n]), 0LL) % MOD);
    }
}