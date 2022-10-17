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
    string str;

    vector<bool> signs;
    bool sign = true;

    while (cin >> str) {
        if (str == "=") break;

        if (str == "?") {
            signs.push_back(sign);
        }
        else sign = str == "+";
    }

    cin >> N;
    int T = signs.size();

    vector<int> lo(T + 1, N), hi(T + 1, N);

    for (int i = T - 1; i >= 0; i--) {
        if (signs[i]) {
            lo[i] = lo[i+1] - N;
            hi[i] = hi[i+1] - 1;
        } else {
            lo[i] = lo[i+1] + 1;
            hi[i] = hi[i+1] + N;
        }
    }

    if (hi[0] < 0 || lo[0] > 0) {
        cout << "Impossible\n";
        return 0;
    }

    cout << "Possible\n";

    int cur = 0;
    for (int i = 0; i < T; i++) {
        if (i > 0) cout << (signs[i] ? " + " : " - ");

        if (signs[i]) {
            int val = max(1, lo[i+1] - cur);
            cout << val;
            cur += val;
        } else {
            int val = max(1, cur - hi[i+1]);
            cout << val;
            cur -= val;
        }
    }

    cout << " = " << N << "\n";
    return 0;
}