#include<bits/stdc++.h>
const int N=100005;
using namespace std;
int n,u,v,pre[N],st[2][N],t[2],
typ[2][N],fin[4][N],tt[4],tp;
char S[N];
void print(int x){
	if(pre[x])print(pre[x]);
	printf("%d ",x);
}
int main(){
	scanf("%s",S+1);
	n=strlen(S+1);
	for(int i=1;i<=n;i++){
		u=S[i]=S[i]=='R';
		if(t[u^1])
		v=st[u^1][t[u^1]--],pre[i]=v;
		st[u][++t[u]]=i;
	}
	for(int i=0;i<2;i++)
	for(int j=t[i],k;j;j--){
		for(k=st[i][j];pre[k];k=pre[k]);
		typ[i][j]=S[k];
	}
	if(t[0]&&t[1]&&typ[0][t[0]]&&!typ[1][t[1]]){
		u=st[0][t[0]]<st[1][t[1]];
		swap(pre[st[u][t[u]]],st[u^1][t[u^1]]);
		typ[0][t[0]]^=1,typ[1][t[1]]^=1;
	}
	for(int i=0;i<2;i++)
	for(int j=t[i];j;j--)
	tp=typ[i][j]<<1|i,
	fin[tp][tt[tp]++]=st[i][j];
	u=tt[0]<tt[3];
	printf("%d\n",t[0]+t[1]-1);
	for(int i=0;i<tt[1+u];i++)
	print(fin[1+u][i]);
	if(tt[u*3])print(fin[u*3][0]);
	for(int i=0;i<tt[2-u];i++)
	print(fin[2-u][i]);
	for(int i=0;i<tt[3-u*3];i++){
		print(fin[3-u*3][i]);
		if(i+1<tt[u*3])print(fin[u*3][i+1]);
	}
}