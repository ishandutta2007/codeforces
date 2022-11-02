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
const int N = 100;

int a[N + 10], x[N + 10], y[N + 10];
ll dist[N + 10][N + 10];
ll d[N + 10];
bool used[N + 10];
queue <int> q;

int main(){
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n, D;
	scanf("%d %d", &n, &D);
	for(int i = 1; i < n - 1; i++){
		scanf("%d", &a[i]);
	}
	for(int i = 0; i < n; i++){
		scanf("%d %d", &x[i], &y[i]);
	}
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			if(i == j){
				dist[i][j] = inf;
				continue;
			}
			dist[i][j] = D * (abs(x[i] - x[j]) + abs(y[i] - y[j])) - a[j]; 
		}
	}
	int ans = -1, l = 0, r = inf;
	while(l <= r){
		int mid = (l + r) / 2;
		for(int i = 0; i < n; i++){
			d[i] = ll(inf) * inf;
		}
		d[0] = -mid;
		used[0] = true;
		q.push(0);
		while(!q.empty()){
			int cur = q.front();
			q.pop();
			used[cur] = false;
			for(int i = 0; i < n; i++){
				if(d[cur] + dist[cur][i] < d[i]){
					d[i] = d[cur] + dist[cur][i];
					if(!used[i]){
						used[i] = true;
						q.push(i);
					}
				}
			}
		}
		if(d[n - 1] <= 0){
			ans = mid;
			r = mid - 1;
		}
		else{
			l = mid + 1;
		}
	}
	printf("%d\n", ans);
	return 0;
}