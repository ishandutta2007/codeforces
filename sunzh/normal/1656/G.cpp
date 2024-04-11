#include<iostream>
#include<cstdio>
#include<algorithm>
#include<set>
#include<vector>
#include<ctime>
#include<cstring>
#include<map>
#include<cmath>
#include<queue>
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
int T;
int n;
int p[200010],fa[200010];
int cnt[200010],lst[200010];
int a[200010];
bool vis[200010];
int find(int x){
	return fa[x]==x?x:fa[x]=find(fa[x]);
}
int main(){
	T=read();
	for(int o=1;o<=T;++o){
		n=read();
		for(int i=1;i<=n;++i) a[i]=cnt[i]=0,lst[i]=-1;
		for(int i=1;i<=n;++i) a[i]=read(),++cnt[a[i]];
		for(int i=1;i<=n;++i) vis[i]=0,fa[i]=i;
		bool fl=0;
		bool fail=0;
		for(int i=1;i<=n;++i){
			if(cnt[i]&1){
				if(n&1){
					// if(i==(n+i>>1)) fail=1;
					if(fl) fail=1;fl=1;
				}
				else fail=1;
			}
		}
		// printf("%d %d\n",fl,fail);
		int tc=0;
		bool ok=0;
		for(int i=1;i<=n;++i){
			if((cnt[a[i]]&1)&&(i!=(n+1>>1))&&!ok){
				// printf("i:%d\n",i);
				ok=1;p[n+1>>1]=i;--cnt[a[i]];
			}
			else{
				if(lst[a[i]]==-1) p[++tc]=i,lst[a[i]]=tc;
				else p[n-lst[a[i]]+1]=i,lst[a[i]]=-1;
			}
		}
		if(fail||(fl&&!ok)) {
			puts("NO");
			continue ;
		}
		for(int i=1;i<=n;++i) if(!vis[i]){
			int po=p[i];
			while(po!=i){
				vis[po]=1;
				fa[po]=i;po=p[po];
			}
			vis[i]=1;
		}
		for(int i=1;i<n-i+1;++i){
			if(find(i)!=find(n-i+1)){
				int fx=find(i),fy=find(n-i+1);
				fa[fx]=fy;swap(p[i],p[n-i+1]);
			}
		}
		for(int i=1;i<n-i+1;++i) if(find(i)!=find(i+1)){
			fa[find(i)]=find(i+1);
			int a1=p[i],a2=p[n-i+1],b1=p[i+1],b2=p[n-i];
			p[i]=b2,p[n-i+1]=b1,p[i+1]=a1,p[n-i]=a2;
		}
		// if(T==30000){
		// 	if(o==470){
		// 		printf("%d\n",n);for(int i=1;i<=n;++i) printf("%d ",a[i]);printf("\n");
		// 	}
		// 	continue ;
		// }
		printf("YES\n");
		for(int i=1;i<=n;++i) printf("%d ",p[i]);printf("\n");
	}
}