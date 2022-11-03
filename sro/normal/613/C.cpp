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

int n;
int a[30];
char tmp[1 << 17];

int gcd(int a, int b) {
	return b ? gcd(b, a % b) : a;
}

int main() {
	scanf("%d", &n); int js = 0;
	loop(i, n) scanf("%d", a + i), js += (a[i] & 1);
	if(js >= 2) {
		puts("0");
		loop(i, n) loop(j, a[i]) printf("%c", i + 'a');
		return 0 & puts("");
	}
	if(js) {
		int g = 0, is = 0;
		loop(i, n) g = gcd(g, a[i]);
		string vc = "", cv;
		loop(i, n) {
			if(a[i] % 2 == 0) {
				loop(j, a[i] / g / 2) vc += i + 'a';
			} else {
				loop(j, (a[i] - g) / g / 2) vc += i + 'a';
				is = i;
			}
		}
		cv = vc; reverse(all(cv));
		vc = vc + char(is + 'a') + cv;
		cv = ""; loop(i, g) cv += vc;
		cout << g << endl;
		cout << cv << endl;
	} else {
		int g = 0;
		loop(i, n) g = gcd(g, a[i]);
		g /= 2; string vc = "", cv;
		loop(i, n) loop(j, a[i] / g / 2) vc += i + 'a';
		cv = vc; reverse(all(cv));
		vc = vc + cv;
		cv = ""; loop(i, g) cv += vc;
		cout << g * 2 << endl;
		cout << cv << endl;
	}
	return 0;
}