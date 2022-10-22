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
#define pb push_back
#define vc vector<int>
int T,n,m;
int a[MN],id[MN],b[MN];
vector<int>pos[MN];
bool cmp(int a,int b){return pos[a].size()<pos[b].size();}
signed main(){
	T=read();
	while(T--){
		n=read();
		for(int i=1;i<=n;++i)pos[i].clear();
		for(int i=1;i<=n;++i){
			b[i]=a[i]=read();
			pos[a[i]].push_back(i);
			id[i]=i;
		}	
		sort(id+1,id+1+n,cmp);
		int lst=0;
		for(int i=1;i<=n;++i){
			int o=id[i];
			while(pos[o].size()){
				vc w(0);
				for(int j=i;j<=n;++j){
					w.pb(pos[id[j]].back());
					pos[id[j]].pop_back();
				}
				for(int j=0;j<w.size();++j)
					b[w[j]]=a[w[(j+1)%w.size()]];
			}
		}
		for(int i=1;i<=n;++i)printf("%lld ",b[i]);
		puts("");
	}
	return 0;
}