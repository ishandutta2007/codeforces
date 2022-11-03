#include<bits/stdc++.h>
using namespace std;

struct zdm{
	int nxt,to;
}e[1000005];
int n,go[1000005][26],fa[1000005],len[1000005],cnt,f[1000005][2],q[1000005],ft[1000005],m;
char s[1000005];
void dfs(int x){
	f[x][0]=0,f[x][1]=1;
	for(int i=ft[x];i;i=e[i].nxt){
		int y=e[i].to;dfs(y);
		f[x][0]+=max(f[y][0],f[y][1]);
		f[x][1]+=f[y][0];
	}
}
int main(){
	int T;scanf("%d",&T);
	while(T--){
		scanf("%d",&n);cnt=2;m=1;
		while(n--){
			scanf("%s",s);
			int now=1;len[now]=0;
			for(int i=0;s[i];i++){
				int x=s[i]-'a';
				if(!go[now][x])len[go[now][x]=cnt++]=len[now]+1;
				now=go[now][x];
			}
		}
		int h=0,t=0;
		for(int i=0;i<26;i++)if(go[1][i]){
			int u=go[1][i];
			fa[u]=1,q[t++]=u;
			e[m]=(zdm){ft[1],u};ft[1]=m++;
		}else go[1][i]=1;
		while(h<t){
			int u=q[h++];
			for(int i=0;i<26;i++)if(go[u][i]){
				int v=go[u][i];
				fa[v]=go[fa[u]][i];
				q[t++]=v;
				if(len[fa[v]]==len[v]-1)
					e[m]=(zdm){ft[fa[v]],v},ft[fa[v]]=m++;
				else e[m]=(zdm){ft[1],v},ft[1]=m++;
			}else go[u][i]=go[fa[u]][i];
		}
//		for(int i=1;i<cnt;i++){
//			for(int j=ft[i];j;j=e[j].nxt)printf("%d %d\n",i,e[j].to);
//		}
		int ans=0;
		dfs(1);
		printf("%d\n",f[1][0]);
		memset(f,0,sizeof(int)*cnt);
		memset(ft,0,sizeof(int)*cnt);
		for(int i=1;i<cnt;i++)for(int j=0;j<26;j++)go[i][j]=0;
	}
	return 0;
}