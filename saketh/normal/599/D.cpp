#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;

ull x;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0), cout.precision(15);

    cin >> x;
    x *= 6;

    vector<pair<ull, ull>> solns;

    for (ull N = 1; ; N++) {
        ull M = x / N;
        M += N * N - 1;

        ull D = 3 * N + 3;

        if ((M + D - 1) / D < N) break;

        if (x % N != 0) continue;

        if (M % D == 0) {
            M /= D;

            solns.emplace_back(N, M);
            if (M != N) 
                solns.emplace_back(M, N);
        }
    }

    sort(solns.begin(), solns.end());

    cout << solns.size() << "\n";

    for (auto p : solns)
        cout << p.first << " " << p.second << "\n";
}