#include<bits/stdc++.h>
#define MAXN 100005
#define MAXK 105
#define INF 0x3f3f3f3f
#define MOD 1000000007
#define F first
#define S second
using namespace std;
int n,k,l[MAXK+10],r[MAXK+10],f[MAXN*2+10][2],tmp[MAXN*2+10][2],q[MAXN*2+10],ql,qr;
int ans=INF;
int main(){
	scanf("%d%d",&n,&k);
	for(int i=1;i<=k;++i) scanf("%d%d",&l[i],&r[i]);
	memset(f,0x3f,sizeof f); f[0][0]=f[0][1]=0;
	for(int i=1;i<=k;++i){
		memset(tmp,0x3f,sizeof tmp); ql=1; qr=0;
		for(int j=0;j<=n*2;++j){
			if(j-r[i]+r[i-1]>=0) tmp[j][0]=min(tmp[j][0],f[j-r[i]+r[i-1]][0]);
			for(;ql<=qr&&f[j][1]<f[q[qr]][1];--qr); q[++qr]=j;
			for(;ql<=qr&&q[ql]<j-r[i]+l[i];++ql); if(ql<=qr) tmp[j][0]=min(tmp[j][0],f[q[ql]][1]+1);
		}
		ql=1; qr=0;
		for(int j=0;j<=n*2;++j){
			tmp[j][1]=min(tmp[j][1],f[j][1]);
			if(j-l[i]+r[i-1]>=0){
				for(;ql<=qr&&f[j-l[i]+r[i-1]][0]<f[q[qr]][0];--qr); q[++qr]=j-l[i]+r[i-1];
			}
			for(;ql<=qr&&q[ql]<j-r[i]+r[i-1];++ql); if(ql<=qr) tmp[j][1]=min(tmp[j][1],f[q[ql]][0]+1);
		}
		for(int j=0;j<=n*2;++j){
			f[j][0]=tmp[j][0]; f[j][1]=tmp[j][1];
			if(f[j][0]+1<f[j][1]) f[j][1]=f[j][0]+1;
			if(f[j][1]+1<f[j][0]) f[j][0]=f[j][1]+1;
		}
	}
	for(int i=0;i<=n*2;++i){
		if(i==r[k]-n) ans=min(ans,f[i][0]);
		if(i==n) ans=min(ans,f[i][1]);
	}
	if(ans>=INF) printf("Hungry\n");
	else printf("Full\n%d\n",ans);
}