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
const int N = 100;

char s[N + 10];

int main(){
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int a, b;
	scanf("%d %d %s", &a, &b, s);
	int n = strlen(s), x = 0, y = 0;
	for(int i = 0; i < n; i++){
		if(s[i] == 'U'){
			y++;
		}
		if(s[i] == 'D'){
			y--;
		}
		if(s[i] == 'L'){
			x--;
		}
		if(s[i] == 'R'){
			x++;
		}
	}
	int vx = 0, vy = 0;
	for(int i = 0; i <= n; i++){
		if(x == 0){
			if(vx == a){
				if(y == 0){
					if(vy == b){
						puts("Yes");
						return 0;
					}
				}
				else{
					if((b - vy) % y == 0){
						int k = (b - vy) / y;
						if(k >= 0){
							puts("Yes");
							return 0;
						}
					}
				}
			}
		}
		else{
			if((a - vx) % x == 0){
				int k = (a - vx) / x;
				if(k >= 0 && vy + ll(k) * y == b){
					puts("Yes");
					return 0;
				}
			}
		}
		if(i == n){
			break;
		}
		if(s[i] == 'U'){
			vy++;
		}
		if(s[i] == 'D'){
			vy--;
		}
		if(s[i] == 'L'){
			vx--;
		}
		if(s[i] == 'R'){
			vx++;
		}
	}
	puts("No");
	return 0;
}