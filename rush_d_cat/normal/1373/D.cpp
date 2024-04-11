#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 200002;
int t,n,a[N];
LL s[N], mn[N];
int main() {
	scanf("%d", &t);
	while (t --) {
		scanf("%d",&n);
		LL ans=0;
		for(int i=1;i<=n;i++) {
			scanf("%d",&a[i]);
			if(i%2==1) ans+=a[i];
		}

		LL tmp=ans;
		for(int i=2;i<=n;i+=2){
			s[i]=s[i-2]+a[i]-a[i-1]; 
			mn[i]=min(s[i],mn[i-2]);
			ans=max(ans, tmp+s[i]-mn[i]);
		}

		for(int i=0;i<=n;i++) mn[i]=s[i]=0;
		for(int i=3;i<=n;i+=2){
			s[i]=s[i-2]+a[i-1]-a[i];
			mn[i]=min(s[i],mn[i-2]);
			ans=max(ans, tmp+s[i]-mn[i]);
		}
		printf("%lld\n", ans);
	}
}