#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <vector>
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
typedef unsigned long long ull;
typedef unsigned int uint;
typedef pair <int, int> pii;
typedef vector <int> vi;
typedef complex <double> tc;

const int inf = int(1e9);
const double eps = 1e-9;
const double pi = 4 * atan(double(1));

int a[100100], d[100100];

int main(){
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	//freopen(".in", "r", stdin);
	//freopen(".out", "w", stdout);
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		scanf("%d", &a[i]);
	}
	int ans = 0;
	for(int i = 0; i < n; i++){
		int res = 1;
		for(int j = 1; j * j <= a[i]; j++){
			if(a[i] % j == 0){
				if(j > 1){
					res = max(res, d[j] + 1);
				}
				if(a[i] / j > 1){
					res = max(res, d[a[i] / j] + 1);
				}
			}
		}
		ans = max(ans, res);
		for(int j = 1; j * j <= a[i]; j++){
			if(a[i] % j == 0){
				d[j] = max(d[j], res);
				d[a[i] / j] = max(d[a[i] / j], res);
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}