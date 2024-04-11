#include<bits/stdc++.h>
#define int long long
using namespace std;

int mod = 1000000007;

int silnia(int n) {
    int wynik = 1;
    for (int i = 2; i <= n; i++) {
        wynik *= i;
        wynik %= mod;
    }
    return wynik;
}

int pot(int x, int p) {
    if (p == 0)
        return 1;
    int wynik = pot(x, p / 2);
    wynik *= wynik;
    wynik %= mod;
    if (p % 2) {
        wynik *= x;
    }
    return wynik %= mod;
}

int32_t main() {
    int n;
    cin >> n;
    int licz = silnia(2 * n + 2);
    int mian = pot(silnia(n + 1), mod - 2);
    cout << (((licz * mian) % mod * mian) % mod -1 + mod) % mod;
}