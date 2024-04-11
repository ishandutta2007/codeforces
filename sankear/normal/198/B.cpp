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

char s[100100], t[100100];
int d[200200], q[200200], lev[200200];
vi v[200200];

int main(){
#ifdef HOME
	double start = clock();
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#else
	//freopen(".in", "r", stdin);
	//freopen(".out", "w", stdout);
#endif
	int n, k;
	scanf("%d %d %s %s", &n, &k, s, t);
	for(int i = 0; i < n; i++){
		lev[i] = i + 1;
		if(s[i] == 'X'){
			continue;
		}
		if(i > 0 && s[i - 1] == '-'){
			v[i].pb(i - 1);
		}
		if(i + 1 < n && s[i + 1] == '-'){
			v[i].pb(i + 1);
		}
		if(i + k < n && t[i + k] == '-'){
			v[i].pb(n + i + k);
		}
		if(i + k >= n){
			v[i].pb(2 * n);
		}
	}
	for(int i = 0; i < n; i++){
		lev[i + n] = i + 1;
		if(t[i] == 'X'){
			continue;
		}
		if(i > 0 && t[i - 1] == '-'){
			v[i + n].pb(i + n - 1);
		}
		if(i + 1 < n && t[i + 1] == '-'){
			v[i + n].pb(i + n + 1);
		}
		if(i + k < n && s[i + k] == '-'){
			v[i + n].pb(i + k);
		}
		if(i + k >= n){
			v[i + n].pb(2 * n);
		}
	}
	lev[2 * n] = inf;
	for(int i = 0; i <= 2 * n; i++){
		d[i] = inf;
	}
	d[0] = 0;
	int l = 0, r = 1;
	while(l < r){
		int cur = q[l++];
		for(int i = 0; i < sz(v[cur]); i++){
			if(d[cur] + 1 < lev[v[cur][i]] && d[v[cur][i]] > d[cur] + 1){
				d[v[cur][i]] = d[cur] + 1;
				q[r++] = v[cur][i];
			}
		}
	}
	if(d[2 * n] == inf){
		printf("NO\n");
		return 0;
	}
	printf("YES\n");
	return 0;
}