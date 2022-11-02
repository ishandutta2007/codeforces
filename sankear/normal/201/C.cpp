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
 
const ll inf = ll(1e18);
const double eps = 1e-9;
const double pi = 4 * atan(double(1));

ll a[100100], l1[100100], l2[100100], r1[100100], r2[100100];

int main(){
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
	int n;
	scanf("%d", &n);
	for(int i = 1; i < n; i++){
		scanf(LLD, &a[i]);
	}
	for(int i = 2; i <= n; i++){
		if(a[i - 1] % 2 == 0){
			l1[i] = l1[i - 1] + a[i - 1] - 1;
		}
		else{
			l1[i] = l1[i - 1] + a[i - 1];
		}
		if(a[i - 1] / 2 == 0){
			l2[i] = 0;
		}
		else{
			l2[i] = l2[i - 1] + 2 * (a[i - 1] / 2);
		}
		l1[i] = max(l1[i], l2[i]);
	}
	for(int i = n - 1; i >= 1; i--){
		if(a[i] % 2 == 0){
			r1[i] = r1[i + 1] + a[i] - 1;
		}
		else{
			r1[i] = r1[i + 1] + a[i];
		}
		if(a[i] / 2 == 0){
			r2[i] = 0;
		}
		else{
			r2[i] = r2[i + 1] + 2 * (a[i] / 2);
		}
		r1[i] = max(r1[i], r2[i]);
	}
	ll ans = 0;
	for(int i = 1; i <= n; i++){
		ans = max(ans, l2[i] + r1[i]);
		ans = max(ans, r2[i] + l1[i]);
		ans = max(ans, l2[i] + r2[i]);
	}
	printf(LLD"\n", ans);
	return 0;
}