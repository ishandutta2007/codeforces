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

struct Data {
	ll t, w;
	int id, id_asli;
};

#define N 300005
int n;
Data arr[N];
int ans;
ll bit[N];
int cntbit[N];
int of[N];

void update(int pos, ll val) {
	//cerr << "UPD " << pos << " " << val << endl;
	++pos;
	for (; pos < N; pos += pos & -pos) {
		if (val > INFLL - bit[pos]) {
			of[pos] |= 1;
			bit[pos] = INFLL;
		} else {
			bit[pos] += val;
		}
		++cntbit[pos];
	}
}

tuple<ll, int, int> cek(int pos) {
	++pos;
	ll sum = 0LL;
	int cntsum = 0;
	int ofz = 0;
	for (; pos; pos -= pos & -pos) {
		if (of[pos] || sum > INFLL - bit[pos]) {
			ofz = 1;
		} else {
			sum += bit[pos];
			cntsum += cntbit[pos];
		}
	}
	return mt(sum, cntsum, ofz);
}

vll uniq;

int main(int argc, char** argv) {
	__INIT_CC__
	cin >> n;
	FOR (i, 0, n) {
		cin >> arr[i].t >> arr[i].w;
		arr[i].id_asli = i;
		uniq.pb(arr[i].t);
	}
	uniq.pb(0LL);
	VSORT(uniq);
	uniq.erase(unique(ALL(uniq)), uniq.end());
	reverse(ALL(uniq));
	sort(arr, arr + n, [](const Data& A, const Data& B) {
			return (A.w - A.t) < (B.w - B.t);
			});
	FOR (i, 0, n) {
		arr[i].id = i;
	}
	sort(arr, arr + n, [](const Data& A, const Data& B) {
			return A.t > B.t;
			});
	ll lst = INFLL;
	int renk = 0;
	int pos = 0;
	FOR (i, 0, n) {
		if (arr[i].t != lst) renk = i + 1;
		if (arr[i].id_asli == 0) {
			ans = renk;
			pos = i;
		}
		lst = arr[i].t;
	}
	
	//cerr << "ASU " << ans << endl;

	int lst_proc = 0;

	int ptr = 0;
	while (ptr < SIZE(uniq) && uniq[ptr] != arr[pos].t) ++ptr;

	ll ada = 0LL;
	int lewat = 0;

	while (ptr < SIZE(uniq)) {
		//cerr << "UNIQ " << uniq[ptr] << endl;
		while (lst_proc < n && arr[lst_proc].t > uniq[ptr]) {
			if (lst_proc != pos)
				update(arr[lst_proc].id, arr[lst_proc].w - arr[lst_proc].t + 1);
			else ++lewat;
			++lst_proc;
		}
		int lo = -1, hi = n + 1, mid;
		int ccnt = 0;
		while (lo < hi) {
			mid = (lo + hi + 1) >> 1;
			ll tmpval;
			int tmpof, tmpcnt;
			tie(tmpval, tmpcnt, tmpof) = cek(mid);
			//cerr << lo << " " << hi << " " << mid << " | " << tmpval << " " << tmpcnt << " " << tmpof << endl;
			if (tmpof || tmpval > ada) hi = --mid;
			else {
				lo = mid;
				ccnt = max(ccnt, tmpcnt);
			}
		}
		//cerr << uniq[ptr] << " " << lst_proc << " " << ccnt << endl;
		//cerr << lst_proc - ccnt + 1 - lewat << endl;
		ans = min(ans, lst_proc - ccnt + 1 - lewat);
		++ptr;
		if (ptr < SIZE(uniq)) ada += uniq[ptr - 1] - uniq[ptr];
	}

	cout << ans << "\n";
}