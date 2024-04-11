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
const int steps = 31;

ll mem_cnt[steps + 10], mem_need[steps + 10], cnt[steps + 10], need[steps + 10];

int main(){
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n, m;
	scanf("%d %d", &n, &m);
	for(int i = 0; i < n; i++){
		int cur;
		scanf("%d", &cur);
		for(int j = 0; j < steps; j++){
			if((cur & (1 << j)) != 0){
				mem_cnt[j]++;
			}
		}
	}
	for(int i = 0; i < m; i++){
		int cur;
		scanf("%d", &cur);
		mem_need[cur]++;
	}
	int ans = 0, l = 1, r = m;
	while(l <= r){
		int mid = (l + r) / 2, cur = 0;
		for(int i = 0; i < steps; i++){
			cnt[i] = mem_cnt[i];
			need[i] = 0;
		}
		for(int i = 0; i < steps; i++){
			if(cur + mem_need[i] <= mid){
				need[i] = mem_need[i];
				cur += mem_need[i];
				continue;
			}
			need[i] = mid - cur;
			break;
		}
		bool good = true;
		for(int i = steps - 1; i >= 0; i--){
			if(cnt[i] < need[i]){
				good = false;
				break;
			}
			cnt[i] -= need[i];
			if(i > 0){
				cnt[i - 1] += 2 * cnt[i];
			}
		}
		if(good){
			ans = mid;
			l = mid + 1;
		}
		else{
			r = mid - 1;
		}
	}
	printf("%d\n", ans);
	return 0;
}