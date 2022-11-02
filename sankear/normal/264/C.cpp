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

const ll inf = ll(1e15);
const double eps = 1e-9;
const double pi = 4 * atan(double(1));

int a[100100], b[100100];
ll d[100100];

int main(){
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	//freopen(".in", "r", stdin);
	//freopen(".out", "w", stdout);
	int n, q;
	scanf("%d %d", &n, &q);
	for(int i = 0; i < n; i++){
		scanf("%d", &a[i]);
	}
	for(int i = 0; i < n; i++){
		scanf("%d", &b[i]);
	}
	for(int i = 0; i < q; i++){
		ll A, B;
		scanf("%I64d %I64d", &A, &B);
		for(int j = 1; j <= n; j++){
			d[j] = -inf;
		}
		ll max1 = 0, max2 = 0;
		int col1 = -1, col2 = -1;
		for(int j = 0; j < n; j++){
			ll res = B * a[j];
			if(col1 == b[j]){
				res = max(res, max2 + B * a[j]);
			}
			else{
				res = max(res, max1 + B * a[j]);
			}
			res = max(res, d[b[j]] + A * a[j]);
			d[b[j]] = max(d[b[j]], res);
			if(d[b[j]] > max1){
				if(col1 != b[j]){
					max2 = max1;
					col2 = col1;
				}
				max1 = d[b[j]];
				col1 = b[j];
			}
			else{
				if(d[b[j]] > max2 && col1 != b[j]){
					max2 = d[b[j]];
					col2 = b[j];
				}
			}
		}
		ll ans = 0;
		for(int j = 1; j <= n; j++){
			ans = max(ans, d[j]);
		}
		printf("%I64d\n", ans);
	}
	return 0;
}