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
        int N, d;
        cin >> N >> d;
        vector<int> a(N);
        rep(i, N) cin >> a[i];
        int ans = 0;
        rep(i, N) {
            rep(x, a[i]) {
                if (i <= d) {
                    d -= i;
                    ans++;
                }
            }
        }
        cout << ans << endl;
    }
}