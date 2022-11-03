#include<bits/stdc++.h>
using namespace std;

int n,a[200005],b[30][200005],d[30][200005],c[200005],r[200005],l[200005];
long long ans=0;
int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++)scanf("%d",&a[i]);
	for(int i=0;i<30;i++){
		b[i][n]=n;
		for(int j=n-1;j>=0;j--)if(a[j]>>i&1)b[i][j]=j;else b[i][j]=b[i][j+1];
		if(a[0]>>i&1)d[i][0]=0;else d[i][0]=-1;
		for(int j=1;j<n;j++)if(a[j]>>i&1)d[i][j]=j;else d[i][j]=d[i][j-1];
	}
//	for(int i=0;i<n;i++)printf("%d ",d[0][i]);printf("\n");
	int t=0;
	for(int i=0;i<n;i++){
		while(t&&a[c[t-1]]<=a[i])t--;
		if(t)l[i]=c[t-1]+1;else l[i]=0;
		c[t++]=i;
	}
	t=0;
	for(int i=n-1;i>=0;i--){
		while(t&&a[c[t-1]]<a[i])t--;
		if(t)r[i]=c[t-1]-1;else r[i]=n-1;
		c[t++]=i;
//		for(int j=0;j<t;j++)printf("%d ",c[j]);printf("\n");
	}
	for(int i=0;i<n;i++){
		int L=-1,R=n;
		for(int j=0;j<30;j++)if(!(a[i]>>j&1))L=max(L,d[j][i]),R=min(R,b[j][i]);
		L++,R--;L=max(L,l[i]),R=min(R,r[i]);
//		printf("%d %d %d %d %d\n",i,l[i],r[i],L,R);
		ans+=1ll*(i-l[i]+1)*(r[i]-i+1)-1ll*(i-L+1)*(R-i+1);
	}
	printf("%I64d\n",ans);
	return 0;
}