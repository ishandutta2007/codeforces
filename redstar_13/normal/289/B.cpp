#include<bits/stdc++.h>
#define NN 10011

using namespace std;

int n,m,d;
int a[NN];
int ans;

int main () {
#ifndef ONLINE_JUDGE
	freopen("in.in","r",stdin);
	freopen("out.out","w",stdout);
#endif
	scanf("%d%d%d",&n,&m,&d);
	int k=1;
	for(int i=1; i<=n; i++)
		for(int j=1; j<=m; j++) scanf("%d",&a[k++]);
	k--;
	sort(a+1,a+k+1);
	for(int i=2; i<=k; i++) 
		if ((a[i] - a[i-1])%d !=0 ) {
			puts("-1"); return 0;
		}
	for(int i=1; i<=k; i++) ans+=abs(a[i]-a[(1+k)/2])/d;
	cout<<ans<<endl;
	return 0;
}