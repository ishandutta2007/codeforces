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
int n,q;
int a[200010];
int fa[200010];
int f[1000010];
const int M=1000001;
void getf(){
	for(int i=2;i<=M;++i){
		if(!f[i]){
			f[i]=i;for(int j=2;j*i<=M;++j) if(!f[i*j]) f[i*j]=i;
		}
	}
}
vector<int>vec[1000010];
int find(int x){
	return fa[x]==x?x:fa[x]=find(fa[x]);
}
set<PII>st;
int main(){
	n=read(),q=read();
	for(int i=1;i<=n;++i) a[i]=read(),fa[i]=i;
	getf();
	for(int i=1;i<=n;++i){
		int x=a[i];
		while(x!=1){
			vec[f[x]].pb(i);
			// printf("i:%d,f:%d\n",i,f[x]);
			int t=f[x];while(x%t==0) x/=t;
		}
	}
	for(int i=2;i<=M;++i){
		if(f[i]==i&&vec[i].size()){
			int t=vec[i][0];
			for(int j:vec[i]) if(find(j)!=find(t)) fa[find(j)]=find(t);
		}
	}
	for(int i=1;i<=n;++i){
		int x=a[i]+1;
		vector<int>A;
		while(x!=1){
			// vec[f[x]].pb(i);
			int t=f[x];while(x%t==0) x/=t;
			// printf("i:%d,t:%d\n",i,t);
			if(vec[t].size()){
				int F=find(vec[t][0]);
				A.pb(F);
			}
		}
		A.pb(find(i));
		sort(A.begin(),A.end());auto it=unique(A.begin(),A.end());
		for(auto j=A.begin();j!=it;++j){
			for(auto k=A.begin();k!=it;++k){
				st.insert(mp(*j,*k));
			}
		}
	}
	while(q--){
		int s=read(),t=read();
		s=find(s),t=find(t);
		if(s==t) printf("0\n");
		else if(st.count(mp(s,t))) printf("1\n");else printf("2\n");
	}
}