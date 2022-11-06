//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
#define loop while(true)
#define rep(x,y,z) for(int (x)=(y);(x)<=(z);(x)++)
#define per(x,y,z) for(int (x)=(y);(x)>=(z);(x)--)
#define fil(x,y) memset((x), (y), sizeof(x))
using namespace std;
typedef long long ll;

int n, t, c, ans, tot;

int main() {
	scanf("%d%d%d", &n, &t, &c);
	while(n--) {
		int _; scanf("%d", &_);
		if(_ > t) {ans += max(tot-c+1, 0); tot = 0;}
		else ++tot;
	}
	ans += max(tot-c+1, 0);
	printf("%d", ans);
	return 0;
}