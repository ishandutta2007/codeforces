#if 1
#ifdef LOCAL
#define _GLIBCXX_DEBUG 1
#define dbg(...) cerr << "LINE(" << __LINE__ << ") -> [" << #__VA_ARGS__ << "]: [", DBG(__VA_ARGS__)
#else
#define dbg(...) 0
#endif

#include <bits/stdc++.h>
using namespace std;

#if 0
    #include <bits/extc++.h>
    using namespace __gnu_pbds;

    template<class T>
    using ordered_set = tree<T, null_type, less<T>, rb_tree_tag,
        tree_order_statistics_node_update>;
#endif

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define sz(x) (int)(x).size()
#define all(x) begin(x), end(x)
#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define F0R(i,a) FOR(i,0,a)

typedef string str;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

template<typename T, typename U> T &ctmax(T &x, const U &y){ return x = max<T>(x, y); }
template<typename T, typename U> T &ctmin(T &x, const U &y){ return x = min<T>(x, y); }

mt19937 rng((unsigned)chrono::steady_clock::now().time_since_epoch().count());

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
template<class A, class B> str ts(pair<A,B> p) {return "("+ts(p.first)+", "+ts(p.second)+")"; }
 
template<class A> void pr(A x) { cout << ts(x); }
template<class H, class... T> void pr(const H& h, const T&... t) { pr(h); pr(t...); }
void ps() { pr("\n"); }
template<class H, class... T> void ps(const H& h, const T&... t) { pr(h); if (sizeof...(t)) pr(" "); ps(t...); }
 
void DBG() { cerr << "]" << endl; }
template<class H, class... T> void DBG(H h, T... t) {cerr << ts(h); if (sizeof...(t)) cerr << ", ";	DBG(t...); }

int myrand(int l, int r) { return uniform_int_distribution(l, r)(rng); }

#endif

const int mod = 1000000007;
const int LIM = 1000000;

vector<int> junction[26];
int pot2[1100000];

vi pi(const string& s) {
	vi p(sz(s));
	rep(i,1,sz(s)) {
		int g = p[i-1];
		while (g && s[i] != s[g]) g = p[g-1];
		p[i] = g + (s[i] == s[g]);
	}
	return p;
}

int match(const string& s, const string& pat) {
    int cnt = 0;
	vi p = pi(pat + '\0' + s), res;
	rep(i,sz(p)-sz(s),sz(p))
		if (p[i] == sz(pat)) cnt++;
	return cnt;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    pot2[0] = 1;
    for (int i = 1; i <= 1000000; i++) pot2[i] = (pot2[i-1] + pot2[i-1]) % mod;
    
    int n, q;
    cin >> n >> q;

    vector<string> songs(n+1);
    string t;
    cin >> songs[0] >> t;

    for (int i = 1; i <= n; i++) {
        if (sz(songs[i-1]) >= LIM) break;
        songs[i] = songs[i-1] + t[i-1] + songs[i-1];
    }

    for (int i = 0; i < 26; i++) {
        junction[i] = vector<int>(n+1);

        for (int j = 1; j <= n; j++) {
            junction[i][j] = (junction[i][j-1] + junction[i][j-1]) % mod;
            if (t[j-1] == ('a' + i)) junction[i][j] = (junction[i][j] + 1) % mod;
        }
    }
    

    for (; q; --q) {
        int song_idx;
        string name;
        cin >> song_idx >> name;

        int special_song = 0;
        while (special_song < song_idx && sz(songs[special_song]) < sz(name)) special_song++;

        ll match_special = match(songs[special_song], name);
        match_special = (match_special * 1ll * pot2[song_idx - special_song]) % mod;

        if (special_song == song_idx) {
            cout << match_special << '\n';
            continue;
        }
        
        string ed = songs[special_song].substr(sz(songs[special_song]) - sz(name) + 1);
        string bg = songs[special_song].substr(0, sz(name) - 1);

        for (int i = 0; i < 26; i++) {
            int matches = match(ed + (char)('a'+i) + bg, name);
            
            ll coef = (junction[i][song_idx] - junction[i][special_song] * 1ll * (pot2[song_idx-special_song])) % mod;
            if (coef < 0) coef += mod;

            match_special = (match_special + matches * 1ll * coef) % mod;
            if (match_special < 0) match_special += mod;
        }

        cout << match_special << '\n';
    }

    return 0;
}