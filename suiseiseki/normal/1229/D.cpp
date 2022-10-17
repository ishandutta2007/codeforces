#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
using namespace std;
#define ll long long
#define Maxn 200000
#define Mod 1000000007
int n,m,p[Maxn+5][6],q[Maxn+5],r,f[155],sta[10005],top,t,b[6],e,num[Maxn+5],v[155],a[155],el,er,op;
int head[155],Next[Maxn>>1|5],adj[Maxn>>1|5];
ll ans;
int sum(int x[]){
	int s=0,ans=0,p=1;
	for(int i=m;i>0;i--){
		s=0;
		for(int j=i+1;j<=m;j++){
			if(x[j]<x[i]){
				s++;
			}
		}
		ans+=p*s;
		p*=(m-i+1);
	}
	return ans;
}
void Push(int u,int v){
	Next[++op]=head[u];
	head[u]=op;
	adj[op]=v;
}
int p1[6],p2[6];
struct str{
	int u,v;
};
vector<str> g[155];
void dfs2(int i){
	if(i>m){
		int op[6];
		for(int a=1,b;a<=m;a++){
			for(b=1;b<=m;b++){
				if(p1[a]==p2[b]){
					break;
				}
			}
			op[a]=b;
		}
		g[sum(op)].push_back((str){sum(p1),sum(p2)});
		return;
	}
	for(int j=1;j<=m;j++){
		if(v[j]==0){
			v[j]=1;
			p2[i]=j;
			dfs2(i+1);
			v[j]=0;
		}
	}
}
void dfs(int i){
	if(i>m){
		dfs2(1);
		return;
	}
	for(int j=1;j<=m;j++){
		if(f[j]==0){
			f[j]=1;
			p1[i]=j;
			dfs(i+1);
			f[j]=0;
		}
	}
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			scanf("%d",&p[i][j]);
		}
		num[i]=sum(p[i]);
	}
	dfs(1);
	for(int i=1,k;i<=n;i++){
		q[++r]=i;
		memset(f,0,sizeof f);
		f[0]=1;
		a[1]=0;
		k=1;
		top=0;
		memset(head,0,sizeof head);
		op=0;
		for(int j=r;j>0;j--){
			int last=k;
			for(int t=0;t<(int)g[num[q[j]]].size();t++){
				if(f[g[num[q[j]]][t].u]!=1||f[g[num[q[j]]][t].v]!=1){
					Push(g[num[q[j]]][t].u,g[num[q[j]]][t].v);
				}
			}
			for(int t=1;t<=k;t++){
				for(int e=head[a[t]];e!=0;e=Next[e]){
					if(f[adj[e]]==0){
						f[adj[e]]=1;
						a[++k]=adj[e];
					}
				}
			}
			if(last!=k){
				sta[++top]=q[j];
			}
			ans+=1ll*k*(q[j]-q[j-1]);
		}
		r=top;
		for(int j=1;j<=top;j++){
			q[j]=sta[top-j+1];
		}
	}
	cout<<ans<<endl;
	return 0;
}