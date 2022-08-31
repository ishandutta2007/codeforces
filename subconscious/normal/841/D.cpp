#include <bits/stdc++.h>
#define rep(i,n) for(int i=1;i<=n;++i)
#define N 300005
using namespace std;
int b[N],v[N<<1],f[N<<1],k[N<<1],tot=1;bool c[N<<1];
int d[N],n,m,p=0,cnt=0,ans[N],top=0;
void add(int x,int y,int key){v[++tot]=y,f[tot]=b[x],b[x]=tot;k[tot]=key;}
int q[N],l,r,tp[N];bool in[N];
void dfs(int x){
	in[x]=1;
	for(int i=b[x];i;i=f[i])if(!in[v[i]]){
		in[v[i]]=1;dfs(v[i]);
		if(d[v[i]]==1){
			ans[++top]=k[i];
			d[x]^=1;
		}
	}
}
int doit(){
	in[q[1]]=1;
	while(l!=r){
		int x=q[++l];
		for(int i=b[x];i;i=f[i])if(!in[v[i]]){
			in[v[i]]=1;q[++r]=v[i];tp[r]=i^1;
		}
	}
	for(int i=n;i>1;--i){
		int x=q[i];
		if(d[x]==1){
			ans[++top]=k[tp[i]];
			if(d[v[tp[i]]]==0)d[v[tp[i]]]=1;
			if(d[v[tp[i]]]==1)d[v[tp[i]]]=0;
			d[x]=0;
		}
	}
}
void pri(){

	printf("%d\n",top);
	sort(ans+1,ans+top+1);
	rep(i,top)printf("%d\n",ans[i]);
}
int main(){
	scanf("%d%d",&n,&m);
	rep(i,n){
		scanf("%d",d+i);
		if(d[i]==-1)p=i;
		if(d[i]==1)++cnt;
	}
	int x,y;
	rep(i,m){
		scanf("%d%d",&x,&y);
		if(x==y)continue;
		add(x,y,i),add(y,x,i);
	}
	if(p!=0){
		if(cnt%2==1)d[p]=1;
		rep(i,n)if(d[i]==-1)d[i]=0;
		//rep(i,n)printf("%d\n",d[i]);
		dfs(1);pri();
	}else if(cnt%2==0){
		dfs(1);pri();
	}else puts("-1");
	return 0;
}