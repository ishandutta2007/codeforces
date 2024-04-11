//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
#define loop while(true)
#define rep(x,y,z) for(int (x)=(y);(x)<=(z);(x)++)
#define per(x,y,z) for(int (x)=(y);(x)>=(z);(x)--)
#define fil(x,y) memset((x), (y), sizeof(x))
using namespace std;
typedef long long ll;
const int N = 1005;

int T, n, a[N];
map<int, int> mp;

int main() {
	scanf("%d", &T);
	while(T--) {
		mp.clear();
		scanf("%d", &n);
		int _ = 1;
		rep(i, 1, n) {
			scanf("%d", &a[i]);
			if(++mp[a[i]] > 1) _ = 0;
		}
		if(_) puts("NO");
		else puts("YES");
	}
	return 0;
}