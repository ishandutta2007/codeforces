#include<cstdio>
#include<iostream>
#include<vector>
using namespace std;
const int o=2e5+10;
int T,n,a[o],p[o],q[o],cnt,fa[o],m,id[o];bool vis[o];vector<int> vec[o];
int fr(int x){return fa[x]==x?x:fa[x]=fr(fa[x]);}
int main(){
	for(scanf("%d",&T);T--;cnt=m=0){
		scanf("%d",&n);
		for(int i=1;i<=n;vis[i++]=0) vec[fa[i]=i].clear();
		for(int i=1;i<=n;++i) scanf("%d",&a[i]),vec[a[i]].push_back(i);
		for(int i=1;i<=n;++i) cnt+=(vec[i].size()&1);
		if(cnt>1||(n%2&&vec[a[(n+1)/2]].size()==1)){printf("NO\n");continue;}
		printf("YES\n");
		for(int i=1,t=0;i<=n;++i){
			if(vec[i].size()&1) for(int j=0,sz=vec[i].size();j<sz;++j)
				if(vec[i][j]!=(n+1)/2){p[(n+1)/2]=vec[i][j];vec[i].erase(vec[i].begin()+j);break;}
			for(int j=0,sz=vec[i].size();j<sz;j+=2) p[n-t]=vec[i][j],p[++t]=vec[i][j+1];
		}
		for(int i=1,j;i<=n;++i) if(!vis[i]){j=i;do vis[j]=1,fa[j]=i;while(!vis[j=p[j]]);}
		for(int i=1,u,v;i<=n/2;++i) if((u=fr(i))^(v=fr(n-i+1))) swap(p[i],p[n-i+1]),fa[u]=v;
		for(int i=1;i<=n;vis[i++]=0) q[i]=p[i];
		for(int i=1,j;i<=n;++i) if(!vis[i]) for(j=i,id[++m]=0;1;j=p[j]){
			vis[j]=1;
			if(!id[m]&&(n%2==0||j-(n+1)/2)) id[m]=j;
			if(p[j]==i) break;
		}
		for(int i=1;i<m;++i) p[id[i]]=q[n-id[i+1]+1],p[n-id[i]+1]=q[id[i+1]];
		p[id[m]]=q[id[1]];p[n-id[m]+1]=q[n-id[1]+1]; 
		for(int i=1;i<=n;++i) printf("%d ",p[i]);
		putchar('\n');
	}
	return 0;
}