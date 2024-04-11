#include <bits/stdc++.h>
using namespace std;

#define TRACE(x) x
#define WATCH(x) TRACE(cout << #x" = " << x << endl)
#define WATCHR(a, b) TRACE(for (auto it=a; it!=b;) cout << *(it++) << " "; cout << endl)
#define WATCHC(V) TRACE({cout << #V" = "; WATCHR(V.begin(), V.end());})

#define all(x) (x).begin(), (x).end()

typedef long long ll;
typedef vector<bool> vb;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef vector<vll> vvll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cout << fixed << setprecision(15);

    const int MOD = 1e9 + 7;

    set<int> buy, unk, sell;
    buy.insert(0);
    sell.insert(int(1e9));

    int N, v, ans = 1;
    string op;

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> op >> v;
        if (op == "ADD") {
            if (v < *buy.rbegin())
                buy.insert(v);
            else if (v > *sell.begin())
                sell.insert(v);
            else unk.insert(v);
        } else {
            if (unk.count(v)) {
                ans = ans * 2ll % MOD;
                for (int e : unk) {
                    if (e < v) buy.insert(e);
                    else if (e > v) sell.insert(e);
                }
                unk.clear();
            } else if (v == *buy.rbegin()) {
                buy.erase(v);
                for (int e : unk)
                    sell.insert(e);
                unk.clear();
            } else if (v == *sell.begin()) {
                sell.erase(v);
                for (int e : unk)
                    buy.insert(e);
                unk.clear();
            } else {
                cout << 0 << endl;
                return 0;
            }
        }
    }

    ans = ans * 1ll * (unk.size() + 1) % MOD;
    cout << ans << endl;
    return 0;
}