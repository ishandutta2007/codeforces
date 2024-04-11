#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <bitset>
#include <queue>
#include <deque>
#include <stack>
#include <complex>
#include <cassert>

using namespace std;

#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define sz(s) int((s).size())
#define len(s) int((s).size())
#ifdef LOCAL
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#define LLD "%lld"
#else
#define eprintf(...) 42
#define LLD "%I64d"
#endif
#define next _next
#define prev _prev
#define rank _rank
#define link _link
#define hash _hash

typedef long long ll;
typedef long long llong;
typedef long long int64;
typedef long double ld;
typedef unsigned long long ull;
typedef unsigned long long lint;
typedef unsigned int uint;
typedef pair <int, int> pii;
typedef vector <int> vi;
typedef complex <double> tc;

const int inf = int(1e9);
const double eps = 1e-9;
const double pi = 4 * atan(double(1));
const int N = int(1e6);

int ptr, lt, ls, mem_ptr;
bool used[N + 10];
char s[N + 10], t[N + 10];
int len[N + 10], pos[N + 10], num[N + 10], lst[N + 10], l[N + 10], r[N + 10];
int cnt[26][N + 10];

void dfs(int v){
	r[ptr] = mem_ptr++;
	used[v] = true;
	num[v] = ptr;
	lst[len[ptr]] = v;
	pos[v] = len[ptr]++;
	v = (v + ls) % lt;
	if(!used[v]){
		dfs(v);
	}
}

inline int get_cnt(int *cnt, int l, int r, int lg, int rg){
	if(l <= r){
		return cnt[r] - (l > 0 ? cnt[l - 1] : 0);
	}
	return get_cnt(cnt, l, rg, lg, rg) + get_cnt(cnt, lg, r, lg, rg);
}

int main(){
	ll n, m;
	scanf(LLD" "LLD, &n, &m);
	scanf("%s %s", s, t);
	ls = strlen(s);
	lt = strlen(t);
	ptr = mem_ptr = 0;
	for(int i = 0; i < lt; i++){
		if(used[i]){
			continue;
		}
		l[ptr] = mem_ptr;
		dfs(i);
		for(int j = 0; j < 26; j++){
			for(int z = 0; z < len[ptr]; z++){
				cnt[j][l[ptr] + z] = (z > 0 ? cnt[j][l[ptr] + z - 1] : 0) + (t[lst[z]] - 'a' == j);
			}
		}
		ptr++;
	}
	ll ans = n * ls;
	ptr = 0;
	for(int i = 0; i < ls; i++){
		ll k = n / len[num[ptr]];
		ans -= k * cnt[s[i] - 'a'][r[num[ptr]]];
		int ost = n % len[num[ptr]];
		if(ost > 0){
			ans -= get_cnt(cnt[s[i] - 'a'], l[num[ptr]] + pos[ptr], l[num[ptr]] + (pos[ptr] + ost - 1) % len[num[ptr]], l[num[ptr]], r[num[ptr]]);
		}
		ptr++;
		if(ptr >= lt){
			ptr = 0;
		}
	}
	printf(LLD"\n", ans);
	return 0;
}