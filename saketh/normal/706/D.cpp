#include <bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(), (x).end()

#define TRACE(x) x
#define WATCH(x) TRACE(cout << #x" = " << x << endl)
#define WATCHR(a, b) TRACE(for (auto it=a; it!=b;) cout << *(it++) << " "; cout << endl)
#define WATCHC(V) TRACE({cout << #V" = "; WATCHR(V.begin(), V.end());})

typedef vector<unordered_map<int, int>> data;

vector<bool> read(int val) {
    vector<bool> res(31);
    for (int i = 0; i < 31; i++) {
        res[30 - i] = val&1;
        val >>= 1;
    }
    return res;
}

void update(data &avail, int val, int diff) {
    auto bits = read(val);
    int pref = 0;
    for (int i = 0; i < 31; i++) {
        pref = 2 * pref + bits[i];
        avail[i][pref] += diff;
    }
}

int solve(data &avail, int val) {
    auto bits = read(val);
    int res = 0;
    for (int i = 0; i < 31; i++) {
        int want = !bits[i];
        if (avail[i][2 * res + want])
            res = 2 * res + want;
        else
            res = 2 * res + !want;
    }
    return res ^ val;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cout << fixed << setprecision(15);

    data avail(31);
    update(avail, 0, 1);

    int Q;
    cin >> Q;

    for (int i = 0; i < Q; i++) {
        char op;
        int val;
        cin >> op >> val;

        if (op == '+') {
            update(avail, val, 1);
        } else if (op == '-') {
            update(avail, val, -1);
        } else {
            cout << solve(avail, val) << "\n";
        }
    }

    return 0;
}