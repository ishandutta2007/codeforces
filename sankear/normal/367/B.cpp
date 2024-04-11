#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cstring>
#include <cassert>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <bitset>
#include <complex>
#include <queue>
#include <deque>
#include <stack>

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
#define link _link
#define hash _hash
#define rank _rank
#define y0 yy0
#define y1 yy1

typedef long long ll;
typedef long long llong;
typedef long long int64;
typedef unsigned long long ull;
typedef unsigned long long ullong;
typedef unsigned long long lint;
typedef unsigned int uint;
typedef pair <int, int> pii;
typedef vector <int> vi;
typedef complex <double> tc;
typedef long double ld;

const int inf = int(1e9);
const double eps = 1e-9;
const double pi = 4 * atan(double(1));
const int N = int(2e5) + 100;
const int LOG = 17;

int n, p, k;
bool used[N];
int a[N], b[N], lst[N];
int c[N * 2], cnt[N];
vi ans;

void dfs(int a){
	used[a] = true;
	lst[k++] = a;
	if(a + p < n){
		dfs(a + p);
	}
}

int main(){
	int m;
	scanf("%d %d %d", &n, &m, &p);
	int sz = 0;
	for(int i = 0; i < n; i++){
		scanf("%d", &a[i]);
		c[sz++] = a[i];
	}
	for(int i = 0; i < m; i++){
		scanf("%d", &b[i]);
		c[sz++] = b[i];
	}
	sort(c, c + sz);
	sz = unique(c, c + sz) - c;
	for(int j = 0; j < m; j++){
		cnt[lower_bound(c, c + sz, b[j]) - c]++;
	}
	int zeros = 0;
	for(int j = 0; j < sz; j++){
		zeros += (cnt[j] == 0);
	}
	for(int i = 0; i < n; i++){
		if(!used[i]){
			k = 0;
			dfs(i);
			if(k < m){
				continue;
			}
			for(int j = 0; j < m; j++){
				int pos = lower_bound(c, c + sz, a[lst[j]]) - c;
				if(cnt[pos] == 0){
					zeros--;
				}
				cnt[pos]--;
				if(cnt[pos] == 0){
					zeros++;
				}
			}
			for(int j = 0; j + m - 1 < k; j++){
				if(zeros == sz){
					ans.pb(lst[j]);
				}
				if(j + m < k){
					int pos = lower_bound(c, c + sz, a[lst[j]]) - c;
					if(cnt[pos] == 0){
						zeros--;
					}
					cnt[pos]++;
					if(cnt[pos] == 0){
						zeros++;
					}
					pos = lower_bound(c, c + sz, a[lst[j + m]]) - c;
					if(cnt[pos] == 0){
						zeros--;
					}
					cnt[pos]--;
					if(cnt[pos] == 0){
						zeros++;
					}
				}
			}
			for(int j = 0; j < m; j++){
				int pos = lower_bound(c, c + sz, a[lst[k - 1 - j]]) - c;
				if(cnt[pos] == 0){
					zeros--;
				}
				cnt[pos]++;
				if(cnt[pos] == 0){
					zeros++;
				}
			}
			
		}
	}
	sort(ans.begin(), ans.end());
	printf("%d\n", sz(ans));
	for(int i = 0; i < sz(ans); i++){
		printf("%d ", ans[i] + 1);
	}
	puts("");
	return 0;
}