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
typedef unsigned long long ull;
typedef unsigned int uint;
typedef pair <int, int> pii;
typedef vector <int> vi;
typedef complex <double> tc;

const int inf = int(1e9);
const double eps = 1e-9;
const double pi = 4 * atan(double(1));
const int N = 8;

int sz, ans, n;
ll a[N + 10], val[N + 10];
int par[N + 10];
bool need[N + 10], prime[N + 10];
map <ll, int> cnt;

inline int get_cnt(ll ch){
	if(cnt.find(ch) != cnt.end()){
		return cnt[ch];
	}
	int ans = 0;
	ll cur = ch;
	for(ll i = 2; i * i <= ch; i++){
		while(ch % i == 0){
			ch /= i;
			ans++;
		}
	}
	if(ch > 1){
		ans++;
	}
	return cnt[cur] = ans;
}

void gen(int x){
	if(x >= n){
		int res = sz + (par[0] > 1);
		for(int i = 1; i <= sz && res < ans; i++){
			if(need[i] && val[i] > 1){
				res += get_cnt(val[i]);
			}
		}
		ans = min(ans, res);
		return;
	}
	for(int i = 0; i <= sz; i++){
		if(i == 0 || val[i] % a[x] == 0){
			if(i > 0){
				val[i] /= a[x];
			}
			par[i]++;
			val[++sz] = a[x];
			need[sz] = !prime[x];
			gen(x + 1);
			par[i]--;
			sz--;
			if(i > 0){
				val[i] *= a[x];
			}
		}
	}
}

int main(){
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		scanf(LLD, &a[i]);
	}
	sort(a, a + n);
	reverse(a, a + n);
	for(int i = 0; i < n; i++){
		prime[i] = (get_cnt(a[i]) == 1);
	}
	sz = 0;
	ans = inf;
	gen(0);
	printf("%d\n", ans);
	//cerr << ans << endl;
	return 0;
}