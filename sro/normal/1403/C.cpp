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

string suf[] = {"lios", "liala", "etr", "etra", "initis", "inites"};

int main() {
	string s;
	int valid = 1, mode = 0, gen = 0, wds = 0;
	while(cin >> s) {
		wds++; bool match = 0;
		loop(i, 6) if(suf[i].size() <= s.size() && s.substr(s.size() - suf[i].size()) == suf[i]) {
			match = 1;
			int ge = i & 1, par = i >> 1;
			gen |= 1 << ge;
			if(mode == 0 && par == 1) mode = 1;
			else if(mode == 0 && par == 2) valid = 0;
			else if(mode == 1 && par <= 1) valid = 0;
		}
		if(!match) return 0 & puts("NO");
	}
	if(wds == 1) return 0 & puts("YES");
	if(!valid || gen == 3 || mode == 0) return 0 & puts("NO");
	return 0 & puts("YES");
}