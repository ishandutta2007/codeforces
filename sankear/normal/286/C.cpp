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
#define stack _stack

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

int a[1000100], stack[1000100];

int main(){
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		scanf("%d", &a[i]);
	}
	int m;
	scanf("%d", &m);
	for(int i = 0; i < m; i++){
		int num;
		scanf("%d", &num);
		num--;
		a[num] *= -1;
	}
	int k = 0;
	for(int i = n - 1; i >= 0; i--){
		if(a[i] > 0){
			if(k > 0 && stack[k - 1] == a[i]){
				k--;
				continue;
			}
			stack[k++] = a[i];
			a[i] *= -1;
			continue;
		}
		stack[k++] = -a[i];
	}
	if(k > 0){
		printf("NO\n");
		return 0;
	}
	printf("YES\n");
	for(int i = 0; i < n; i++){
		printf("%d ", a[i]);
	}
	printf("\n");
	return 0;
}