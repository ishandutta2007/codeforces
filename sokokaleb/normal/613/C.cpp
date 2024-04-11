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

#define N 30
int arr[N];
int n;

int main(int argc, const char *argv[])
{
	__INIT_CC__
	cin >> n;
	FOR (i,0,n) cin >> arr[i];
	int sum = 0;
	FOR (i,0,n) sum += arr[i];

	if (sum == 1)
	{
		cout << 0 << "\n";
		FOR (i,0,n) if (arr[i]) cout << char('a' + i);
		cout << "\n";
		return 0;
	}

	int ans = -1, lenans = 0;

	FORN (i,1,*min_element(arr, arr + n))
	{
		int oc = 0, ok = 0;
		FOR (j,0,n)
			if (arr[j] % i == 0)
			{
				++ok;
				if ((arr[j] / i)&1) ++oc;
			}

		if (ok == n && oc <= 1)
		{
			int tmp = i * (2 - oc);
			if (tmp > ans)
			{
				ans = tmp;
				lenans = sum / i;
			}
		}
	}

	if (ans == -1)
	{
		cout << "0\n";
		FOR (i,0,n)
			FOR (j,0,arr[i])
				cout << char('a' + i);
		cout << "\n";
		return 0;
	}

	string res = "";
	FOR (i,0,lenans)
		res += ' ';

	cout << ans << "\n";

	if (lenans&1)
	{
		char ocz = 0;
		FOR (i,0,n)
			if ((arr[i] / ans) & 1)
				ocz = 'a' + i;
		res[lenans / 2] = ocz;
		--arr[ocz - 'a'];
		int ptrl = 0, ptrr = lenans - 1;
		FOR (i,0,n)
		{
			int cnt = arr[i] / ans;
			cnt >>= 1;
			while (cnt > 0)
			{
				res[ptrl++] = 'a' + i;
				res[ptrr--] = 'a' + i;
				--cnt;
			}
		}

		FOR (i,0,ans) cout << res;
		cout << "\n";
	}
	else
	{
		ans >>= 1;
		int ptrl = 0, ptrr = lenans - 1;
		FOR (i,0,n)
		{
			int cnt = arr[i] / ans;
			cnt >>= 1;
			while (cnt > 0)
			{
				res[ptrl++] = 'a' + i;
				res[ptrr--] = 'a' + i;
				--cnt;
			}
		}
		FOR (i,0,ans) cout << res;
		cout << "\n";
	}
	return 0;
}