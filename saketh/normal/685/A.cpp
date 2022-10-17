#include <bits/stdc++.h>
using namespace std;

#define TRACE(x) x
#define WATCH(x) TRACE(cout << #x" = " << x << endl)
#define WATCHR(a, b) TRACE(for (auto c=a; c!=b;) cout << *(c++) << " "; cout << endl)
#define WATCHC(V) TRACE(cout << #V" = "; WATCHR(V.begin(), V.end()))

typedef long long ll;

int len(int lim) {
    if (lim == 0) return 1;
    int res = 0;
    while (lim) {
        res++;
        lim /= 7;
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0), cout.precision(15);

    int N, M;
    cin >> N >> M;

    int f = len(N-1), b = len(M-1);

    if (f + b > 7) {
        cout << 0 << endl;
        return 0;
    }

    vector<int> digs(7);
    for (int i = 0; i < 7; i++)
        digs[i] = i;

    vector<pair<int, int>> pos;

    do {
        int hour = 0;
        for (int i = 0; i < f; i++) {
            hour = 7 * hour + digs[i];
        }

        int minut = 0;
        for (int i = 0; i < b; i++) {
            minut = 7 * minut + digs[f + i];
        }

        if (hour < N && minut < M)
            pos.emplace_back(hour, minut);
    } while (next_permutation(digs.begin(), digs.end()));

    sort(pos.begin(), pos.end());
    pos.erase(unique(pos.begin(), pos.end()), pos.end());
    cout << pos.size() << endl;

    return 0;
}