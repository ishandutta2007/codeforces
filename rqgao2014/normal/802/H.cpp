#include<bits/stdc++.h>

#define HEAP priority_queue
#define rep(i, n) for(int i = 0, _end_ = (n); i < _end_; ++i)
#define per(i, n) for(int i = (n) - 1; i >= 0 ; --i)
#define forn(i, l, r) for(int i = (l), _end_ = (r); i <= _end_; ++i)
#define nrof(i, r, l) for(int i = (r), _end_ = (l); i >= _end_; --i)
#define FOR(a, b) for(auto (a): (b))
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define X first
#define Y second
#define eps 1e-6
#define pi 3.1415926535897932384626433832795
#define SZ(x) (int)x.size()
#define ALL(x) x.begin(), x.end()
#define FILL(a, b) memset((a), (b), sizeof((a)))
#define MCPY(a, b) memcpy((a), (b), sizeof((b)))

using namespace std;

typedef long long LL;
typedef double flt;
typedef vector<int> vi;
typedef vector<LL> vl;
typedef pair<int,int> pii;
typedef pair<int,LL> pil;
typedef pair<LL,int> pli;
typedef pair<LL,LL> pll;
typedef vector<pil> vil;
typedef vector<pii> vii;
typedef vector<pli> vli;
typedef vector<pll> vll;

const int iinf = 1e9 + 7;
const int oo = 0x3f3f3f3f;
const LL linf = 1ll << 60;
const flt dinf = 1e60;

template <typename T>
inline void scf(T &x)
{
	bool f = 0; x = 0; char c = getchar();
	while((c < '0' || c > '9') && c != '-') c = getchar();
	if(c == '-') { f = 1; c = getchar(); }
	while(c >= '0' && c <= '9') { x = x * 10 + c - '0'; c = getchar(); }
	if(f) x = -x; return;
}
template <typename T1, typename T2>
void scf(T1 &x, T2 &y) { scf(x); return scf(y); }
template <typename T1, typename T2, typename T3>
void scf(T1 &x, T2 &y, T3 &z) { scf(x); scf(y); return scf(z); }
template <typename T1, typename T2, typename T3, typename T4>
void scf(T1 &x, T2 &y, T3 &z, T4 &w) { scf(x); scf(y); scf(z); return scf(w); }

inline char mygetchar(){ char c = getchar(); while(c == ' ' || c == '\n') c = getchar(); return c; }

template <typename T> inline bool chkmax(T &x, const T &y){ return y > x ? x = y, 1 : 0; }
template <typename T> inline bool chkmin(T &x, const T &y){ return y < x ? x = y, 1 : 0; }

#ifdef ONLINE_JUDGE
#define debug(...) ;
#else
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define DEBUG
#endif

//---------------------------------------------------------head----------------------------------------------------

int n;
int a[22], b[22];
string s, t;

void push(int m)
{
	if(n > 14 && m == n - 1)
	{
		s += (char)('a' + n - 1);
		s += (char)('a' + n - 1);
		return;
	}
	if(n > 14 && m == n)
	{
		s += (char)('a' + n - 1);
		s += (char)('a' + n - 1);
		s += (char)('a' + n - 1);
		s += (char)('a' + n - 1);
		return;
	}
	forn(i, n - 1 - m + 1, n - 1) s += (char)('a' + i);
	return;
}

int main()
{
	scf(n);
	rep(i, 22) a[i] = (n >> i) & 1;
	s = t = "";
	n = 21;
	while(!a[n]) --n;
	forn(i, 0, n) t += (char)('a' + i);
	s = t.substr(0, n);
	if(a[0]) s += (char)('a' + n);
	per(m, n)
	{
		push(n - m);
		if(a[n - m]) s += (char)('a' + n);
	}
	cerr<<SZ(s)<<endl;
	cout<<s<<' '<<t<<endl;
	return 0;
}