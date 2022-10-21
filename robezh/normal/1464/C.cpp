#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int n;
ll T;
string str;
ll pw[62];
int cnt[62];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> T;
    cin >> str;
    pw[0] = 1;
    rep(i, 1, 62) pw[i] = pw[i - 1] * 2;

    rep(i, 0, n - 2) cnt[str[i] - 'a' + 1]++;
    T -= -pw[str[n - 2] - 'a'] + pw[str[n - 1] - 'a'];
    rep(i, 0, n - 2) {
        T += pw[str[i] - 'a'];
    }
//    cout << T << endl;
    for(int b = 62; b >= 0; b--) {
        if(!(T >> b & 1)) continue;
        ll cur = 0;
        for(int b2 = b; b2 >= 0; b2--) {
            while(cnt[b2] && cur < (1LL << b)) {
                cur += (1LL << b2);
                cnt[b2]--;
            }
            if(cur == (1LL << b)) break;
        }
        if(cur != (1LL << b)) return cout << "No\n" << endl, 0;
    }
//    for(int b = 62; b >= 0; b--) if(cnt[b]) return cout << "No\n" << endl, 0;;
    cout << "Yes\n";






}