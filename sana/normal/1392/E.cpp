#if 1
#ifdef LOCAL
#define _GLIBCXX_DEBUG 1
#define dbg(...) cerr << "LINE(" << __LINE__ << ") -> [" << #__VA_ARGS__ << "]: [", DBG(__VA_ARGS__)
#else
#define dbg(...) 0
#endif

#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define sz(x) (int)(x).size()
#define all(x) begin(x), end(x)
#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define F0R(i,a) FOR(i,0,a)

typedef string str;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

#define ts to_string
str ts(char c) { return str(1,c); }
str ts(bool b) { return b ? "true" : "false"; }
str ts(const char* s) { return (str)s; }
str ts(str s) { return s; }
template<class A> str ts(complex<A> c) { stringstream ss; ss << c; return ss.str(); }
str ts(vector<bool> v) { str res = "{"; F0R(i,sz(v)) res += char('0'+v[i]);	res += "}"; return res; }
template<size_t SZ> str ts(bitset<SZ> b) { str res = ""; F0R(i,SZ) res += char('0'+b[i]); return res; }
template<class A, class B> str ts(pair<A,B> p);
template<class T> str ts(T v) { bool fst = 1; str res = "{"; for (const auto& x: v) {if (!fst) res += ", ";	fst = 0; res += ts(x);}	res += "}"; return res;}
template<class A, class B> str ts(pair<A,B> p) {return "("+ts(p.f)+", "+ts(p.s)+")"; }
 
template<class A> void pr(A x) { cout << ts(x); }
template<class H, class... T> void pr(const H& h, const T&... t) { pr(h); pr(t...); }
void ps() { pr("\n"); }
template<class H, class... T> void ps(const H& h, const T&... t) { pr(h); if (sizeof...(t)) pr(" "); ps(t...); }
 
void DBG() { cerr << "]" << endl; }
template<class H, class... T> void DBG(H h, T... t) {cerr << ts(h); if (sizeof...(t)) cerr << ", ";	DBG(t...); }
#endif

ll C[52][52];

int main() {
    ios::sync_with_stdio(false);
    
    int n;
    cin >> n;

    vector< vector<ll> > a(n, vector<ll>(n));
    vector< vector<ll> > maxp(n+1, vector<ll>(n+1));
    
    vector< vector<ll> > minp(n+1, vector<ll>(n+1, 1000000000000000000LL));
    fill(all(minp[n-1]), 0);

    for (int i = n-2; i >= 0; i--) {
        for (int j = n-1; j >= 0; j--) {
            if (j > 0) a[i][j] = maxp[i+1][j-1] - min(minp[i+1][j], minp[i][j+1]) + 1;
            maxp[i][j] = a[i][j] + max(maxp[i+1][j], maxp[i][j+1]);
            minp[i][j] = a[i][j] + min(minp[i+1][j], minp[i][j+1]);
        }   
    }

    // cout << mp[0][0] << endl;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

    int q;
    cin >> q;

    for (; q; q--) {
        ll ans;
        cin >> ans;

        int curx = 0, cury = 0;
        cout << "1 1\n";

        for (int jj = 0; jj < 2*n-2; jj++) {
            ans -= a[curx][cury];
            if (curx == n-1 || ans > maxp[curx+1][cury]) {
                cury++;
            }
            else curx++;

            cout << curx+1 << " " << cury+1 << '\n';
        }

        cout.flush();
    }

    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j < n; j++) {
    //         cout << maxp[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    // cout << endl;

    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j < n; j++) {
    //         cout << minp[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    // cout << endl;

    return 0;
}