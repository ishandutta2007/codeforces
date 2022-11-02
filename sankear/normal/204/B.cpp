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

int a[100100], b[100100];
int c[200200], cnt1[200200], cnt2[200200];

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
	int m = 0;
	for(int i = 0; i < n; i++){
		scanf("%d %d", &a[i], &b[i]);
		c[m++] = a[i];
		c[m++] = b[i];
	}
	sort(c, c + m);
	m = unique(c, c + m) - c;
	for(int i = 0; i < n; i++){
		cnt1[lower_bound(c, c + m, a[i]) - c]++;
		if(a[i] == b[i]){
			continue;
		}
		cnt2[lower_bound(c, c + m, b[i]) - c]++;
	}
	int ans = inf;
	for(int i = 0; i < m; i++){
		int need = max((n + 1) / 2 - cnt1[i], 0);
		if(need <= cnt2[i]){
			ans = min(ans, need);
		}
	}
	if(ans == inf){
		printf("-1\n");
		return 0;
	}
	printf("%d\n", ans);
	return 0;
}