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
int cnt[N][2], cntong[2], cum[N][2];
int n, arr[N];
vii vans;

int main(int argc, char const *argv[])
{
	__INIT_CC__;
	vans.clear();
	cin >> n;
	RESET(cnt,-1);
	cnt[0][0] = cnt[0][1] = 0;
	FORN (i,1,n)
	{
		cin >> arr[i];
		int a = arr[i] - 1;
		int b = 1 - a;

		++cntong[a];
		cnt[cntong[a]][a] = i;
		cum[i][0] = cntong[0];
		cum[i][1] = cntong[1];
	}

	FORN (post,1,n)
	{
		int ptr;
		int score[2];
		score[0] = score[1] = 0;
		ptr = 0;
		int lastsiapa = -1;
		bool ok = 1;
		while (ptr != n)
		{
			int cnex[2];
			cnex[0] = cnt[cum[ptr][0] + post][0];
			cnex[1] = cnt[cum[ptr][1] + post][1];
			int siapa = -1;
			if (cnex[0] != -1)
			{
				if (cnex[1] == -1) siapa = 0;
				else siapa = (cnex[0] < cnex[1] ? 0 : 1);
			}
			else if (cnex[1] != -1) siapa = 1;
			if (siapa == -1)
			{
				ok = 0;
				break;
			}
			else
			{
				++score[siapa];
				ptr = cnex[siapa];
				lastsiapa = siapa;
			}
		}
		ok &= (score[0] != score[1] && score[lastsiapa] > score[1 - lastsiapa]);
		if (ok) vans.pb(mp(max(score[0],score[1]), post));
	}
	VSORT(vans);
	cout << SIZE(vans) << "\n";
	for (auto i : vans) cout << i.ff << " " << i.ss << "\n";
	return 0;
}