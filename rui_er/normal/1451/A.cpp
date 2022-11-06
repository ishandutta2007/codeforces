//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
#define loop while(true)
#define rep(x,y,z) for(int (x)=(y);(x)<=(z);(x)++)
#define per(x,y,z) for(int (x)=(y);(x)>=(z);(x)--)
#define fil(x,y) memset((x), (y), sizeof(x))
using namespace std;
typedef long long ll;

int T, n;
int prime(int x) {
	if(x <= 1) return 0;
	int qwq = sqrt(x);
	rep(i, 1, qwq) if(x % i == 0) return 0;
	return 1;
}

int main() {
	scanf("%d", &T);
	while(T--) {
		int ans = 0;
		scanf("%d", &n);
		if(n == 1) puts("0");
		else if(n == 2) puts("1");
		else if(n == 3) puts("2");
		else if(!(n&1)) puts("2");
		else puts("3");
	}
	return 0;
}