#include<iostream>
#include<cstdio>
#include<algorithm>
#include<set>
#include<vector>
#include<ctime>
#include<cstring>
#include<map>
#include<queue>
#define mp make_pair
#define PII pair<int,int>
#define fi first
#define se second
#define int long long
#define pb push_back
using namespace std;
inline int read(){
	int x=0,f=1;
	char c=getchar();
	while(!isdigit(c)){if(c=='-') f=-1;c=getchar();}
	while(isdigit(c)){x=(x<<3)+(x<<1)+(c^48);c=getchar();}
	return f==1?x:~x+1;
}
typedef pair<int,pair<int,int> >ppii;
int T;
int n,m;
int b[110][110],ans[110][110];
bool vis[110][110];
signed main(){
	T=read();
	while(T--){
		n=read(),m=read();
		for(int i=1;i<=n;++i){
			for(int j=1;j<=m;++j) b[i][j]=read(),vis[i][j]=0,ans[i][j]=-1;
		}
		priority_queue<ppii,vector<ppii>,greater<ppii> >Q;
		for(int i=1;i<=n;++i) {
			for(int j=1;j<=m;++j){
				Q.push(mp(b[i][j],mp(i,j)));
			}
		}
		for(int i=1;i<=m;++i){
			ppii a=Q.top();Q.pop();
			ans[a.se.fi][i]=a.fi;
//			printf("%d i:%d j:%d\n",a.fi,a.se.fi,a.se.se);
			vis[a.se.fi][a.se.se]=1;
		}
		for(int i=1;i<=n;++i){
			for(int j=1;j<=m;++j){
				if(ans[i][j]==-1){
					for(int k=1;k<=m;++k){
//						printf("i:%d,j:%d,k:%d\n",i,j,k);
						if(!vis[i][k]){
							vis[i][k]=1;ans[i][j]=b[i][k];break ;
						}
					}
				}
				printf("%d ",ans[i][j]);
			}
			printf("\n");
		}
	}
}