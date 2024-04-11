#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;
const int N = 105;

int n, m;
int rs[N][N];
multiset<int> S[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while(T--) {
        cin >> n >> m;
        rep(i, 0, n) {
            S[i].clear();
            rep(j, 0, m) {
                int b;
                cin >> b;
                S[i].insert(b);
            }
        }
        ll res = 0;
        rep(iter, 0, m) {
            int mni = -1;
            rep(i, 0, n) {
                if(mni == -1 || *S[i].begin() < *S[mni].begin()) mni = i;
            }
            res += *S[mni].begin();
            rep(i, 0, n) {
                if(mni == i) {
                    rs[i][iter] = *S[i].begin();
                    S[i].erase(S[i].begin());
                }
                else {
                    auto it = S[i].end(); it--;
                    rs[i][iter] = *it;
                    S[i].erase(it);
                }
            }
        }
//        cout << res << '\n';
        rep(i, 0, n) {
            rep(j, 0, m) cout << rs[i][j] << " ";
            cout << '\n';
        }
    }


}