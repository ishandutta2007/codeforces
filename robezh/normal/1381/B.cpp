#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const int N = 4005;

int n;
int a[N];
int dp[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while(T--) {
        cin >> n;
        rep(i, 0, 2 * n) cin >> a[i];
        int r = 2 * n;
        memset(dp, 0, sizeof(dp));
        dp[0] = 1;
        while(r > 0) {
            int mxi = -1;
            for(int i = 0; i < r; i++) {
                if(mxi == -1 || a[mxi] < a[i]) mxi = i;

            }
            int len = r - mxi;
//            cout << len << '\n';
            for(int j = N; j - len >= 0; j--) {
                dp[j] |= dp[j - len];
            }
            r = mxi;
        }
        cout << (dp[n] ? "YES" : "NO") << "\n";
    }

}