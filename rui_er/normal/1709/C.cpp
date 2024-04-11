// Problem: C. Recover an RBS
// Contest: Codeforces - Educational Codeforces Round 132 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1709/problem/C
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

//By: OIer rui_er
#include <bits/stdc++.h>
#define rep(x,y,z) for(int x=(y);x<=(z);x++)
#define per(x,y,z) for(int x=(y);x>=(z);x--)
#define debug printf("Running %s on line %d...\n",__FUNCTION__,__LINE__)
#define fileIO(s) do{freopen(s".in","r",stdin);freopen(s".out","w",stdout);}while(false)
using namespace std;
typedef long long ll;
const int N = 2e5+5;

int T, n;
char s[N];
template<typename T> void chkmin(T& x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T& x, T y) {if(x < y) x = y;}

int main() {
	for(scanf("%d", &T);T;T--) {
		scanf("%s", s+1);
		n = strlen(s+1);
		int diff = 0, ques = 0;
		rep(i, 1, n) {
			if(s[i] == '(') ++diff;
			else if(s[i] == ')') --diff;
			else ++ques;
		}
		int left = (ques - diff) / 2;
		int now = 0;
		rep(i, 1, n) {
			if(s[i] == '?') {
				++now;
				if(now < left || now == left + 1) s[i] = '(';
				else s[i] = ')';
			}
		}
		diff = 0;
		int ok = 1;
		rep(i, 1, n) {
			if(s[i] == '(') ++diff;
			else --diff;
			if(diff < 0) ok = 0;
		}
		ok &= !diff;
		puts(ques&&ok?"NO":"YES");
	}
	return 0;
}