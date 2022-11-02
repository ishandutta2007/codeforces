#include<bits/stdc++.h>
const int V=500005,M=1000000007;
using namespace std;
int n,m=1,d,p,x,t,ans,
q[V],de[V],f[V],c[V][10],
g[4][V],h[4][V];
char S[1003],L[55],R[55];
inline void sol(char*T){
	memset(g,0,sizeof g);g[0][1]=1;
	for(int i=0;i<d;i++){
		//cerr<<i<<"====\n";
		for(int j=0;j<4;j++)
		for(int k=1;k<=m;k++)
		h[j][k]=g[j][k],g[j][k]=0;
		for(int j=0;j<4;j++)
		for(int k=1;k<=m;k++)
		if(t=h[j][k]){
			//cerr<<"("<<j<<','<<k<<")"<<t<<endl;
		for(int l=0;l<10;l++)
		if((j&1)||l<T[i]-47){
			p=c[k][l];
			x=j|(l<T[i]-48)|(de[p]>=d/2?2:0);
			//cerr<<"trans to "<<x<<','<<p<<")\n";
			g[x][p]=(g[x][p]+t)%M;
		}}
	}/*
	cerr<<"fin\n";
		for(int j=0;j<4;j++)
		for(int k=1;k<=m;k++)
		if(t=g[j][k])
			cerr<<"("<<j<<','<<k<<")"<<t<<endl;*/
}
int main(){
	//freopen("dat.txt","r",stdin);
	scanf("%s%s%s",S,L,R);
	n=strlen(S),d=strlen(L);
	for(int i=0;i<10;i++)c[0][i]=1;
	for(int i=0;i<n;i++){
		p=1;
		for(int j=i;j<n;j++){
			if(!c[p][t=S[j]-48])
			c[p][t]=++m,de[m]=de[p]+1;
			p=c[p][t];
		}
	}t=q[0]=1;
	for(int i=0;i<t;){
		p=q[i++];
		for(int j=0;j<10;j++)
		if(x=c[p][j]){
			f[q[t++]=x]=c[f[p]][j];
		}
		else c[p][j]=c[f[p]][j];
	}
	sol(L);
	for(int i=1;i<=m;i++)
	ans=(ans-g[3][i])%M;
	//cerr<<"pre "<<ans<<endl;
	sol(R);
	for(int i=1;i<=m;i++)
	for(int j=0;j<2;j++)
	ans=(ans+g[2|j][i])%M;
	printf("%d",(ans+M)%M);
}