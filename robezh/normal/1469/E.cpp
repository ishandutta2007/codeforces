#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
const int N = (int)1e6 + 50;
int n, k;
string str;
int psum[N];
int vis[2 * N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while(T--) {
        cin >> n >> k;
        cin >> str;
        str = " " + str;
        rep(i, 1, n + 1) psum[i] = psum[i - 1] + (str[i] == '1');
        int rk = 0, pw = 1;
        while(rk < k && pw <= n - k + 1) pw *= 2, rk++;
        int lk = k - rk;
        fill(vis, vis + pw, false);
        for(int i = 1; i + k - 1 <= n; i++) {
            if(psum[i + lk - 1] - psum[i - 1] == lk) {
                int cur = 0;
                for(int j = i + lk; j < i + k; j++) cur *= 2, cur += (str[j] == '0');
//                cout << "adding " << cur << endl;
                vis[cur] = 1;
            }
        }
        int best = -1;

        for(int i = pw - 1; i >= 0; i--) if(!vis[i]) best = i;
        if(best == -1) {
            cout << "NO\n";
            continue;
        }
        cout << "YES\n";
        vi obest(rk, 0);
        rep(i, 0, rk) obest[i] = best % 2, best /= 2;
        reverse(all(obest));
        rep(i, 0, lk) cout << 0;
        rep(i, 0, rk) cout << obest[i];
        cout << '\n';
    }


}