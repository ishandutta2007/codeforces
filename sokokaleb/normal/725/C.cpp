#include <bits/stdc++.h>

#define __INIT_CC__ ios::sync_with_stdio(false); \
	cin.tie(0);

#ifdef __WIN32__
	char getchar_unlocked() {return getchar();}
#endif

#define FOR(_i,_n,_m) for(int (_i)=(_n),_t=(_m);_i<(_t);++(_i))
#define FORN(_i,_n,_m) for(int (_i)=(_n),_t=(_m);_i<=(_t);++(_i))
#define FORD(_i,_n,_m) for(int (_i)=(_n),_t=(_m);_i>=(_t);--(_i))
#define FORLL(_i,_n,_m) for(long long (_i)=(_n),_t=(_m);_i<(_t);++(_i))
#define FORNLL(_i,_n,_m) for(long long (_i)=(_n),_t=(_m);(_i)<=(_t);++(_i))
#define FORDLL(_i,_n,_m) for(long long (_i)=(_n),_t=(_m);(_i)>=(_t);--(_i))
#define FOREACH(_i,_a) for (__typeof(_a.begin()) _i=_a.begin();_i!=_a.end();++_i)
#define RESET(_a,_value) memset(_a,_value,sizeof(_a))
#define pb push_back
#define ppb pop_back
#define pf push_front
#define ppf pop_front
#define ff first
#define ss second
#define mp make_pair
#define SIZE(_a) (int)_a.size()
#define VSORT(_a) sort(_a.begin(),_a.end())
#define SSORT(_a,_val) sort(_a,_a+(_val))
#define ALL(_a) _a.begin(),_a.end()
#define mt make_tuple
#define _get(_tuple,_i) get<_i>(_tuple)
#define eb emplace_back
 
using namespace std;
 
const int dr[] = { 1, 0,-1, 0, 1, 1,-1,-1};
const int dc[] = { 0, 1, 0,-1, 1,-1,-1, 1};
const double eps = 1e-9;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll,ll> pll;
typedef vector<pll> vpll;
typedef vector<ll> vll;
typedef pair<double,double> pdd;
typedef vector<pdd> vpdd;
const int INF = 0x7FFFFFFF;
const ll INFLL = 0x7FFFFFFFFFFFFFFFLL;
const double pi = acos(-1);

template <class T> T take(queue<T> &O) {T tmp=O.front();O.pop();return tmp;}
template <class T> T take(stack<T> &O) {T tmp=O.top();O.pop();return tmp;}
template <class T> T take(priority_queue<T> &O) {T tmp=O.top();O.pop();return tmp;}
template <class T> inline void getint(T &num)
{
	bool neg = 0;
	num = 0;
	char c;
	while ((c = getchar_unlocked()) && (!isdigit(c) && c != '-'));
	if (c == '-')
	{
		neg = 1;
		c = getchar_unlocked();
	}
	do num = num * 10 + c - '0';
	while ((c = getchar_unlocked()) && isdigit(c));
	if (neg) num = -num;
}

template <class T> inline bool inRange(T z, T a, T b){return a <= z && z <= b;}

void OPEN(string in = "input.txt",string out = "output.txt")
{
	freopen(in.c_str(), "r", stdin);
	freopen(out.c_str(), "w", stdout);
	return ;
}

//using sokokaleb's template v3.1

string s;
int inbetween;
char duakali;
int kiri, kanan;

tuple<char, int, int, int> cari(const string& s) {
	FOR (i, 0, SIZE(s))
		FOR (j, i + 1, SIZE(s))
			if (s[i] == s[j]) {
				return mt(s[i], j - i - 1, i, j);
			}
}

string ans[2] = {".............", "............."};

int main(int argc, char** argv) {
	__INIT_CC__
	cin >> s;
	tie(duakali, inbetween, kiri, kanan) = cari(s);
	if (kiri == kanan - 1) {
		cout << "Impossible\n";
		return 0;
	}
	if (inbetween & 1) {
		int tengah = kiri + inbetween / 2 + 1;
		ans[0][0] = s[tengah];
		int ptrx = 1, ptry = 0;
		FORD (i, tengah - 1, kiri + 1) ans[0][ptrx++] = s[i];
		FOR (i, tengah + 1, kanan) ans[1][ptry++] = s[i];
		ans[1][ptry++] = s[kiri];
		queue<ii> Q;
		FOR (i, ptry, 13) {
			Q.push(mp(0, i));
			Q.push(mp(1, i));
		}
		ptrx = kiri - 1, ptry = kanan + 1;
		while (ptrx >= 0 || ptry < 27) {
			if (ptrx >= 0) {
				auto pos = take(Q);
				ans[pos.ff][pos.ss] = s[ptrx--];
			}
			if (ptry < 27) {
				auto pos = take(Q);
				ans[pos.ff][pos.ss] = s[ptry++];
			}
		}
	} else {
		int tengah = kiri + inbetween / 2;
		int ptrx = 0, ptry = 0;
		FORD (i, tengah, kiri + 1) ans[0][ptrx++] = s[i];
		FOR (i, tengah + 1, kanan) ans[1][ptry++] = s[i];
		ans[0][ptrx++] = s[kiri];
		queue<ii> Q;
		Q.push(mp(1, ptry++));
		FOR (i, ptry, 13) {
			Q.push(mp(0, i));
			Q.push(mp(1, i));
		}
		ptrx = kiri - 1, ptry = kanan + 1;
		while (ptrx >= 0 || ptry < 27) {
			if (ptrx >= 0) {
				auto pos = take(Q);
				ans[pos.ff][pos.ss] = s[ptrx--];
			}
			if (ptry < 27) {
				auto pos = take(Q);
				ans[pos.ff][pos.ss] = s[ptry++];
			}
		}
	}

	cout << ans[0] << "\n" << ans[1] << "\n";
}