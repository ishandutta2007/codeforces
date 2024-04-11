#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXN = 128;

int N, D;
int song[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0), cout.precision(15);

    cin >> N >> D;

    int tot = (N - 1) * 10;

    for (int i = 0; i < N; i++) {
        cin >> song[i];
        tot += song[i];
    }

    if (tot > D) cout << -1 << "\n";
    else cout << (D - tot) / 5 + 2 * (N - 1) << "\n";
}