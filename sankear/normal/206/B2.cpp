#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <cstring>
#include <string.h>
#include <vector>
#include <set>
#include <map>
#include <bitset>
#include <complex>
#include <queue>
#include <cassert>

using namespace std;

//#define HOME
#define pb push_back
#define mp make_pair
#define next _next
#define prev _prev
#define rank _rank
#define fs first
#define sc second
#define sz(s) int((s).size())

typedef long long ll;
typedef unsigned long long ull;
typedef vector <int> vi;
typedef pair <int, int> pii;
typedef complex <double> tc;

const int inf = int(1e9);
const double eps = 1e-9;
const double pi = acos(double(-1));

int a[10100], best[10100];

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
	for(int i = 0; i < n; i++){
		scanf("%d", &a[i]);
	}
	int ans = 0;
	for(int i = 0; i < n; i++){
		best[n - 1] = n - 1;
		for(int j = n - 2; j >= 0; j--){
			best[j] = best[j + 1];
			while(best[j] - j > a[best[j]]){
				best[j]--;
			}
		}
		int cur = 0;
		while(cur < n - 1){
			cur = best[cur];
			ans++;
		}
		for(int j = n; j > 0; j--){
			a[j] = a[j - 1];
		}
		a[0] = a[n];
	}
	printf("%d\n", ans);
#ifdef HOME
	printf("time = %.18lf\n", (clock() - start) / CLOCKS_PER_SEC);
#endif
	return 0;
}