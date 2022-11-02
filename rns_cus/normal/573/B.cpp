#include <bits/stdc++.h>
using namespace std;
#define N 100009
#define inf 1000000009
int h[N],s[N],a[N];
int n;
main() {
	//freopen("b.in","r",stdin);
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",h+i);
	for (int i=1;i<=n;i++) {
		s[i]=min(s[i-1],h[i]-i);
		a[i]=s[i]+i;
	}
	reverse(h+1,h+n+1);
	for (int i=1;i<=n;i++) {
		s[i]=min(s[i-1],h[i]-i);
		a[n+1-i]=min(a[n+1-i],s[i]+i);
	}
	int ans=0;
	for (int i=1;i<=n;i++) ans=max(ans,a[i]);
	printf("%d\n",ans);
}