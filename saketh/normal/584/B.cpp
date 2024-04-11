#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MOD = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0), cout.precision(15);

    int N;
    cin >> N;

    ll all = 1;
    for (int i = 0; i < 3 * N; i++)
        all = all * 3 % MOD;

    ll bad = 1;
    for (int i = 0; i < N; i++)
        bad = bad * 7 % MOD;

    cout << (all - bad + MOD) % MOD << "\n";
}