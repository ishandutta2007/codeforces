#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <string.h>
#include <vector>
#include <set>
#include <map>
#include <complex>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef complex <double> tc;

int k;
bool used[1000][1000], can[1000][1000];

inline void good(){
	printf("+\n");
}

inline void bad(){
	printf("-\n");
}

inline void stupid(int n, int m){
	memset(used, false, sizeof(used));
	memset(can, false, sizeof(can));
	for(int i = n; i >= 1; i--){
		for(int j = m; j >= 1; j--){
			if(i + 1 <= n && !can[i + 1][j]){
				can[i][j] = true;
			}
			if(j + 1 <= m && !can[i][j + 1]){
				can[i][j] = true;
			}
			if(i + k <= n && j + k <= m && !can[i + k][j + k]){
				can[i][j] = true;
			}
		}
	}
	if(can[1][1]){
		printf("+ ");
	}
	else{
		printf("- ");
	}
}

inline void solve(){
	int n, m;
	scanf("%d %d", &n, &m);
	//stupid(n, m);
	if(k >= n || k >= m){
		if((n + m) % 2 != 0){
			good();
			return;
		}
		bad();
		return;
	}
	n -= k;
	m -= k;
	int sz = min((n - 1) / (k + 1), (m - 1) / (k + 1)) + 1;
	n -= (sz - 1) * (k + 1);
	m -= (sz - 1) * (k + 1);
	//cerr << n << " " << m << " " << sz << endl;
	if(n == 1 || m == 1){
		good();
		return;
	}
	if(sz % 2 == 0 || k == 1){
		if((n + m) % 2 != 0){
			good();
			return;
		}
		bad();
		return;
	}
	if((n + m) % 2 == 0){
		good();
		return;
	}
	bad();
}

int main(){
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int t;
	scanf("%d %d", &t, &k);
	for(int i = 0; i < t; i++){
		solve();
	}
	return 0;
}