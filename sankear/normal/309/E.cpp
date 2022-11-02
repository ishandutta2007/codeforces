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
const int N = 2000;

int n;
bool used[N + 10];
int l[N + 10], r[N + 10], num[N + 10], can[N + 10], sz[N + 10], perm[N + 10];

inline bool can_build(int mid){
	for(int i = 0; i < n; i++){
		used[i] = false;
		can[i] = n - 1;
	}
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			if(!used[j] && can[j] < i){
				return false;
			}
		}
		for(int j = i; j < n; j++){
			sz[j] = 0;
		}
		for(int j = 0; j < n; j++){
			if(!used[j]){
				sz[can[j]]++;
			}
		}
		for(int j = i + 1; j < n; j++){
			sz[j] += sz[j - 1];
		}
		for(int j = i; j < n; j++){
			if(sz[j] > j - i + 1){
				return false;
			}
		}
		int g = i;
		for(int j = i + 1; j < n; j++){
			if(j - i + 1 - sz[j] < g - i + 1 - sz[g]){
				g = j;
			}
		}
		int best = -1;
		for(int j = 0; j < n; j++){
			if(!used[j] && can[j] <= g && (best == -1 || r[j] < r[best])){
				best = j;
			}
		}
		perm[i] = num[best];
		used[best] = true;
		for(int j = 0; j < n; j++){
			if(!used[j] && max(l[j], l[best]) <= min(r[j], r[best])){
				can[j] = min(can[j], i + mid);
			}
		}
	}
	return true;
}

int main(){
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		scanf("%d %d", &l[i], &r[i]);
		num[i] = i;
	}
	for(int i = 0; i < n - 1; i++){
		for(int j = n - 1; j > i; j--){
			if(l[i] < l[j]){
				swap(l[i], l[j]);
				swap(r[i], r[j]);
				swap(num[i], num[j]);
			}
		}
	}
	int ans = n, l = 0, r = n - 1;
	while(l <= r){
		int mid = (l + r) / 2;
		if(can_build(mid)){
			ans = mid;
			r = mid - 1;
		}
		else{
			l = mid + 1;
		}
	}
	can_build(ans);
	for(int i = 0; i < n; i++){
		printf("%d ", perm[i] + 1);
	}
	puts("");
	return 0;
}