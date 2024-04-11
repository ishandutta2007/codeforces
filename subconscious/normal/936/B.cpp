#include<bits/stdc++.h>
#define rep(i,n) for(int i=1;i<=n;++i)
#define N 100005
using namespace std;
typedef long long ll;
int b[N],v[N<<1],f[N<<1],tot=0;
// 1 lose 2 draw 3 win
int typ[2][N],to[2][N];
bool in[2][N],fin[2][N];
int x,k;
void sol(int pos,int pye){
	in[pye][pos]=1;
	for(int i=b[pos];i;i=f[i]){
		int tp;
		if(fin[pye^1][v[i]])tp=typ[pye^1][v[i]];
		else if(in[pye^1][v[i]])tp=2;
		else sol(v[i],pye^1),tp=typ[pye^1][v[i]];
		//printf("%d %d %d\n",pos,pye,tp);
		if(tp<typ[pye][pos])continue;
		typ[pye][pos]=tp;
		to[pye][pos]=v[i];
	}
	if(typ[pye][pos]==0){
		if(pye==0)typ[pye][pos]=1;else typ[pye][pos]=3;
	}
	//printf("%d %d %d\n",pos,pye,typ[pos][pye]);
	in[pye][pos]=0;
	fin[pye][pos]=1;
}
int ans[N<<1],top=0;
void add(int x,int y){v[++tot]=y,f[tot]=b[x],b[x]=tot;}
int n,m;
int main(){
	scanf("%d%d",&n,&m);
	rep(i,n){
		scanf("%d",&k);
		rep(j,k)scanf("%d",&x),add(i,x);
	}
	int s;scanf("%d",&s);
	sol(s,0);
	if(typ[0][s]==1)puts("Lose");
	else if(typ[0][s]==2)puts("Draw");
	else if(typ[0][s]==3){
		bool tp=0;
		while(to[tp][s])ans[++top]=s,s=to[tp][s],tp^=1;
		ans[++top]=s;
		puts("Win");
		rep(i,top)printf("%d%c",ans[i],i==top?'\n':' ');
	}
	//system("pause");
	return 0;
}