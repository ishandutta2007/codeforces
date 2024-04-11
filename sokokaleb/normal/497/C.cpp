#include <bits/stdc++.h>

#ifdef PEYEK 
	#define debugln {printf("----OK----\n");}
	#define debug(...) {printf(__VA_ARGS__);}
	#define debugs(...) {printf(":::::--->> ");printf(__VA_ARGS__);}
	#define TIME() printf("%.3lf\n",clock()/(double)CLOCKS_PER_SEC)
#else
	#define debugln {}
	#define debug(...) {}
	#define debugs(...) {}
	#define TIME() {}
#endif

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
 
using namespace std;
 
const int dr[]={ 1, 0,-1, 0, 1, 1,-1,-1};
const int dc[]={ 0, 1, 0,-1, 1,-1,-1, 1};
const double eps=1e-9;
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
const int INF=0x7FFFFFFF;
const ll INFLL=0x7FFFFFFFFFFFFFFFLL;
const double pi=acos(-1);

template <class T> T take(queue<T> &O) {T tmp=O.front();O.pop();return tmp;}
template <class T> T take(stack<T> &O) {T tmp=O.top();O.pop();return tmp;}
template <class T> T take(priority_queue<T> &O) {T tmp=O.top();O.pop();return tmp;}
template <class T> inline void getint(T &num)
{
	bool neg=0;
	num=0;
	char c;
	while ((c=getchar_unlocked()) && (!isdigit(c) && c!='-'));
	if (c=='-')
	{
		neg=1;
		c=getchar_unlocked();
	}
	do num=num*10+c-'0';
	while ((c=getchar_unlocked()) && isdigit(c));
	num*=(neg)?-1:1;
}

template <class T> inline bool inRange(T z, T a, T b){return a <= z && z <= b;}

void OPEN(string in="input.txt",string out="output.txt")
{
	freopen(in.c_str(),"r",stdin);
	freopen(out.c_str(),"w",stdout);
	return ;
}

//using sokokaleb's template v3.0

typedef pair<int,ii> i3;
typedef vector<i3> vi3;
#define mp3(_a,_b,_c) mp(_a,mp(_b,_c))

#define N 200005
set<i3> SET;
int ksisa[N],aa[N],bb[N];
vii ve;
vi3 vq;
bitset<N> active;
int n,m;
int ans[N];

int main(int argc, char const *argv[])
{
	__INIT_CC__;
	ve.clear();vq.clear();
	cin >> m;
	FOR (i,0,m)
	{
		int a,b;
		cin >> a >> b;
		vq.pb(mp3(a,b,i));
	}
	cin >> n;
	FORN (i,1,n)
	{
		int a,b;
		cin >> a >> b;
		cin >> ksisa[i];
		ve.pb(mp(a,i));
		ve.pb(mp(b+1,i));
		// cerr << a << " " << b + 1 << endl;
		aa[i] = a;
		bb[i] = b;
	}
	VSORT(ve);
	VSORT(vq);

	int ptre = 0;
	active.reset();
	FOR (i,0,SIZE(vq))
	{
		auto &nowq = vq[i];
		// cerr << ve[ptre].ff << " " << nowq.ff << endl;
		while (ptre < SIZE(ve) && ve[ptre].ff <= nowq.ff)
		{
			auto &nowe = ve[ptre];
			if (!active.test(nowe.ss)) // masuk
			{
				SET.insert(mp3(bb[nowe.ss], ksisa[nowe.ss], nowe.ss));
				active.set(nowe.ss,1);
			}
			else
			{
				active.set(nowe.ss,0);
				auto x = SET.find(mp3(bb[nowe.ss], ksisa[nowe.ss], nowe.ss));
				if (x != SET.end())
					SET.erase(x);
			}
			// cerr << ptre << endl;
			++ptre;
		}
		// cerr << "ESE " << ptre << endl;
		// cerr << ve[ptre].ff << " " << nowq.ff << "\n";
		auto x = SET.lower_bound(mp3(nowq.ss.ff, -INF, -INF));
		if (x != SET.end())
		{
			auto z = (*x);
			// cerr << nowq.ff << " " << nowq.ss.ff << " " << nowq.ss.ss << "\n";
			// cerr << z.ff << " " << z.ss.ff << " " << z.ss.ss << "\n";
			// cerr << "ASU\n";
			SET.erase(x);
			z.ss.ff -= 1;
			--ksisa[z.ss.ss];
			if (z.ss.ff > 0) SET.insert(z);
			ans[nowq.ss.ss] = z.ss.ss;
		}
		else
		{
			cout << "NO\n";
			exit(0);
		}
	}

	cout << "YES\n";
	FOR (i,0,m) cout << ans[i] << (i == m - 1 ? "\n" : " ");

	return 0;
}