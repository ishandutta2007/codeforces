#include<bits/stdc++.h>
using namespace std;
#define int long long
int read(){
	int a=0,fh=1;char c=getchar();
	while(c>'9'||c<'0'){if(c=='-')fh=-1;c=getchar();}
	while('0'<=c&&c<='9'){
		a=a*10+c-48;
		c=getchar();
	}
	return a*fh;
}
#define MN 200005
#define pii pair<int,int>
#define mp make_pair
#define x first
#define y second
int T,n,m;
int a[MN],id[MN];
bool cmp(int x,int y){
	return a[x]<a[y];
}
char ch[MN];
vector<int>edge[MN];
signed main(){
	T=read();
	while(T--){
		n=read();
		int ans=0;
		for(int i=1;i<=n;++i){
			a[i]=read();
			ans+=a[i];
		}
		for(int i=1;i<=n;++i)edge[i].clear();
		for(int i=1;i<n;++i){
			int u=read(),v=read();
			edge[u].push_back(v);
			edge[v].push_back(u);
		}
		for(int i=1;i<=n;++i)id[i]=i;
		sort(id+1,id+1+n,cmp);
		printf("%lld ",ans);
		int now=1;
		for(int i=n;i;--i){
//			cerr<<"? "<<i<<" "<<id[i]<<" "<<edge[id[i]].size()<<endl;
			if(edge[id[i]].size()>1){
				edge[id[i]].pop_back();
				now++;
				ans+=a[id[i]];
				printf("%lld ",ans);
				i++;
			}
		}
		for(int i=now+1;i<n;++i)printf("%lld ",ans);
		puts("");
	}
	return 0;
}