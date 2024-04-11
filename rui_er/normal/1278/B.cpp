//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
#define loop while(true)
#define rep(x,y,z) for(int x=y;x<=z;x++)
#define per(x,y,z) for(int x=y;x>=z;x--)
#define fil(x,y) memset(x, y, sizeof(x))
using namespace std;
typedef long long ll;

int T, x, y;

int main() {
	scanf("%d", &T);
	while(T--) {
		scanf("%d%d", &x, &y);
		int ans = 0;
		if(x > y) swap(x, y);
		while(x < y || (x - y) & 1) x += ++ans;
		printf("%d\n", ans);
	}
	return 0;
}