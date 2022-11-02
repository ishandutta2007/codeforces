#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <string.h>
#include <cstring>
#include <vector>
#include <set>
#include <map>
#include <complex>
#include <bitset>
#include <queue>
#include <cassert>

using namespace std;

//#define HOME
#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define next _next
#define rank _rank
#define prev _prev
#define sz(s) int((s).size())

typedef long long ll;
typedef unsigned long long ull;
typedef vector <int> vi;
typedef pair <int, int> pii;
typedef complex <double> tc;

const double eps = 1e-9;
const double pi = acos(double(-1));
const int inf = int(1e9);

vi v[5050];
bool used[5050], can[5050], cur[5050];
int sz[5050], p[5050];

void dfs(int a){
	used[a] = true;
	sz[a] = 1;
	for(int i = 0; i < sz(v[a]); i++){
		if(!used[v[a][i]]){
			p[v[a][i]] = a;
			dfs(v[a][i]);
			sz[a] += sz[v[a][i]];
		}
	}
}

int main(){
#ifdef HOME
	double start = clock();
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#else
	//freopen(".in", "r", stdin);
	//freopen(".out", "w", stdout);
#endif
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n - 1; i++){
		int a, b;
		scanf("%d %d", &a, &b);
		a--;
		b--;
		v[a].pb(b);
		v[b].pb(a);
	}
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			used[j] = false;
			p[j] = -1;
		}
		dfs(i);
		for(int j = 0; j <= n; j++){
			cur[j] = false;
		}
		cur[0] = true;
		for(int j = 0; j < n; j++){
			if(p[j] == i){
				for(int z = n; z >= sz[j]; z--){
					cur[z] |= cur[z - sz[j]];
				}
			}
		}
		for(int j = 1; j <= n; j++){
			can[j] |= cur[j];
		}
	}
	vector <pii> ans;
	for(int i = 1; i < n - 1; i++){
		if(can[i]){
			ans.pb(mp(i, n - i - 1));
		}
	}
	printf("%d\n", sz(ans));
	for(int i = 0; i < sz(ans); i++){
		printf("%d %d\n", ans[i].fs, ans[i].sc);
	}
	return 0;
}