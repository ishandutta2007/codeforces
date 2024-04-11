#include <bits/stdc++.h>
using namespace std;

#define rep(i, N) for (int i = 0; i < (N); i++)
#define all(a) (a).begin(), (a).end()
#define pb push_back

using ll = long long;
using i_i = tuple<int, int>;

int main() {
    int T; cin >> T;
    while (T--) {
        int N, A, B;
        cin >> N >> A >> B;
        bool ok = false;
        rep(a, A) {
            int x; cin >> x;
            if (x == N) ok = true;
        }
        rep(b, B) {
            int x; cin >> x;
        }
        cout << (ok ? "YES" : "NO") << endl;
    }
}