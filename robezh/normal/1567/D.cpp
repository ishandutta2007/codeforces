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
const int INF = (int)1e9 + 5;

ll mx_pw10(ll x) {
    ll p = 1;
    while(x % (p * 10) == 0) p *= 10;
    return p;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while(T--) {
        int s, n;
        cin >> s >> n;
        multiset<int> S;
        int p = 1;
        while(s) {
            for (int j = 0; j < s % 10; j++) S.insert(p);
            s /= 10;
            p *= 10;
        }
        while(sz(S) > n) {
            int a = *S.begin(); S.erase(S.begin());
            int b = *S.begin(); S.erase(S.begin());
            S.insert(a + b);
        };
        while(sz(S) < n) {
            int mnpw = INF, mnsp = INF;
            for (int x : S) {
                ll mxp = mx_pw10(x);
                if(mxp == x) {
                    if(x > 1) mnpw = min(mnpw, x);
                }
                else mnsp = min(mnsp, x);
            }
            if(mnsp != INF) {
                S.erase(S.find(mnsp));
                ll mxp = mx_pw10(mnsp);
                S.insert(mxp);
                S.insert(mnsp - mxp);
            } else {
                assert(mnpw != INF);
                S.erase(S.find(mnpw));
                S.insert(mnpw / 10);
                S.insert(mnpw / 10 * 9);
            }
        }
        if(sz(S) == n) {
            for (int x : S) cout << x << " ";
            cout << '\n';
            continue;
        }

    }


}