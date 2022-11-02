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

int n, k;
bool used[100100];
int a[100100];

int main(){
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d %d", &n, &k);
	for(int i = 0; i < n; i++){
		scanf("%d", &a[i]);
	}
	sort(a, a + n);
	int ans = 0;
	for(int i = 0; i < n; i++){
		if(!used[i]){
			if(k != 1){
				int j = i, len = 0;
				while(j < n){
					used[j] = true;
					len++;
					if(ll(a[j]) * k > int(1e9)){
						break;
					}
					int nj = lower_bound(a, a + n, a[j] * k) - a;
					if(nj < n && a[nj] == a[j] * k){
						j = nj;
					}
					else{
						j = n;
					}
				}
				ans += (len + 1) / 2;
			}
			else{
				ans++;
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}