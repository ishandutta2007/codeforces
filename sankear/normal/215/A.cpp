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

int a[100], b[100];

int main(){
#ifdef HOME
	double start = clock();
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#else
	//freopen("davidsmagic.in", "r", stdin);
	//freopen("davidsmagic.out", "w", stdout);
#endif
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		scanf("%d", &a[i]);
	}
	int m;
	scanf("%d", &m);
	for(int i = 0; i < m; i++){
		scanf("%d", &b[i]);
	}
	int ans = 0, best = 0;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(b[j] % a[i] == 0){
				int cur = b[j] / a[i];
				if(cur > best){
					best = cur;
					ans = 1;
				}
				else{
					if(cur == best){
						ans++;
					}
				}
			}
		}
	}
	printf("%d\n", ans);
#ifdef HOME
	printf("time = %.18lf\n", (clock() - start) / CLOCKS_PER_SEC);
#endif
	return 0;
}