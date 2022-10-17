#include <bits/stdc++.h>
using namespace std;

#define TRACE(x) x
#define WATCH(x) TRACE(cout << #x" = " << x << endl)
#define WATCHR(a, b) TRACE(for (auto it=a; it!=b;) cout << *(it++) << " "; cout << endl)
#define WATCHC(V) TRACE({cout << #V" = "; WATCHR(V.begin(), V.end());})

#define all(x) (x).begin(), (x).end()

using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vll = vector<ll>;
using vvll = vector<vll>;
using vb = vector<bool>;
using vs = vector<string>;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N;
    cin >> N;

    stack<int> st;
    int melim = 0;

    for (int i = 0, v; i < N; i++) {
        cin >> v;
        if (!st.empty() && st.top() == v) {
            melim = max(melim, v);
            st.pop();
        } else {
            if (!st.empty() && v > st.top()) {
                cout << "NO\n";
                return 0;
            }
            st.push(v);
        }
    }

    set<int> v;
    for (; !st.empty(); st.pop()) {
        if (st.top() < melim) {
            cout << "NO\n";
            return 0;
        }
        v.insert(st.top());
    }
    cout << (v.size() <= 1 ? "YES" : "NO") << "\n";

    return 0;
}