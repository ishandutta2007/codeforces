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
#include <complex>
#include <cassert>

using namespace std;

#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define sz(s) int((s).size())
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#define next _next
#define prev _prev
#define rank _rank
#define link _link

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

queue <int> q;
bool used[300300];
int bad[300300], col[300300];
vi v[300300];

inline void recount(int a){
	bad[a] = 0;
	for(int i = 0; i < sz(v[a]); i++){
		if(col[a] == col[v[a][i]]){
			bad[a]++;
		}
	}
}

int main(){
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	//freopen(".in", "r", stdin);
	//freopen(".out", "w", stdout);
	int n, m;
	scanf("%d %d", &n, &m);
	for(int i = 0; i < m; i++){
		int a, b;
		scanf("%d %d", &a, &b);
		a--;
		b--;
		v[a].pb(b);
		v[b].pb(a);
	}
	for(int i = 0; i < n; i++){
		col[i] = 0;
	}
	for(int i = 0; i < n; i++){
		recount(i);
		if(bad[i] > 1){
			used[i] = true;
			q.push(i);
		}
	}
	while(!q.empty()){
		int cur = q.front();
		q.pop();
		used[cur] = false;
		recount(cur);
		if(bad[cur] <= 1){
			continue;
		}
		col[cur] = 1 - col[cur];
		recount(cur);
		if(bad[cur] > 1 && !used[cur]){
			used[cur] = true;
			q.push(cur);
		}
		for(int i = 0; i < sz(v[cur]); i++){
			recount(v[cur][i]);
			if(bad[v[cur][i]] > 1 && !used[v[cur][i]]){
				used[v[cur][i]] = true;
				q.push(v[cur][i]);
			}
		}
	}
	for(int i = 0; i < n; i++){
		printf("%d", col[i]);
	}
	printf("\n");
	return 0;
}