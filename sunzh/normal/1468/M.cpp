#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstring>
#include<queue>
#include<map>
#include<set>
#include<random>
#include<ctime>
#define ep emplace_back
#define PII pair<int,int>
#define pb push_back
#define fi first
#define se second
#define mp make_pair
using namespace std;
inline int read(){
	int x=0,f=1;
	char c=getchar();
	while(!isdigit(c)){if(c=='-') f=-1; c=getchar();}
	while(isdigit(c)){x=(x<<3)+(x<<1)+(c^48);c=getchar();}
	return f==1?x:~x+1;
}
int T;
int n;
int K[200010];
vector<int>a[200010];
int s[200010];
int m;
int w[200010];
vector<PII>vec[200010];
int main(){
	T=read();
	while(T--){
		n=read();
		m=0;
		for(int i=1;i<=n;++i){
			K[i]=read();
			for(int j=1;j<=K[i];++j){
				int x=read();a[i].pb(x);
				s[++m]=x;
			}
		}
		sort(s+1,s+m+1);
		int B=260;
		m=unique(s+1,s+m+1)-s-1;
		for(int i=1;i<=n;++i){
			sort(a[i].begin(),a[i].end());
			unique(a[i].begin(),a[i].end());
			K[i]=a[i].size();
		}
		for(int i=1;i<=n;++i){
			for(int j=1;j<=K[i];++j) a[i][j-1]=lower_bound(s+1,s+m+1,a[i][j-1])-s; 
		}
		for(int i=1;i<=n;++i){
			if(K[i]>=B){
				bool g=0;
				for(int j=1;j<=K[i];++j) w[a[i][j-1]]=1;
				for(int j=1;j<=n;++j){
					if(j==i) continue ;
					if(i<j&&K[j]>=B) continue ;
					int c=0;
					for(int k=1;k<=K[j];++k){
						if(w[a[j][k-1]]){
							++c;if(c>=2) break ;
						}
					}
					if(c>=2){
						printf("%d %d\n",i,j);g=1;break ;
					}
				}
				for(int j=1;j<=K[i];++j) w[a[i][j-1]]=0;
				if(g) goto nxt;
				continue ;
			}
		}
		for(int i=1;i<=n;++i){
			if(K[i]<B){
				for(int j=1;j<=K[i];++j){
					for(int k=j+1;k<=K[i];++k){
						if(k==j) continue ;
						vec[a[i][j-1]].ep(a[i][k-1],i);
					}
				}
			}
		}
		for(int i=1;i<=m;++i){
			PII ans=mp(-1,-1);
			for(auto j:vec[i]){
				if(w[j.fi]){
					ans=mp(w[j.fi],j.se);
					break ;
				}
				else w[j.fi]=j.se;
			}
			for(auto j:vec[i]) w[j.fi]=0;
			if(ans.fi!=-1){
				printf("%d %d\n",ans.fi,ans.se);goto nxt;
			}
		}
		printf("-1\n");
		nxt:;
		for(int i=1;i<=m;++i){
			vec[i].clear();
		}
		for(int i=1;i<=n;++i){
			a[i].clear();
		}
	}
	return 0;
}