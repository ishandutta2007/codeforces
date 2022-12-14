#include<bits/stdc++.h>
using namespace std;

int n,m,k,b[100005],c[100005];

int main(){
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=n;i++)scanf("%d",b+i);
	for(int i=1;i<n;i++)c[i]=b[i+1]-b[i]-1;
	sort(c+1,c+n);
	int ans=n;
	for(int i=1;i<=n-k;i++)ans+=c[i];
	printf("%d\n",ans);
	return 0;
}