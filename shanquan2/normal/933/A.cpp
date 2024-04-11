#include<bits/stdc++.h>
using namespace std;

int n,a[2005],g[2005],f[2005][2005],s1[2005],s2[2005],pre[2005],suf[2005];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=1;i<=n;i++){
		s1[i]=s1[i-1]+(a[i]==1);
		s2[i]=s2[i-1]+(a[i]==2);
	}
	for(int i=1;i<=n;i++){
		f[i][i]=1;
		for(int j=i+1;j<=n;j++){
			f[i][j]=max(f[i][j-1]+(a[j]==1),s2[j]-s2[i-1]);
		}
	}
	for(int i=0;i<=n;i++)pre[i]=g[i]=s1[i]+s2[n]-s2[i];
	for(int i=1;i<=n;i++)pre[i]=max(pre[i-1],g[i]);
	for(int i=n;i>=0;i--)suf[i]=max(suf[i+1],g[i]);
	int ans=pre[n];
	for(int l=1;l<=n;l++)for(int r=l+1;r<=n;r++){
		int tmp=max(pre[l-1],suf[r]);
		tmp=max(tmp,s1[l-1]+s2[n]-s2[r]+f[l][r]);
//		printf("%d %d %d\n",l,r,tmp);
		if(tmp>ans)ans=tmp;
	}
	printf("%d\n",ans);
	return 0;
}