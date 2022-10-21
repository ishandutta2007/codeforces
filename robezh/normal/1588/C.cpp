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

const int N = (int)3e5 + 50;

int n, a[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while(T--) {
        cin >> n;
        rep(i, 0, n) cin >> a[i];
        map<ll, int> S;
        ll s = 1, off = 0;
        ll res = 0;
        rep(i, 0, n) {
            S[-off * s]++;
            auto it = S.find((a[i] - off) * s);
            if(it != S.end()) res += it -> second;

//            cout << "before";
//            cout << i << ": " << endl;
//            for (auto &p : S) cout << p.first * s + off << ": " << p.second << endl;

            if(s == 1) {
                while(!S.empty()) {
                    auto it = S.end(); it--;
                    if(it -> first + off > a[i]) S.erase(it);
                    else break;
                }
            } else {
                while(!S.empty()) {
                    auto it = S.begin();
                    if(-it -> first + off > a[i]) S.erase(it);
                    else break;
                }
            }
            s = -s;
            off = a[i] - off;
//            cout << i << ": " << endl;
//            for (auto &p : S) cout << p.first * s + off << ": " << p.second << endl;
        }
        cout << res << '\n';
    }
}