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

const ll inf = ll(1e15);
const double eps = 1e-9;
const double pi = 4 * atan(double(1));

int x[555];
bool used[555], use[555];
ll ans[555], d1[555], d2[555];
ll a[555][555], d[555][555];

int main(){
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			scanf(LLD, &a[i][j]);
		}
	}
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			d[i][j] = inf;
		}
	}
	for(int i = 0; i < n; i++){
		scanf("%d", &x[i]);
		x[i]--;
	}
	for(int i = n - 1; i >= 0; i--){
		used[x[i]] = true;
		for(int j = 0; j < n; j++){
			use[j] = false;
			d1[j] = a[x[i]][j];
		}
		for(int j = 0; j < n; j++){
			int cur = -1;
			for(int z = 0; z < n; z++){
				if(used[z] && !use[z] && (cur == -1 || d1[z] < d1[cur])){
					cur = z;
				}
			}
			if(cur == -1 || d1[cur] == inf){
				break;
			}
			use[cur] = true;
			for(int z = 0; z < n; z++){
				d1[z] = min(d1[z], d1[cur] + a[cur][z]);
			}
		}
		for(int j = 0; j < n; j++){
			use[j] = false;
			d2[j] = a[j][x[i]];
		}
		for(int j = 0; j < n; j++){
			int cur = -1;
			for(int z = 0; z < n; z++){
				if(used[z] && !use[z] && (cur == -1 || d2[z] < d2[cur])){
					cur = z;
				}
			}
			if(cur == -1 || d2[cur] == inf){
				break;
			}
			use[cur] = true;
			for(int z = 0; z < n; z++){
				d2[z] = min(d2[z], d2[cur] + a[z][cur]);
			}
		}
		for(int j = 0; j < n; j++){
			if(!used[j]){
				continue;
			}
			for(int z = 0; z < n; z++){
				if(used[z]){
					d[j][z] = min(d[j][z], d2[j] + d1[z]);
				}
			}
		}
		ans[i] = 0;
		for(int j = 0; j < n; j++){
			if(!used[j]){
				continue;
			}
			for(int z = 0; z < n; z++){
				if(used[z]){
					ans[i] += d[j][z];
				}
			}
		}
	}
	for(int i = 0; i < n; i++){
		printf(LLD" ", ans[i]);
	}
	printf("\n");
	return 0;
}