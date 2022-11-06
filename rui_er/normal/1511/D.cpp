#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define per(i,a,b) for(int i=a;i>=b;i--)
using namespace std;
const int N = 2e5+5;

int n, k, len;
char c[N];

int main() {
	scanf("%d%d", &n, &k);
	rep(i, 'a', 'a'+k-1) {
		c[len++] = i;
		rep(j, i+1, 'a'+k-1) {
			c[len++] = i;
			c[len++] = j;
		}
	}
	c[len] = '\0';
	rep(i, 1, n/len) printf("%s", c);
	rep(i, n/len*len+1, n) printf("%c", c[(i+len-1)%len]);
	return 0;
}