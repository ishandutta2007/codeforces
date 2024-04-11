#include<stdio.h>
#include<iostream>
#include<vector>
#include<math.h>
#include<algorithm>
#include<memory.h>
#include<map>
#include<queue>
#define O 200

using namespace std;

int n,m,x,y,p[111111],o[111111],a[111111],f[111111],ans=1e9,k=0,b[1111],kk[555],gg[O][111111],ff[O][111111],l[111111],r[111111];

int find(int x){
	int y=x;
	while (x!=p[x])x=p[x];
	while (y!=x){
		int t=p[y];
		p[y]=x;
		y=t;
	}
	return x;
}

bool ok(int x){
	while (x){
		if (x%10!=4&&x%10!=7)return 0;
		x/=10;
	}
	return 1;
}

int main(){
//	freopen("1.in","r",stdin);	
//	freopen("1.out","w",stdout);	
	cin >> n>> m;
	for (int i=0;i<n;i++)p[i]=i;
	for (int i=0;i<n;i++)o[i]=1;
	for(int i=0;i<m;i++){
		scanf("%d%d",&x,&y);
		x--;
		y--;
		if (find(x)==find(y))continue;
		o[p[y]]+=o[p[x]];
		p[p[x]]=p[y];
	}
	for (int i=0;i<n;i++)if (find(i)==i)if (o[i]<O)a[o[i]]++;else b[k++]=o[i];
	memset(f,63,sizeof(f));
	int g=min(n,77777);
	f[0]=0;
	for (int i=1;i<O;i++)if(a[i]){
		memset(kk,0,sizeof(kk));
		for (int j=0;j<=g;j++){
			ff[j%i][kk[j%i]]=f[j];
			gg[j%i][kk[j%i]++]=j;
		}
		for (int j=0;j<i;j++){
			for (int k=0;k<kk[j];k++)ff[j][k]-=k;
			for (int k=0;k<kk[j];k++)if (k%a[i]==0)l[k]=ff[j][k];else l[k]=min(l[k-1],ff[j][k]);
			r[kk[j]-1]=ff[j][kk[j]-1];
			for (int k=kk[j]-2;k>=0;k--)if ((k+1)%a[i]==0)r[k]=ff[j][k];else r[k]=min(r[k+1],ff[j][k]);
			for (int k=1;k<kk[j];k++)f[gg[j][k]]=min(f[gg[j][k]],min(l[k-1],r[max(k-a[i],0)])+k);
		}
	}
	for (int i=0;i<k;i++)for (int j=g;j>=0;j--)if (j+b[i]<=n)f[j+b[i]]=min(f[j+b[i]],f[j]+1);
	for (int i=1;i<=g;i++)if (ok(i))ans=min(ans,f[i]);
	if (ans>n)puts("-1");else cout << ans-1 << endl;
	return 0;
}