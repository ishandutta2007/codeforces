#include<iostream>
#include<cstdio>
#include<algorithm>
#include<set>
#include<vector>
#include<ctime>
#include<cstring>
#include<map>
#include<functional>
#include<cmath>
#include<queue>
#define int long long
#define mp make_pair
#define PII pair<int,int>
#define fi first
#define se second
#define pb push_back
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c)){x=(x<<3)+(x<<1)+(c^48);c=getchar();}
	return f==-1?~x+1:x;
}
int n,m;
char str[10];
int a[50010],b[50010],op[50010];
vector<int>vec;
vector<int>adj[200010];
int fa[200010];
int find(int x){
	return fa[x]==x?x:fa[x]=find(fa[x]);
}
void merge(int x,int y){
	fa[find(x)]=find(y);
}
bool open[200010];
signed main(){
	n=read(),m=read();vec.pb(0);vec.pb(1ll<<n);
	for(int i=1;i<=m;++i){
		scanf("%s",str+1);
		a[i]=read(),b[i]=read();
		if(str[1]=='b'){
			op[i]=1;
			vec.pb(a[i]);vec.pb(b[i]+1);
		}
	}
	sort(vec.begin(),vec.end());
	vec.erase(unique(vec.begin(),vec.end()),vec.end());
	int tmp=vec.size()-1;
	for(int i=0;i<tmp;++i){
		int l=vec[i],r=vec[i+1]-1;
		int k=0;
		while((l>>k)!=(r>>k)) ++k;
		if(k!=0){
			vec.pb(r&(~((1ll<<k-1)-1)));
		}
	}
	sort(vec.begin(),vec.end());vec.erase(unique(vec.begin(),vec.end()),vec.end());
	// for(int i:vec) printf("%d ",i);printf("\n");
	function<void(int,int,int)>add=[&](int x,int y,int z){
		int l=max(vec[x],vec[y]-(1ll<<z)),r=min(vec[x+1]-1,vec[y+1]-(1ll<<z)-1);
		if((~l&(1ll<<z))||(~r&(1ll<<z))||(l>>z)!=(r>>z)){
			adj[x].pb(y);adj[y].pb(x);
		}
		return ;
	};
	for(int k=0;k<n;++k){
		for(int i=0,j=0;i<vec.size()-1;++i){
			// printf("%d %d %d\n",i,j,k);
			while(j<vec.size()-1&&vec[j+1]<=vec[i]+(1ll<<k)) ++j;
			while(j<vec.size()-1&&vec[j+1]<=vec[i+1]+(1ll<<k)){
				add(i,j,k);++j;
			}
			if(j<vec.size()-1&&vec[j]<vec[i+1]+(1ll<<k)){
				add(i,j,k);
			}
		}
	}
	for(int i=0;i<vec.size()-1;++i) fa[i]=i;
	fill(open,open+vec.size(),1);
	for(int i=1;i<=m;++i){
		if(op[i]==1){
			int l=lower_bound(vec.begin(),vec.end(),a[i])-vec.begin();
			int r=lower_bound(vec.begin(),vec.end(),b[i]+1)-vec.begin();
			// printf("i:%d,l:%d,r:%d\n",i,l,r);
			for(int j=l;j<r;++j) open[j]=0;
		}
	}
	for(int i=0;i<vec.size();++i){
		if(open[i]){
			for(int v:adj[i]){
				if(open[v]) merge(i,v);
			}
		}
	}
	vector<int>ans;
	for(int i=m;i>=1;--i){
		if(op[i]==1){
			int l=lower_bound(vec.begin(),vec.end(),a[i])-vec.begin();
			int r=lower_bound(vec.begin(),vec.end(),b[i]+1)-vec.begin();
			for(int j=l;j<r;++j){
				open[j]=1;
				for(int v:adj[j]){
					if(open[v]) merge(j,v);
				}
			}
		}
		else{
			int x=upper_bound(vec.begin(),vec.end(),a[i])-vec.begin()-1;
			int y=upper_bound(vec.begin(),vec.end(),b[i])-vec.begin()-1;
			ans.pb((find(x)==find(y)));
			// printf("%d\n",(find(x)==find(y)));
		}
	}
	reverse(ans.begin(),ans.end());
	for(int i:ans) printf("%d\n",i);
}