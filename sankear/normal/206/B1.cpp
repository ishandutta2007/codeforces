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

int a[400], d[400], q[400];

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
		for(int j = 0; j < n; j++){
			d[j] = inf;
		}
		d[0] = 0;
		int l = 0, r = 1;
		q[0] = 0;
		while(l < r){
			int cur = q[l++];
			for(int i = cur + 1; i < n; i++){
				if(i - cur <= a[i] && d[i] > d[cur] + 1){
					d[i] = d[cur] + 1;
					q[r++] = i;
				}
			}
		}
		ans += d[n - 1];
		for(int i = n; i > 0; i--){
			a[i] = a[i - 1];
		}
		a[0] = a[n];
	}
	printf("%d\n", ans);
#ifdef HOME
	printf("time = %.18lf\n", (clock() - start) / CLOCKS_PER_SEC);
#endif
	return 0;
}