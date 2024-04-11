#include <bits/stdc++.h>
using namespace std;

#define TRACE(x) x
#define WATCH(x) TRACE(cout << #x" = " << x << endl)
#define WATCHR(a, b) TRACE(for (auto c=a; c!=b;) cout << *(c++) << " "; cout << endl)
#define WATCHC(V) TRACE(cout << #V" = "; WATCHR(V.begin(), V.end()))

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0), cout.precision(15);

    int N;
    cin >> N;

    vector<int> vals(N);
    for (int i = 0; i < N; i++)
        cin >> vals[i];

    bool go = true;
    while (go) {
        go = false;

        for (int i = 0; i + 1 < N; i++) {
            if (vals[i] > vals[i+1]) {
                go = true;
                swap(vals[i], vals[i+1]);
                cout << i + 1 << " " << i + 2 << "\n";
                break;
            }
        }
    }

    return 0;
}