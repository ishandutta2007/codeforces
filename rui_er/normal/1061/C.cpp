//By: OIer rui_er
#include <bits/stdc++.h>
#define rep(x,y,z) for(int x=(y);x<=(z);x++)
#define per(x,y,z) for(int x=(y);x>=(z);x--)
#define debug(format...) fprintf(stderr, format)
#define fileIO(s) do{freopen(s".in","r",stdin);freopen(s".out","w",stdout);}while(false)
using namespace std;
typedef long long ll;
const int N = 1e5+5, mod = 1e9+7;

int n, a[N], dp[N], ans;
vector<int> d;
template<typename T> void chkmin(T& x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T& x, T y) {if(x < y) x = y;}

int main() {
	scanf("%d", &n);
	rep(i, 1, n) scanf("%d", &a[i]);
	dp[0] = 1;
	rep(i, 1, n) {
		d.clear();
		for(int j=1;j*j<=a[i];j++) {
			if(!(a[i] % j)) {
				d.push_back(j);
				if(j * j < a[i]) d.push_back(a[i]/j);
			}
		}
		sort(d.begin(), d.end(), greater<int>());
		for(int j : d) if(j <= n) dp[j] = (dp[j] + dp[j-1]) % mod;
	}
	rep(i, 1, n) ans = (ans + dp[i]) % mod;
	printf("%d\n", ans);
	return 0;
}