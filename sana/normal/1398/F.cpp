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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n; string s; 
    cin >> n >> s;

    vi one(n+1), zero(n+1), D(n+1);
    vector<vi> activate(n+1);
    for (int i = n-1; i >= 0; i--) {
        if (s[i] != '0') one[i] = one[i+1]+1;
        if (s[i] != '1') zero[i] = zero[i+1]+1;
        D[i] = max(one[i], zero[i]);
    }

    vi newD;
    for (int i = 0; i < n; i++) {
        if (i == 0 || D[i] >= D[i-1]) {
            activate[D[i]].push_back(i);
            newD.push_back(i);
        }
    }

    vi prv(n+1), nxt(n+1);
    prv[newD.front()] = -1; nxt[newD.back()] = n;

    for (int i = 1; i < sz(newD); i++) {
        int x = newD[i];
        prv[x] = newD[i-1];
        while (prv[x] != -1 && D[prv[x]] < D[x]) prv[x] = prv[prv[x]];
    }    
    for (int i = sz(newD)-2; i >= 0; i--) {
        int x = newD[i];
        nxt[x] = newD[i+1];
        while (nxt[x] != n && D[nxt[x]] < D[x]) nxt[x] = nxt[nxt[x]];
    }

    vi ans;
    int first = n;
    for (int x = n; x >= 1; x--) {
        for (int k : activate[x]) {
            if (prv[k] != -1) nxt[prv[k]] = k;
            if (nxt[k] != n) prv[nxt[k]] = k;
            first = min(first, k);
        }

        int curr = first;
        int fr = curr;
        int t = curr;
        int curans = 0;
        while (curr < n) {
            int blocks = (D[curr] - (fr-curr)) / x;

            fr += x * blocks;
            curans += blocks;
            while (t < n && (D[t] - (fr-t)) / x <= 0) t = nxt[t];
            curr = t;

            fr = max(fr, t);
        }

        ans.push_back(curans);
    }

    reverse(all(ans));
    for (int x : ans) cout << x << " ";
    cout << endl;
}