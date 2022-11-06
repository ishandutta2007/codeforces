//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
#define loop while(true)
#define rep(x,y,z) for(int x=y;x<=z;x++)
#define per(x,y,z) for(int x=y;x>=z;x--)
#define fil(x,y) memset(x, y, sizeof(x))
using namespace std;
typedef long long ll;

int n, p, hashTab[305];

int main() {
	scanf("%d%d", &p, &n);
	rep(i, 1, n) {
		int x;
		scanf("%d", &x);
		if(hashTab[x%p]) return printf("%d\n", i), 0;
		hashTab[x%p] = 1;
	}
	puts("-1");
	return 0;
}