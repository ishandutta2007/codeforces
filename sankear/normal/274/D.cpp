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

int sz;
bool used[500500];
vi v[500500];
int lst[500500], num[500500];
int *a[500500], *b[500500];
pii p[500500];

void dfs(int a){
	used[a] = true;
	for(int i = 0; i < sz(v[a]); i++){
		if(!used[v[a][i]]){
			dfs(v[a][i]);
		}
	}
	lst[sz++] = a;
}

int main(){
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n, m;
	scanf("%d %d", &n, &m);
	for(int i = 0; i < n; i++){
		a[i] = new int[m];
	}
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			scanf("%d", &a[i][j]);
		}
	}
	int ptr = m;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			p[j] = mp(a[i][j], j);
		}
		sort(p, p + m);
		int l = 0, r = 0;
		while(r + 1 < m && p[r + 1].fs == p[l].fs){
			r++;
		}
		while(r + 1 < m){
			int nl = r + 1, nr = nl;
			while(nr + 1 < m && p[nr + 1].fs == p[nl].fs){
				nr++;
			}
			if(p[l].fs == -1){
				l = nl;
				r = nr;
				continue;
			}
			for(int j = l; j <= r; j++){
				v[p[j].sc].pb(ptr);
			}
			for(int j = nl; j <= nr; j++){
				v[ptr].pb(p[j].sc);
			}
			ptr++;
			l = nl;
			r = nr;
		}
	}
	sz = 0;
	for(int i = 0; i < ptr; i++){
		if(!used[i]){
			dfs(i);
		}
	}
	for(int i = 0; i < n; i++){
		b[i] = new int[m];
	}
	int col = 0;
	for(int i = ptr - 1; i >= 0; i--){
		if(lst[i] < m){
			for(int j = 0; j < n; j++){
				b[j][col] = a[j][lst[i]];
			}
			num[col++] = lst[i];
		}
	}
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(b[i][j] == -1){
				if(j == 0){
					b[i][j] = 0;
				}
				else{
					b[i][j] = b[i][j - 1];
				}
			}
		}
	}
	for(int i = 0; i < n; i++){
		for(int j = 1; j < m; j++){
			if(b[i][j - 1] > b[i][j]){
				printf("-1\n");
				return 0;
			}
		}
	}
	for(int i = 0; i < m; i++){
		printf("%d ", num[i] + 1);
	}
	printf("\n");
	return 0;
}