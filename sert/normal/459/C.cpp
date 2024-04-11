#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 1e6 + 34;

ll n, k, d, kk = 1, ng;
int main() {
    // freopen("a.in", "r", stdin);
    // freopen("a.out", "w", stdout);
    
    cin >> n >> k >> d;

    for (int i = 0; i < d; i++)
        kk = min(n, kk * k);
    if (kk < n) {
        cout << -1;
        return 0;
    } 
    kk = 1;

    for (int i = 0; i < d; i++) {
        if (kk > n)
            kk = n;
        for (int j = 0; j < n; j++) {
            ng = j / kk;
            printf("%d ", 1 + ng % k);
        }
        printf("\n");
        kk *= k;
    }

    return 0;
}