#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <cstring>
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

typedef long long ll;
typedef long long llong;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef vector <int> vi;
typedef pair <int, int> pii;
typedef complex <double> tc;

const int inf = int(1e9);
const double eps = 1e-9;
const double pi = 4 * atan(double(1));

bool used[200200];
int h[200200], res[200200], ans[200200], a[200200], b[200200];
vector <pii> v[200200];

void dfs(int ver, int d){
	used[ver] = true;
	h[ver] = d;
	for(int i = 0; i < sz(v[ver]); i++){
		if(!used[v[ver][i].fs]){
			res[v[ver][i].fs] = res[ver] + (a[v[ver][i].sc] == v[ver][i].fs);
			dfs(v[ver][i].fs, d + 1);
			ans[ver] += ans[v[ver][i].fs] + (a[v[ver][i].sc] == v[ver][i].fs);
		}
	}
}

int main(){
 	//freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
 	int n;
	scanf("%d", &n);
	for(int i = 0; i < n - 1; i++){
		scanf("%d %d", &a[i], &b[i]);
		a[i]--;
		b[i]--;
		v[a[i]].pb(mp(b[i], i));
		v[b[i]].pb(mp(a[i], i));
	}
	dfs(0, 0);
	int bans = inf;
	vi lst;
	for(int i = 0; i < n; i++){
		int cur = ans[0] + h[i] - 2 * res[i];
		if(cur < bans){
			bans = cur;
			lst.clear();
		}
		if(cur == bans){
			lst.pb(i);	
		}
	}
	printf("%d\n", bans);
	for(int i = 0; i < sz(lst); i++){
		if(i > 0){
			printf(" ");	
		}
		printf("%d", lst[i] + 1);
	}
	printf("\n");
	return 0;
}