#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll n;

int main() {
    scanf("%I64d", &n);
    int k = (int) (sqrt(2 * n) + 0.5);
    cout<<n - 1ll * k * (k - 1) / 2;
    return 0;
}