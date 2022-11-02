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

char a[110][10100];
int best[10100][110];

int main(){
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m;
	scanf("%d %d", &n, &m);
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			scanf(" %c", &a[i][j]);	
		}
	}
	for(int i = 0; i < n; i++){
		int f = -1, l = -1;
		for(int j = 0; j < m; j++){
			if(a[i][j] == '1'){
				if(f == -1){
					f = j;	
				}
				l = j;
			}
		}
		if(f == -1){
			printf("-1\n");
			return 0;
		}
		int cur = -1;
		for(int j = 0; j < m; j++){
			if(a[i][j] == '1'){
				cur = j;	
			}
			best[j][i] = inf;
			if(cur != -1){
				best[j][i] = min(best[j][i], j - cur);	
			}
			best[j][i] = min(best[j][i], m - l + j);
		}
		cur = -1;
		for(int j = m - 1; j >= 0; j--){
			if(a[i][j] == '1'){
				cur = j;	
			}
			if(cur != -1){
				best[j][i] = min(best[j][i], cur - j);	
			}
			best[j][i] = min(best[j][i], f + m - j);
		}
	}
	int ans = inf;
	for(int i = 0; i < m; i++){
		int res = 0;
		for(int j = 0; j < n; j++){
			res += best[i][j];	
		}
		ans = min(ans, res);
	}
	printf("%d\n", ans);
	return 0;
}