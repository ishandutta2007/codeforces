#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
const int N = (int)1e6;

int n;
string str;

mt19937 rng(233);
int p[N];

void solve() {

    for(int i = 0; i < n; i++) {
        if(!p[str[i] - '0']) {
            cout << "1\n" << str[i] << '\n';
            return ;
        }
    }

    for(int i = 0; i < n; i++) {
        rep(j, i + 1, n) {
            int val = (str[i] - '0') * 10 + (str[j] - '0');
            if(!p[val]) {
                cout << "2\n" << val << '\n';
                return ;
            }
        }
    }
    for(int i = 0; i < n; i++) {
        rep(j, i + 1, n) {
            rep(k, j + 1, n) {
                int val = (str[i] - '0') * 100 + (str[j] - '0') * 10 + (str[k] - '0');
                if(!p[val]) {
                    cout << "3\n" << val << '\n';
                    return ;
                }
            }
        }
    }
    assert(false);
}

int main() {
//    ios::sync_with_stdio(false);
//    cin.tie(NULL);

    fill(p, p + N, 1);
    p[1] = 0;
    for (int i = 2; i < N; i++) {
        if(!p[i]) continue;
        for (int j = 2 * i; j <  N; j += i) p[j] = 0;
     }
    int T;
    cin >> T;
    while(T--) {
        cin >> n >> str;
        solve();
    }



}