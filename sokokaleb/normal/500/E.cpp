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

#define N 200005
int n, p[N], leng[N], sampe[N], ccost[N], q, x, y;
int strmq[4 * N], rmqs[20][N];
int stcost[4 * N];

int query(int node, int l,int r,int a,int b)
{
	if (a <= l && r <= b) return strmq[node];
	int mid = (l + r) >> 1, A = node << 1, B = A | 1;
	int res = 0;
	if (mid >= a) res = max(res, query(A, l, mid, a, b));
	if (mid + 1 <= b) res = max(res, query(B, mid + 1, r, a, b));
	return res;
}

void update(int node,int l,int r,int a,int val)
{
	if (l == r && r == a)
	{
		strmq[node] = val;
		return ;
	}
	int mid = (l + r) >> 1, A = node << 1, B = A | 1;
	if (mid >= a) update(A,l,mid,a,val);
	if (mid + 1 <= a) update(B,mid+1,r,a,val);
	strmq[node] = max(strmq[A],strmq[B]);
	return ;
}

void init(int node,int l,int r)
{
	if (l == r)
	{
		strmq[node] = p[l] + leng[l];
		return ;
	}
	int mid = (l + r) >> 1, A = node << 1, B = A | 1;
	init(A,l,mid);
	init(B,mid+1,r);
	strmq[node] = max(strmq[A], strmq[B]);
	return ;
}

inline int queryfast(int l,int r)
{
	int pkt = 31 - __builtin_clz(r - l + 1);
	return max(rmqs[pkt][l],rmqs[pkt][r - (1 << pkt) + 1]);
}

int main(int argc, char const *argv[])
{
	__INIT_CC__;
	cin >> n;
	FOR (i,0,n)
		cin >> p[i] >> leng[i];
	init(1,0,n-1);
	rmqs[0][n-1] = n-1;
	FORD (i,n-2,0)
	{
		int pos = distance(p,upper_bound(p,p+n,p[i]+leng[i]));
		--pos;

		int res = p[i] + leng[i];
		if (i <= pos)
			res = query(1,0,n-1,i,pos);
		update(1,0,n-1,i,res);

		pos = distance(p,lower_bound(p,p+n,res));
		rmqs[0][i] = n - 1;
		if (pos < n)
		{
			ccost[i] = p[pos] - res;
			rmqs[0][i] = pos - 1;
		}
		// cerr << i << " = " << pos << "," << res << " == " << ccost[i] << endl;
	}
	FORD (i,n-2,0)
	{
		// ccost[i] += ccost[i+1];
		ccost[i] += ccost[rmqs[0][i]+1];
		// if (rmqs[0][i] != rmqs[0][i+1]) ccost[i] += ccost[i+1];
		// else ccost[i] = ccost[i+1];
	}

	// DUH
	for (int pkt = 1; (1 << pkt) <= n; ++pkt)
		for (int i = 0; i + (1 << pkt) - 1 < n; ++i)
			rmqs[pkt][i] = max(rmqs[pkt-1][i], rmqs[pkt-1][i + (1 << (pkt - 1))]);

	cin >> q;
	FOR (qq,0,q)
	{
		cin >> x >> y;
		--x;--y;
		if (rmqs[0][x] >= y) cout << "0\n";
		else
		{
			int lo = x, hi = y, mid;
			while (lo < hi)
			{
				mid = (lo + hi) >> 1;
				if (queryfast(x,mid) < y) lo = mid + 1;
				else hi = mid;
			}
			--lo;
			// cerr << x << " " << lo << endl;
			cout << ccost[x] - ccost[lo + 1] << "\n";
		}
	}
	return 0;
}