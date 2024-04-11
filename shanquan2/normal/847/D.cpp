#include<bits/stdc++.h>
using namespace std;

int n,t,m,a[200005],b[500005],s[500005];
int main(){
	scanf("%d%d",&n,&t);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if(a[i]<t)b[m++]=a[i]-i,b[m++]=t-i;
	}
	sort(b,b+m);m=unique(b,b+m)-b;
	for(int i=1;i<=n;i++)if(a[i]<t){
		int u=lower_bound(b,b+m,a[i]-i)-b;
		s[u]++;
		u=lower_bound(b,b+m,t-i)-b;
		s[u]--;
	}
	int ans=0;b[m]=2e9+1;
	for(int i=0;i<m;i++){
		if(i)s[i]+=s[i-1];
		if(ans<s[i]&&b[i+1]>0)ans=s[i];
	}
	printf("%d\n",ans);
	return 0;
}