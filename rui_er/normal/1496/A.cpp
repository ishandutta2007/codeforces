//By: Luogu@rui_er(122461)
//As a tester...
#include <bits/stdc++.h>
#define loop while(true)
#define rep(x,y,z) for(int x=y;x<=z;x++)
#define per(x,y,z) for(int x=y;x>=z;x--)
#define fil(x,y) memset(x, y, sizeof(x))
using namespace std;
typedef long long ll;
const int N = 105;

int n, k;
char s[N];
int gi(int l, int r) {
	int x;
	scanf("%d", &x);
	assert(x>=l&&x<=r);
	return x;
}
void chkstr(char* s, int x) {assert(int(strlen(s))==x);}

int main() {
	for(int T=gi(1, 100);T;T--) {
		n = gi(1, 100); k = gi(0, n/2);
		scanf("%s", s+1); chkstr(s+1, n);
		if(!k) puts("YES");
		else if(k * 2 == n) puts("NO");
		else {
			int l = 1, r = n;
			while(l <= r && s[l] == s[r]) ++l, --r;
			if(l >= r || l > k) puts("YES");
			else puts("NO");
		}
	} 
	return 0;
}