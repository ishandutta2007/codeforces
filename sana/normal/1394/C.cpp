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

pair<int, int> check(const vector<pair<int,int>>& els, int dist) {
    int maxx = 1000000000, maxy = 1000000000;
    int minx = 0, miny = 0;
    int mindif = -1100000000, maxdif = 1100000000;

    for (pii p : els) {
        minx = max(minx, p.first - dist);
        miny = max(miny, p.second - dist);
        maxx = min(maxx, p.first + dist);
        maxy = min(maxy, p.second + dist);
        mindif = max(mindif, p.first-p.second - dist);
        maxdif = min(maxdif, p.first-p.second + dist);
    }

    if (maxx < minx || maxy < miny || maxdif < mindif) return {-1,-1};

    pii cand = {minx, miny};
    if (cand.first - cand.second < mindif) {
        cand.first += mindif - (cand.first - cand.second);
        if (cand.first > maxx) return {-1,-1};
    }
    else if (cand.first - cand.second > maxdif) {
        cand.second +=  (cand.first - cand.second) - maxdif;
        if (cand.second > maxy) return {-1, -1};
    }

    if (cand == pii{0,0}) {
        if (maxx >= 1 && maxy >= 1) return {1,1};
        else if (maxx >= 1 && maxdif >= 1) return {1, 0};
        else if (maxy >= 1 && mindif <= -1) return {0, 1};
        return {-1,-1};
    }
    return cand;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;

    vector< pair<int,int> > els;
    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        int cB = 0, cN = 0;
        for (char c : s) {
            if (c == 'B') cB++;
            else cN++;
        }

        els.push_back({cB,cN});
    }

    int st = 0, ed = 1000000000;
    while (st < ed) {
        int md = st + (ed-st)/2;
        if (check(els, md).first != -1) ed = md;
        else st = md+1;
    }

    pair<int, int> ans = check(els, st);
    
    cout << st << endl;
    for (int i = 0; i < ans.first; i++) cout << 'B';
    for (int i = 0; i < ans.second; i++) cout << 'N';
    cout << endl;

    return 0;
}