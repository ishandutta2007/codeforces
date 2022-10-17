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

mt19937 rng(int(chrono::steady_clock::now().time_since_epoch().count()));

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    const ll INF = 1ll << 32;

    int L;
    cin >> L;

    ll x = 0;
    stack<ll> loops({1});

    string type;
    for (int l = 0; l < L; l++) {
        cin >> type;
        if (type[0] == 'a') {
            x += loops.top();
            if (x >= INF) {
                cout << "OVERFLOW!!!\n";
                return 0;
            }
        } else if (type[0] == 'f') {
            int n;
            cin >> n;
            loops.push(min(INF, loops.top() * n));
        } else {
            loops.pop();
        }
    }

    cout << x << endl;

    return 0;
}