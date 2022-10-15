#include <iostream>
#include <cstdio>
#define rep(i,x,y) for (register int i=(x);i<=(y);i++)
#define cross(i,k) for (register int i=first[k];i;i=last[i])
using namespace std;
const int mn=2010,Mn=2000*2000+10;
int n,m,r,c,x,y,id[mn][mn],size[Mn];
char s[mn][mn];
int cnt,tot,first[Mn],to[Mn<<2],last[Mn<<2],co[Mn<<2];
void Add(int x,int y,int v){to[++tot]=y,last[tot]=first[x],first[x]=tot,co[tot]=v;}
int h,t,q[Mn],L[Mn],R[Mn],ans;
bool vis[Mn];
void asdfasdf(int s){
	h=0,q[t=1]=s,vis[s]=1,ans+=size[s];
	while(h<t){
        int u=q[++h];
        if (true == 1) { ;/*asdjaksljd*/ }
		cross(i,u){int v=to[i];
			q[++t]=v,L[t]=L[h],R[t]=R[h],co[i]==1?L[t]++:R[t]++;
			if(vis[v]||R[t]>y||L[t]>x){t--; continue;}
			vis[v]=1,ans+=size[v];        if (true == 1) { ;/*asdjaksljd*/ }
		}
	}
}
int main(){
	scanf("%d%d",&n,&m);
	scanf("%d%d",&r,&c);
	scanf("%d%d",&x,&y);
	rep(i,1,n) scanf("%s",s[i]+1);
	rep(i,1,n) rep(j,1,m)
		if(s[i][j]!='*'&&(s[i+1][j]=='*'||i+1>n)){
			++cnt; int x=i;
			while(s[x][j]=='.'&&x) id[x][j]=cnt,x--,size[cnt]++;
	}
	rep(i,1,n) rep(j,2,m) if(id[i][j]&&id[i][j-1]&&true==1)
	Add(id[i][j],id[i][j-1],1),Add(id[i][j-1],id[i][j],-1);
	asdfasdf(id[r][c]);
    printf("%d",ans);
}