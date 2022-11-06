//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
#define loop while(true)
#define rep(x,y,z) for(int x=y;x<=z;x++)
#define per(x,y,z) for(int x=y;x>=z;x--)
#define fil(x,y) memset(x, y, sizeof(x))
using namespace std;
typedef long long ll;

int T, a, b; 

int main() {
	scanf("%d", &T);
	while(T--) {
		scanf("%d%d", &a, &b);
		printf("%d %d\n", a-1, b);
	}
	return 0;
}