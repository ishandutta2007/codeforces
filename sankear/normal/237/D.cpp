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

vector <pii> e;
vector <pii> v[100100];
bool used[100100];
int a[100100], b[100100];

void dfs(int a, int b){
	used[a] = true;
	bool first = true;
	int last = -1;
	for(int i = 0; i < sz(v[a]); i++){
		if(!used[v[a][i].fs]){
			if(first && b != -1){
				e.pb(mp(b, v[a][i].sc));
			}
			if(last != -1){
				e.pb(mp(last, v[a][i].sc));
			}
			first = false;
			last = v[a][i].sc;
			dfs(v[a][i].fs, v[a][i].sc);
		}
	}
}

int main(){
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	//freopen("operators.in", "r", stdin);
	//freopen("operators.out", "w", stdout);
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n - 1; i++){
		scanf("%d %d", &a[i], &b[i]);
		a[i]--;
		b[i]--;
		v[a[i]].pb(mp(b[i], i));
		v[b[i]].pb(mp(a[i], i));
	}
	dfs(0, -1);
	printf("%d\n", n - 1);
	for(int i = 0; i < n - 1; i++){
		printf("2 %d %d\n", a[i] + 1, b[i] + 1);
	}
	for(int i = 0; i < n - 2; i++){
		printf("%d %d\n", e[i].fs + 1, e[i].sc + 1);
	}
	return 0;
}