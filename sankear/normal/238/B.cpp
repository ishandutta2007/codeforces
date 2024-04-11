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
#define link _link

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

pii p[100100];
int col[100100];

int main(){
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, h;
	scanf("%d %d", &n, &h);
	for(int i = 0; i < n; i++){
		scanf("%d", &p[i].fs);
		p[i].sc = i;
	}
	sort(p, p + n);
	int ans = inf, best = -1;
	for(int i = 0; i <= n; i++){
		int min_d = inf, max_d = -inf;
		if(i >= 2){
			min_d = min(min_d, p[0].fs + p[1].fs);
			max_d = max(max_d, p[i - 2].fs + p[i - 1].fs);
		}	
		if(n - i >= 2){
			min_d = min(min_d, p[i].fs + p[i + 1].fs);
			max_d = max(max_d, p[n - 2].fs + p[n - 1].fs);
		}
		if(i >= 1 && n - i >= 1){
			min_d = min(min_d, p[0].fs + p[i].fs + h);
			max_d = max(max_d, p[i - 1].fs + p[n - 1].fs + h);
		}
		if(max_d - min_d < ans){
			ans = max_d - min_d;
			best = i;
		}
	}
	for(int i = 0; i < best; i++){
		col[p[i].sc] = 1;
	}
	for(int i = best; i < n; i++){
		col[p[i].sc] = 2;
	}
	printf("%d\n", ans);
	for(int i = 0; i < n; i++){
		printf("%d ", col[i]);
	}
	printf("\n");
	return 0;
}