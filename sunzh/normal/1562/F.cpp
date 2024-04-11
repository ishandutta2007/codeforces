#include<iostream>
#include<cstdio>
#include<algorithm>
#include<set>
#include<vector>
#include<ctime>
#include<cstring>
#include<map>
#include<cmath>
#include<random>
#include<chrono>
#include<cassert>
#include<queue>
#define mp make_pair
#define PII pair<int,int>
#define fi first
#define se second
#define pb push_back
#define int long long
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c)){x=(x<<3)+(x<<1)+(c^48);c=getchar();}
	return f==-1?~x+1:x;
}
// auto random_addr/EED = chrono::steady_clock::now().time_since_epoch().count() * (random_address() | 1);
mt19937 rnd(time(0));
int f[110][110];
int p[200010];
int ask(int i,int j){
	printf("? %d %d\n",i,j);fflush(stdout);
	int x=read();return x;
}
int ans[200010];
signed main(){
	int T=read();
	for(int i=2;i<=200000;++i){
		if(!p[i]){
			p[i]=i;
			for(int j=2;j*i<=200000;++j) if(!p[i*j]) p[i*j]=i;
		}
	}
	while(T--){
		int n=read();
		if(n<100){
			for(int i=1;i<=n;++i){
				for(int j=i+1;j<=n;++j) f[i][j]=f[j][i]=ask(i,j);
			}
			for(int i=1;i<=n;++i){
				int x=(i==1?f[i][2]:f[i][1]);
				for(int j=1;j<=n;++j){
					if(i!=j) x=__gcd(x,f[i][j]);
				}
				ans[i]=x;
				// printf("%d%c",x," \n"[i==n]);
			}
			if(n==3){
				if((~ans[1]&1)&&(~ans[2]&1)&&(~ans[3]&1)){
					
					vector<PII>tmp={mp(ans[1],1),mp(ans[2],2),mp(ans[3],3)};
					sort(tmp.begin(),tmp.end());
					ans[tmp[2].se]>>=1;
				}
			}
			printf("! ");
			for(int i=1;i<=n;++i){
				printf("%d%c",ans[i]," \n"[i==n]);
			}
			fflush(stdout);
		}
		else{
			int t=250;
			int mx=0,ps=0;
			while(t--){
				int x=rnd()%n+1;
				int g=-1;
				for(int i=1;i<=20;++i){
					int y=rnd()%n+1;while(y==x) y=rnd()%n+1;
					if(g==-1) g=ask(x,y);
					else g=__gcd(g,ask(x,y));
				}
				if(p[g]==g){
					if(mx<g) mx=g,ps=x;
				}
			}
			if(mx==0){
				exit(2);
			}
			for(int i=1;i<=n;++i){
				if(i==ps) ans[i]=mx;
				else ans[i]=ask(i,ps)/mx;
			}
			// assert(mx!=0);
			printf("! ");
			for(int i=1;i<=n;++i) printf("%d%c",ans[i]," \n"[i==n]);fflush(stdout);
		}
	}
}