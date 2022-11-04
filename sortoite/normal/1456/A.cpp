#include<bits/stdc++.h>
using namespace std;
using INT = long long;
const int N = 1e5 + 10;
char s[N];
int cnt[N];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
#endif
	int T; cin>>T;
	while(T--) {
		int n, p, k, x, y;
		cin>>n>>p>>k;
		scanf("%s", s + 1);
		cin>>x>>y;
		INT ans = 1e18;
		for(int i = 0; i <= n; i ++) cnt[i] = 0;
		for(int i = n; i >= p; i --) {
			if(s[i] == '0') cnt[i%k]++;
			ans = min(ans, 1ll * (i - p) * y + 1ll * x * cnt[i%k]);
		}
		cout<<ans<<endl;
	}
	return 0;
}