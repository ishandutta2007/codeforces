#include<bits/stdc++.h>
const int N=2000006;
using namespace std;
int T,n,de[N],to[N*2],hd[N*2],lk[N],cnt;
inline void add(int u,int v){
	de[u]++,to[++cnt]=v,hd[cnt]=lk[u],lk[u]=cnt;
}
inline void ad(int u,int v){add(u,v),add(v,u);}
int u,v;
bool fl;
char S[N];
int main(){
	for(scanf("%d",&T);T--;){
		scanf("%d",&n);
		for(int i=1;i<n;i++)
		scanf("%d%d",&u,&v),ad(u,v);
		scanf("%s",S+1);
		for(int i=n;i;i--)
		if(S[i]^'N')
		ad(i,++n),ad(n,n+1),ad(n,n+2),n+=2;
		v=0;
		for(int i=1;i<=n&&!fl;i++)
		if(de[i]>3)fl=1;
		else if(de[i]>2){
			v++,u=0;
			for(int j=lk[i];j;j=hd[j])
			if(de[to[j]]>1)u++;
			if(u>1)fl=1;
		}
		if(v>2||fl||v==2&&(n&1))puts("White");
		else puts("Draw");
		for(int i=1;i<=n;i++)
		lk[i]=de[i]=0;cnt=fl=0;
	}
}