#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <cmath>
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
#include <cassert>

using namespace std;

#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define sz(s) int((s).size())
#ifdef LOCAL
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#define LLD "%lld"
#else
#define eprintf(...) 42
#define LLD "%I64d"
#endif
#define next _next
#define prev _prev
#define rank _rank
#define link _link
#define hash _hash

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

int a[100100];

int main(){
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n;
	scanf("%d", &n);
	int l = 0, r = n - 1, ptr1 = 1, ptr2 = n;
	while(l <= r){
		if(l == r){
			a[l] = ptr1;
			break;
		}
		if(l + 1 == r){
			printf("-1\n");
			return 0;
		}
		if(l + 2 == r){
			printf("-1\n");
			return 0;
		}
		a[l++] = ptr1 + 1;
		a[r--] = ptr2 - 1;
		a[l++] = ptr2;
		a[r--] = ptr1;
		ptr1 += 2;
		ptr2 -= 2;
	}
	for(int i = 0; i < n; i++){
		if(a[a[i] - 1] != n - i){
			printf("-1\n");
			return 0;
		}
	}
	for(int i = 0; i < n; i++){
		printf("%d ", a[i]);
	}
	printf("\n");
	return 0;
}