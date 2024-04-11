#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cassert>
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
#define hash _hash
#ifdef LOCAL
#define LLD "%I64d"
#else
#define LLD "%I64d"
#endif
 
typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef vector <int> vi;
typedef pair <int, int> pii;
typedef complex <double> tc;
 
const int inf = int(1e9);
const double eps = 1e-9;
const double pi = 4 * atan(double(1));

bool userow[200], usecol[200];
int a[200][200];

int main(){
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
	int n, m;
	scanf("%d %d", &n, &m);
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			scanf("%d", &a[i][j]);
		}
	}
	while(true){
		bool fl = false;
		for(int i = 0; i < n; i++){
			int sum = 0;
			for(int j = 0; j < m; j++){
				sum += a[i][j];
			}
			if(sum < 0){
				fl = true;
				userow[i] ^= true;
				for(int j = 0; j < m; j++){
					a[i][j] *= -1;
				}
			}
		}
		for(int i = 0; i < m; i++){
			int sum = 0;
			for(int j = 0; j < n; j++){
				sum += a[j][i];
			}
			if(sum < 0){
				fl = true;
				usecol[i] ^= true;
				for(int j = 0; j < n; j++){
					a[j][i] *= -1;
				}
			}
		}
		if(!fl){
			break;
		}
	}
	vi row;
	for(int i = 0; i < n; i++){
		if(userow[i]){
			row.pb(i);
		}
	}
	vi col;
	for(int i = 0; i < m; i++){
		if(usecol[i]){
			col.pb(i);
		}
	}
	printf("%d", sz(row));
	for(int i = 0; i < sz(row); i++){
		printf(" %d", row[i] + 1);
	}
	printf("\n%d", sz(col));
	for(int i = 0; i < sz(col); i++){
		printf(" %d", col[i] + 1);
	}
	printf("\n");
	return 0;
}