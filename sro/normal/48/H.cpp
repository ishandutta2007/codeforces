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

int n, m;
int a, b, c;
int s[105][105];
char d[6][6] = {"####", "....", "#//.", "\\.#\\", "\\#.\\", ".//#"};

int main() {
	scanf("%d%d", &n, &m);
	scanf("%d%d%d", &a, &b, &c);
	int ni = -1, nj = -1, mi, mj;
	cont(i, n) cont(j, m) {
		if(c > m) {
			s[i][j] = 6;
			ni = i, nj = j;
			c--;
		} else if(b) {
			s[i][j] = 1;
			b--;
		} else if(c) {
			s[i][j] = 6;
			mi = i, mj = j;
			c--;
		} else {
			s[i][j] = 0;
			a--;
		}
	}
	cont(i, n) cont(j, m) {
		if(ni < i || (ni == i && nj < j)) goto next;
		if(j <= nj) {
			int ix = (ni - i) & 1, jx = (nj - j) & 1;
			int xj = ix + jx * 2;
			s[i][j] = 2 + xj;
		} else {
			int ix = (ni - i - 1) & 1, jx = (nj - j) & 1;
			int xj = ix + jx * 2;
			s[i][j] = 2 + xj;
		}
	}
	next:
	cont(j, mj) s[mi][j] = 5 - 2 * ((mj - j) & 1);
	circ(j, mj + 1, m) s[mi - 1][j] = 3 + 2 * ((j - mj) & 1);
	loop(i, n << 1) {
		cont(j, m) {
			if(!(i & 1)) printf("%c%c", d[s[(i >> 1) + 1][j]][0], d[s[(i >> 1) + 1][j]][1]);
			else printf("%c%c", d[s[(i >> 1) + 1][j]][2], d[s[(i >> 1) + 1][j]][3]);
		}
		puts("");
	}
	return 0;
}
/*



0.  1.  2.  3.  4.  5.
##  ..  #/  \.  \#  ./
##  ..  /.  #\  .\  /#

*/