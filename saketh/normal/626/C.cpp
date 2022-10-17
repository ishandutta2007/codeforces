#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int N, M;

bool pos(int lim) {
    int threes = lim / 3;
    int twos = lim / 2;

    int sixes = lim / 6;
    threes -= sixes;
    twos -= sixes;

    int NN = max(0, N - twos);
    int MM = max(0, M - threes);

    return (NN + MM) <= sixes;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0), cout.precision(15);

    cin >> N >> M;

    int lo = 0, hi = 1e8;
    int ans = hi;

    while (lo <= hi) {
        int mi = (lo + hi) / 2;

        if (pos(mi)) {
            ans = mi;
            hi = mi - 1;
        }
        else {
            lo = mi + 1;
        }
    }

    cout << ans << "\n";
    return 0;
}