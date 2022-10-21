#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

ll p, q;
map<int, int> mp;

ll getp(ll x, ll k) {
    ll res = 1;
    while(k--) res *= x;
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while(T--) {
        cin >> p >> q;
        if(p % q != 0) {
            cout << p << '\n';
            continue;
        }
        mp.clear();
        ll mq = q;
        for(int i = 2; i * i <= mq; i++) {
            int cnt = 0;
            while(mq % i == 0) {
                mq /= i;
                cnt++;
            }
            if(cnt) {
                mp[i] = cnt;
            }
        }
        if(mq > 1) mp[mq] = 1;
        ll res = 0;
        for(auto e : mp) {
            ll cp = p;
            while(cp % e.first == 0) cp /= e.first;
            res = max(res, cp * getp(e.first, e.second - 1));
        }
        cout << res << '\n';
    }

}