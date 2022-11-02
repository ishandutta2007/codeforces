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

int ans[1000100];
vi v[1000100];

inline bool check(vi &a){
	if(sz(a) <= 2){
		return false;
	}
	int d = a[1] - a[0];
	for(int i = 2; i < sz(a); i++){
		if(a[i] - a[i - 1] != d){
			return true;
		}
	}
	return false;
}

int main(){
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
	int n, k;
	scanf("%d %d", &n, &k);
	for(int i = 0; i < 2 * k; i++){
		ans[i] = i / 2 + 1;
		v[i / 2].pb(i);
	}
	for(int i = 2 * k; i < n; i++){
		ans[i] = i % k + 1;
		v[i % k].pb(i);
	}
	for(int i = 0; i < k; i++){
		if(!check(v[i])){
			printf("-1\n");
			return 0;
		}
	}
	for(int i = 0; i < n; i++){
		printf("%d ", ans[i]);
	}
	printf("\n");
	return 0;
}