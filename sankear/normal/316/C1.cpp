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
const int N = 80;
const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, -1, 0, 1};

struct edge{
	int go, cost, f, c;
};

int edges;
int a[N + 2][N + 2], num[N + 2][N + 2];
int first[N * N + 100];
int d[N * N + 100], pd[N * N + 100], pe[N * N + 100], pv[N * N + 100];
edge p[(N * N * 4 + N * N + N * N) * 2 + 100];
int next[(N * N * 4 + N * N + N * N) * 2 + 100];
set <pii> S;

inline void add(int from, int to, int cap, int cost){
	p[++edges].go = to;
	p[edges].c = cap;
	p[edges].f = 0;
	p[edges].cost = cost;
	next[edges] = first[from];
	first[from] = edges;
	p[++edges].go = from;
	p[edges].c = 0;
	p[edges].f = 0;
	p[edges].cost = -cost;
	next[edges] = first[to];
	first[to] = edges;
}

int main(){
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n, m;
	scanf("%d %d", &n, &m);
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			scanf("%d", &a[i][j]);
		}
	}
	int ptr1 = 0, ptr2 = 0;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if((i + j) % 2 == 0){
				num[i][j] = ptr1++;
			}
			else{
				num[i][j] = ptr2++;
			}
		}
	}
	int s = ptr1 + ptr2, t = s + 1;
	edges = 0;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if((i + j) % 2 == 0){
				add(s, num[i][j], 1, 0);
			}
			else{
				add(num[i][j] + ptr1, t, 1, 0);
			}
		}
	}
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if((i + j) % 2 == 0){
				for(int z = 0; z < 4; z++){
					int ni = i + dx[z], nj = j + dy[z];
					if(ni >= 0 && ni < n && nj >= 0 && nj < m){
						add(num[i][j], num[ni][nj] + ptr1, 1, (a[i][j] != a[ni][nj]));
					}
				}
			}
		}
	}
	for(int i = 0; i < n * m / 2; i++){
		for(int j = 0; j <= t; j++){
			d[j] = inf;
		}
		d[s] = 0;
		S.insert(mp(d[s], s));
		while(!S.empty()){
			int cur = (S.begin())->sc;
			S.erase(S.begin());
			for(int j = first[cur]; j > 0; j = next[j]){
				if(p[j].c - p[j].f > 0 && d[p[j].go] > d[cur] + pd[cur] + p[j].cost - pd[p[j].go]){
					S.erase(mp(d[p[j].go], p[j].go));
					d[p[j].go] = d[cur] + pd[cur] + p[j].cost - pd[p[j].go];
					pv[p[j].go] = cur;
					pe[p[j].go] = j;
					S.insert(mp(d[p[j].go], p[j].go));
				}
			}
		}
		int j = t;
		while(j != s){
			p[pe[j]].f++;
			p[(pe[j] % 2 == 0 ? pe[j] - 1 : pe[j] + 1)].f--;
			j = pv[j];
		}
		for(int j = 0; j <= t; j++){
			pd[j] = min(pd[j] + d[j], inf);
		}
	}
	int ans = 0;
	for(int i = 0; i <= t; i++){
		for(int j = first[i]; j > 0; j = next[j]){
			if(p[j].f > 0){
				ans += p[j].f * p[j].cost;
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}