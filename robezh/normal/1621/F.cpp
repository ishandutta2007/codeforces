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
typedef vector<int> vi;

const int N = (int)1e5 + 50;

int n;
ll a, b, c;
string str;

ll solve(int turn) {
    vector<pii> vs;
    rep(i, 0, n) {
        if(vs.empty() || vs.back().second != int(str[i] - '0')) {
            vs.push_back({1, int(str[i] - '0')});
        } else vs.back().first++;
    }

    vi g0;
    int u0 = 0, su0 = 0;
    int s1 = 0;
//    cout << endl;
    rep(i, 0, sz(vs)) {
//        cout << "(" << vs[i].first << ", " << vs[i].second << "), ";
        if(vs[i].second == 0 && (i == 0 || i == sz(vs) - 1)) {
            u0++;
            su0 += vs[i].first - 1;
        }
        else if(vs[i].second == 1) s1 += vs[i].first - 1;
        else g0.push_back(vs[i].first);
    }
//    cout << endl;
    sort(all(g0), greater<>());

    // 2 first
    ll res = 0;
    bool fir = true;
    while(true) {
        if(fir) {
            if(turn) {
                if(s1 == 0) break;
                res += b;
                s1--;
            }
            fir = false;
        } else {
            if(s1 == 0) break;
            res += b;
            s1--;
        }

        while(!g0.empty() && g0.back() == 1) {
            g0.pop_back();
            res += b - c;
        }
        if(!g0.empty()) {
            g0.back()--;
            res += a;
        } else if(su0){
            res += a;
            su0--;
        } else if(u0 && s1){
            res -= c;
            u0--;
        } else {
            break;
        }
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while(T--) {
        cin >> n >> a >> b >> c;
        cin >> str;
        if(c > b) {
            int c0 = 0, c1 = 0;
            rep(i, 0, n - 1) {
                if(str[i] == '0' && str[i + 1] == '0') c0++;
                if(str[i] == '1' && str[i + 1] == '1') c1++;
            }
            if(c0 > c1) cout << (c1 + 1) * a + c1 * b << '\n';
            else if(c0 == c1) cout << c0 * a + c1 * b << "\n";
            else cout << c0 * a + (c0 + 1) * b << '\n';
        } else {
            ll r0 = solve(0);
            ll r1 = solve(1);
            cout << max(r0, r1) << '\n';
        }
    }


}