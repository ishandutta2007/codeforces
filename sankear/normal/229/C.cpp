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

vi v[1000100];

bool can[10][10];

int main(){
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
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
	
	/*int res = 0;
	for(int i = 0; i < m; i++){
		can[a[i]][b[i]] = can[b[i]][a[i]] = true;	
	}
	for(int i = 0; i < n; i++){
		for(int j = i + 1; j < n; j++){
			for(int z = j + 1; z < n; z++){
				if((can[i][j] && can[j][z] && can[z][i]) || (!can[i][j] && !can[j][z] && !can[z][i])){
					res++;
				}	
			}
		}
	}
	cout << res << endl;*/
	
	ll del = 0;
	for(int i = 0; i < n; i++){
		if(sz(v[i]) > 1){
			del += ll(sz(v[i])) * (sz(v[i]) - 1) / 2;
		}
	}
	for(int i = 0; i < n; i++){
		for(int j = 0; j < sz(v[i]); j++){
			if(i < v[i][j]){
				del += n - sz(v[i]) - sz(v[v[i][j]]);
			}
		}
	}
	ll ans = ll(n) * (n - 1) * (n - 2) / 6;
	ans -= del;
	cout << ans << endl;
	return 0;
}