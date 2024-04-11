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
const int N = 55;

struct edge{
	int go, c, f, w;
};

int edges;
bool used[N];
queue <int> q;
int pv[N], pe[N], first[N], d[N];
edge e[N * N * 4];
int next[N * N * 4];

inline void add(int a, int b, int c, int w){
	e[++edges].go = b;
	e[edges].c = c;
	e[edges].f = 0;
	e[edges].w = w;
	next[edges] = first[a];
	first[a] = edges;
	e[++edges].go = a;
	e[edges].c = e[edges].f = 0;
	e[edges].w = -w;
	next[edges] = first[b];
	first[b] = edges;
}

inline void gen(){
	freopen("input.txt", "w", stdout);
	cout << 50 << " " << 1000 << endl;
	for(int i = 0; i < 50; i++){
		for(int j = 0; j < 50; j++){
			cout << (i == j ? 0 : int(1e6)) << " ";
		}
		cout << endl;
	}
	exit(0);
}

int main(){
	//gen();
	int n, k;
	scanf("%d %d", &n, &k);
	edges = 0;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			int cur;
			scanf("%d", &cur);
			if(i != j && cur > 0){
				add(i, j, cur, 0);
				add(i, j, inf, 1);
			}
		}
	}
	int flow = 0, sum = 0;
	while(true){
		for(int i = 0; i < n; i++){
			d[i] = inf;
		}
		d[0] = 0;
		used[0] = true;
		q.push(0);
		while(!q.empty()){
			int v = q.front();
			q.pop();
			used[v] = false;
			for(int i = first[v]; i > 0; i = next[i]){
				if(e[i].c - e[i].f > 0 && d[e[i].go] > d[v] + e[i].w){
					d[e[i].go] = d[v] + e[i].w;
					pv[e[i].go] = v;
					pe[e[i].go] = i;
					if(!used[e[i].go]){
						used[e[i].go] = true;
						q.push(e[i].go);
					}
				}
			}
		}
		if(d[n - 1] == inf){
			break;
		}
		int max_f = inf;
		for(int i = n - 1; i > 0; i = pv[i]){
			max_f = min(max_f, e[pe[i]].c - e[pe[i]].f);
		}
		if(d[n - 1] > 0){
			max_f = min(max_f, (k - sum) / d[n - 1]);
		}
		if(max_f == 0){
			break;
		}
		flow += max_f;
		sum += max_f * d[n - 1];
		for(int i = n - 1; i > 0; i = pv[i]){
			e[pe[i]].f += max_f;
			if(pe[i] % 2 == 0){
				e[pe[i] - 1].f -= max_f;
			}
			else{
				e[pe[i] + 1].f -= max_f;
			}
		}
	}
	printf("%d\n", flow);
	return 0;
}