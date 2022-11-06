//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
#define loop while(true)
#define rep(x,y,z) for(int (x)=(y);(x)<=(z);(x)++)
#define per(x,y,z) for(int (x)=(y);(x)>=(z);(x)--)
#define fil(x,y) memset((x), (y), sizeof(x))
using namespace std;
typedef long long ll;

int T, a, b, c;

int main() {
	scanf("%d", &T);
	while(T--) {
		scanf("%d%d%d", &a, &b, &c);
		int ans = (a + b + c + 2) / 2;
		printf("%d\n", min(c+1, max(0, a+c-ans+1)));
	}
	return 0;
}