//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
#define rep(x,y,z) for(int x=y;x<=z;x++)
#define per(x,y,z) for(int x=y;x>=z;x--)
#define debug printf("Running %s on line %d...\n",__FUNCTION__,__LINE__)
using namespace std;
typedef long long ll;
const int N = 2e5+5, B = 101, P = 1e9+7;

int n, m, a[26][N];
char s[N];
template<typename T> void chkmin(T &x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T &x, T y) {if(x < y) x = y;}
struct Hash {
	int h[N], pw[N];
	void init(int *p, int x) {
		pw[0] = 1;
		rep(i, 1, x) h[i] = (1LL * h[i-1] * B % P + p[i]) % P;
		rep(i, 1, x) pw[i] = 1LL * pw[i-1] * B % P;
	}
	int get(int L, int R) {
		return (h[R] - 1LL * h[L-1] * pw[R-L+1] % P + P) % P;
	}
}hsh[26];
vector<int> D, K, ans;

int main() {
	scanf("%d%d%s", &n, &m, s+1);
	rep(i, 1, n) ++a[s[i]-'a'][i];
	rep(i, 0, 25) hsh[i].init(a[i], n);
	rep(i, 1, m) {
		int x, y, len;
		scanf("%d%d%d", &x, &y, &len);
		D.clear(); K.clear();
		rep(k, 0, 25) D.push_back(hsh[k].get(x, x+len-1));
		rep(k, 0, 25) K.push_back(hsh[k].get(y, y+len-1));
		sort(D.begin(), D.end());
		sort(K.begin(), K.end());
		puts(D==K?"YES":"NO");
	}
	return 0;
}