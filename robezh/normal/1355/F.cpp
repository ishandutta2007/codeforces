#include <bits/stdc++.h>
using namespace std;

#define lson(x) 2*x+1
#define rson(x) 2*x+2

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef long double ld;

const int N = (int)850;

int p[N];

int getdivs(int x) {
    int i;
    int res = 0;
    for(i = 1; i * i < x; i++) {
        res += (x % i == 0);
    }
    return res * 2 + (i * i == x);
}

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll fres;

ll get(ll pd) {
    cout << "? " << pd << endl;
    fflush(stdout);
    ll rd; cin >> rd;
    return rd;
//    return __gcd(pd, fres);
}

int main() {
//    ios::sync_with_stdio(false);
//    cin.tie(NULL);

    fill(p, p + N, 1);
    for(int i = 2; i < N; i++) {
        if(p[i]) for(int j = i * 2; j < N; j += i) p[j] = 0;
    }
    int mx = 0;

    int T;
    cin >> T;
    while(T--) {
        ll pd = 1;
        int cnt = 0;
//        fres = 4194304;
//        cout << fres << endl;
        vector<ll> lcms;
        for(int i = 2; i < N; i++) {
            if(!p[i]) continue;
            ll cur = 1;
            while(cur * i <= 1024) cur *= i;
            if((ld)pd * cur > (ld)1e18 + 0.5) {
                lcms.push_back(get(pd));
                cnt++;
                pd = cur;
            }
            else {
                pd *= cur;
            }
            if(cnt == 22) {
                break;
            }
        }
        ll res = 1;
        for(int i = 2; i < N; i++) {
            if(!p[i]) continue;
            for(ll cm : lcms) {
                if(cm % i == 0) {
                    int c = 0;
                    while(cm % i == 0) c++, cm /= i;
                    res *= (c + 1);
                }
            }
        }
        cout << "! " << res * 2 << '\n';
//        cout << "real: " << getdivs(res) << endl;
        fflush(stdout);
    }
}