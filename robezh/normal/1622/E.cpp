#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define subnb true
#define Lnb true
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<ll, int> pli;
typedef vector<int> vi;

const int N = 12, M = 10005;

int n, m;
int x[N];
string str[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while(T--) {
        cin >> n >> m;
        rep(i, 0, n) cin >> x[i];
        rep(i, 0, n) cin >> str[i];

        int mres = -1;
        vi ps(m, 0);
        rep(mask, 0, 1 << n) {
            int csum = 0;
            rep(i, 0, n) {
                if(mask >> i & 1) csum -= x[i];
                else csum += x[i];
            }
            vi cnt(21, 0);
            rep(j, 0, m) {
                int c = 0;
                rep(i, 0, n) {
                    if(mask >> i & 1) c += str[i][j] == '1';
                    else c -= str[i][j] == '1';
                }
                cnt[10 + c]++;
            }
            int pf = 0, cur = 1;
            rep(j, 0, 21) {
                int l = cur, r = cur + cnt[j] - 1;
                cur += cnt[j];
                pf += (r + l) * cnt[j] * (j - 10) / 2;
            }
            if(csum + pf > mres) {
                vi loc(21, 0);
                rep(i, 1, 21) loc[i] = loc[i - 1] + cnt[i - 1];
                rep(j, 0, m) {
                    int c = 0;
                    rep(i, 0, n) {
                        if(mask >> i & 1) c += str[i][j] == '1';
                        else c -= str[i][j] == '1';
                    }
                    ps[j] = loc[10 + c]++;
                }
                mres = csum + pf;
            }
        }
        rep(i, 0, m) cout << ps[i] + 1 << " ";
        cout << '\n';
    }
}