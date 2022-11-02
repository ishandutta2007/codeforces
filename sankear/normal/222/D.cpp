#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <cstring>
#include <vector>
#include <set>
#include <map>
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

typedef long long ll;
typedef long long llong;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef vector <int> vi;
typedef pair <int, int> pii;
typedef complex <double> tc;

const int inf = int(1e9);
const double eps = 1e-9;
const double pi = 4 * atan(double(1));

int a[100100], b[100100];

int main(){
	//freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("painting.in", "r", stdin);
    //freopen("painting.out", "w", stdout);
	int n, x;
	scanf("%d %d", &n, &x);
	for(int i = 0; i < n; i++){
		scanf("%d", &a[i]);	
	}
	for(int i = 0; i < n; i++){
		scanf("%d", &b[i]);	
	}
	sort(a, a + n);
	sort(b, b + n);
	int ans = 0, cur = 0;
	for(int i = n - 1; i >= 0; i--){
		while(cur < n && a[i] + b[cur] < x){
			cur++;
		}
		if(cur < n && a[i] + b[cur] >= x){
			ans++;
			cur++;
		}
	}
	printf("1 %d\n", ans);
	return 0;
}