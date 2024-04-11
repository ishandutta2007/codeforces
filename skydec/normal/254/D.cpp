#include<stdio.h>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<map>
#include<vector>
#include<cmath>
#define pb push_back
#define rep(i,j,k) for(int i=j;i<=k;i++)
#define per(i,j,k) for(int i=j;i>=k;i--)
#define Rep(i,j,k) for(int i=j;i<k;i++)
#define fi first
#define se second
#define pii pair<int,int>
using namespace std;
typedef long long LL;
typedef double db;
vector<pii>go[305];
vector<pii>tmp;
pii jb[305];
int n,m,d;int rat;
char a[1005][1005];int cho;
bool gor[305];
int dx[5]={0,0,0,1,-1};
int dy[5]={0,1,-1,0,0};
int Time[1005][1005];
inline bool hf(pii x,int k){
	if(x.fi+dx[k]<1||x.fi+dx[k]>n)return 0;
	if(x.se+dy[k]<1||x.se+dy[k]>m)return 0;
	if(a[x.fi+dx[k]][x.se+dy[k]]=='X')return 0;
	if(Time[x.fi+dx[k]][x.se+dy[k]]==cho)return 0;
	return 1;
}
void dfs(pii x,int dep){
	tmp.pb(x);Time[x.fi][x.se]=cho;int last=0;
	rep(i,0,d-1){
		int now=tmp.size();
		Rep(j,last,now){
			pii u=tmp[j];
			rep(k,1,4)if(hf(u,k)){
				tmp.pb((pii){u.fi+dx[k],u.se+dy[k]});
				Time[u.fi+dx[k]][u.se+dy[k]]=cho;
				}
			}
		last=now;
		}
}
int main(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	scanf("%d%d%d",&n,&m,&d);
	rep(i,1,n)scanf("%s",a[i]+1);
	rep(i,1,n)rep(j,1,m)if(a[i][j]=='R'){
		jb[++rat]=(pii){i,j};
		tmp.clear();cho++;
		dfs(jb[rat],0);
		go[rat]=tmp;
		if(rat>300)goto pyc1;
	}
	pyc1:;
	if(rat>300){
		printf("-1");
		return 0;
		}
	//printf("%d\n",go[1].size());
	Rep(iss,0,go[1].size()){
		//watch=0;
		pii u=go[1][iss];cho++;
		//if(u.fi==2&&u.se==3)watch=1;
		//printf("%d %d\n",u.fi,u.se);
		memset(gor,0,sizeof gor);
		tmp.clear();dfs(u,0);
		rep(j,1,rat)if(Time[jb[j].fi][jb[j].se]==cho)gor[j]=1;
		int j=1;
		while(j<=rat&&Time[jb[j].fi][jb[j].se]==cho)j++;
		if(j>rat){
			int x,y;x=0;y=0;
			rep(i,1,n)rep(k,1,m)if((!(i==u.fi&&k==u.se))&&a[i][k]!='X'){
				x=i;y=k;
				goto pyc;
				}
			pyc:;
			printf("%d %d %d %d\n",u.fi,u.se,x,y);
			return 0;
			}
		//if(watch)printf("%d\n",j);
		//printf("%d %d\n",iss,j);
		Rep(ip,0,go[j].size()){
			cho++;tmp.clear();dfs(go[j][ip],0);
			//if(watch&&go[j][ip].fi==6&&go[j][ip].se==9){
			//	Rep(k,0,tmp.size())printf("_%d %d\n",tmp[k].fi,tmp[k].se);
			//	}
			bool f=1;
			rep(k,1,rat)f&=((Time[jb[k].fi][jb[k].se]==cho)||(gor[k]));
			if(f){
				printf("%d %d %d %d\n",u.fi,u.se,go[j][ip].fi,go[j][ip].se);
				return 0;
				}
			}
		}
	printf("-1\n");
	return 0;
}