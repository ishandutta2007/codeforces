#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0), cout.precision(15);

    ll N;
    cin >> N;

    ll A = 1;
    for (ll p = 2; p * p <= N; p++) {
        if (N % p) continue;
        A *= p;
        while (N % p == 0) N /= p;
    }

    A *= N;
    cout << A << "\n";
}