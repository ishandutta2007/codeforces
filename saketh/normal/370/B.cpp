#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAXN = 105;

int N, Q;
vector<int> need[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0), cout.precision(15);

    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> Q;
        need[i].resize(Q);

        for (int j = 0; j < Q; j++)
            cin >> need[i][j];
    }

    for (int i = 0; i < N; i++) {
        unordered_set<int> called;
        for (int v : need[i]) called.insert(v);

        int winners = 0;

        for (int j = 0; j < N; j++) {
            bool got = true;

            for (int v : need[j])
                got &= called.count(v);

            winners += int(got);
        }

        cout << (winners == 1 ? "YES" : "NO") << "\n";
    }
}