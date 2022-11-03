/* by Natsu Kinmoe */
#include <bits/stdc++.h>
using namespace std;
#define SZ(x)               ((int)(x).size())
#define all(x)              (x).begin(), (x).end()
#define loop(i, n)          for(int i = 0; i < (n); i++)
#define cont(i, n)          for(int i = 1; i <= (n); i++)
#define circ(i, a, b)       for(int i = (a); i <= (b); i++)
#define range(i, a, b, c)   for(int i = (a); ((c) > 0 ? i <= (b) : i >= (b)); i += (c))
#define foreach(it, v)      for(__typeof((v).begin()) it = (v).begin(); it != (v).end(); it++)
#define y0          y0O0OO00OO0OO0OO0OOO00OO0OO0O0O000OO0
#define y1          y1II11II11III11I1III11II111IIII1II1I1
#define pub         push_back
#define pob         pop_back
#define mak         make_pair
typedef long long   ll;
typedef long double lf;
const int   Inf = 0x3f3f3f3f;
const ll    INF = 0x3f3f3f3f3f3f3f3fll;
/* Source code starts here */

// bool lon[1 << 20];
//
// int gcd(int a, int b) {return b ? gcd(b, a % b) : a;}
//
// int main() {
// 	int n; cin >> n;
// 	cont(i, n) lon[i] = 1;
// 	cont(i, n) circ(j, i + 1, n) {
// 		int a = gcd(i, j), b = i / a, c = j / a;
// 		if(a + b > c && a + c > b && b + c > a) {
// 			lon[i] = lon[j] = 0;
// 		}
// 	}
// 	int res = 0;
// 	cont(i, n) res += lon[i];
// 	cout << res << endl;
// 	return 0;
// }

const int maxn = 1 << 20;
int sus[maxn | 1];
int ss[maxn | 1];

int main() {
	circ(i, 2, maxn) if(!sus[i]) {
		range(j, i + i, maxn, i) sus[j] = 1;
	}
	circ(i, 2, maxn) ss[i] = ss[i - 1] + !sus[i];
	int t; scanf("%d", &t);
	while(t--) {
		int x; scanf("%d", &x);
		printf("%d\n", ss[x] - ss[int(sqrt(x) + 1e-5)] + 1);
	}
	return 0;
}