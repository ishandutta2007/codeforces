#include<bits/stdc++.h>

#define x first
#define y second

using namespace std;

typedef long long INT;

int power(int a, int b, int m, int ans=1) {
	for (; b; b>>=1, a=1LL*a*a%m) if (b&1) ans=1LL*ans*a%m;
	return ans;
}

int cnt[33];
char s[250000];
int dp[250010];

int main(){
#ifndef ONLINE_JUDGE
	freopen("in.in","r",stdin);
	freopen("out.out","w",stdout);
#endif
	int T;
	cin >> T;
	
	while(T--) {
		int n, m, k;
		cin >> n >> m >> k;
		memset(cnt, 0, sizeof cnt);
		scanf("%s", s);
		for(int i=0; i<k; i++) cnt[s[i]-'A']++;
		INT ans=0x3f3f3f3f3f3f3f3f;
		for(int i=0; i<=25; i++) {
			for(int j=0; j<=k; j++) dp[j]=0;
			dp[0]=1;
			for(int j=0; j<=25; j++) if(i != j and cnt[j]) {
				for(int t=k; t>=cnt[j]; t--) if(dp[t-cnt[j]]) dp[t]=1;
			}
			for(int j=n; j>=0; j--) if(dp[j]) {
				int l=n-j;
				int r=m-(k-cnt[i]-j);
				r = max(r, 0);
				if(l+r<=cnt[i]) ans=min(ans, max(0ll, (INT)l*r));
			}
			for(int j=n; j<=k; j++) if(dp[j]) {
				if(k-j>=m) ans=0;
				break;
			}
		}
		cout << ans << endl;
	}
	
	return 0;
}