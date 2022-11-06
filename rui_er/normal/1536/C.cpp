//LG@rui_er
#include <bits/stdc++.h>
#define rep(x,y,z) for(int x=y;x<=z;x++)
#define per(x,y,z) for(int x=y;x>=z;x--)
using namespace std;
typedef long long ll;
const int N = 5e5+5;

int T, n;
char s[N];
map<pair<int, int>, int> buc;

int main() {
	for(scanf("%d", &T);T;T--) {
		buc.clear();
		scanf("%d%s", &n, s+1);
		int D = 0, K = 0;
		rep(i, 1, n) {
			if(s[i] == 'D') ++D;
			else ++K;
//			printf("%d%c", __gcd(D, K), " \n"[i==n]);
			int ratioD = D, ratioK = K, g = __gcd(D, K);
			ratioD /= g; ratioK /= g;
			int ans = ++buc[make_pair(ratioD, ratioK)];
			printf("%d%c", ans, " \n"[i==n]);
		}
	}
	return 0;
}