//By: OIer rui_er
#include <bits/stdc++.h>
#define rep(x,y,z) for(int x=(y);x<=(z);x++)
#define per(x,y,z) for(int x=(y);x>=(z);x--)
#define debug printf("Running %s on line %d...\n",__FUNCTION__,__LINE__)
#define fileIO(s) do{freopen(s".in","r",stdin);freopen(s".out","w",stdout);}while(false)
using namespace std;
typedef long long ll;
const int N = 2e5+5;

int n, a[N]; ll ans;
vector<int> pos[N];
template<typename T> void chkmin(T& x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T& x, T y) {if(x < y) x = y;}
struct BIT {
	int c[N];
	int lowbit(int x) {return x & (-x);}
	void add(int x, int k) {for(;x<=n;x+=lowbit(x)) c[x] += k;}
	int ask(int x) {int k = 0; for(;x;x-=lowbit(x)) k += c[x]; return k;}
}bit;

int main() {
	scanf("%d", &n);
	rep(i, 1, n) {
		scanf("%d", &a[i]);
		chkmin(a[i], n);
		bit.add(i, 1);
		pos[a[i]].push_back(i);
	}
	rep(i, 1, n) {
		if(a[i] > i) ans += bit.ask(a[i]) - bit.ask(i);
		for(int j : pos[i]) bit.add(j, -1);
	}
	printf("%lld\n", ans);
	return 0;
}