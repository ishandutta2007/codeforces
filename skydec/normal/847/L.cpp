#include<bits/stdc++.h>
#define pii pair<int,int>
#define fi first
#define se second
#define rep(i,j,k) for(int i=(int)j;i<=(int)k;i++)
#define per(i,j,k) for(int i=(int)j;i>=(int)k;i--)
using namespace std;
typedef long long LL;
const int N=1005;
int kd[N][N];
int num[N][N];
int dj[N];
int n;
char str[N*100];
int q[N*10];
bool vis[N];

pii ans[N];
int m;
int main(){
	scanf("%d",&n);
	rep(x,1,n){
		scanf("%s",str+1);
		int len=strlen(str+1);
		int now=0;
		q[0]=0;
		rep(i,1,len)if(str[i]<='9'&&str[i]>='0'){
			now=now*10+(str[i]-'0');
		}
		else{
			q[++q[0]]=now;
			now=0;
		}
		q[++q[0]]=now;
		int mm=0;
		for(int i=1;i<=q[0];i++){
			int xx=q[i];
			++mm;
			num[x][mm]=xx;
			rep(j,i+1,i+xx){
				kd[x][q[j]]=mm;
			}
			i=i+xx;
		}
		dj[x]=mm;
	}
	rep(round,1,n){
		int x=0;
		rep(i,1,n)if(!vis[i])if((dj[i]==1)||(dj[i]==0&&round==n))x=i;
		if(!x){
			puts("-1");
			return 0;
		}
		if(round==n)continue;
		vis[x]=1;
		int y=0;
		//printf("%d\n",x);
		rep(i,1,n)if(!vis[i])if(kd[i][x]){
			num[i][kd[i][x]]--;
			//printf("%d %d %d\n",i,kd[i][x],num[i][kd[i][x]]);
			if(!num[i][kd[i][x]]){
				dj[i]--;
				if(y){
					puts("-1");
					return 0;
				}
				y=i;
			}
		}
		if(!y){
			puts("-1");
			return 0;
		}
		ans[++m]=pii(x,y);
	}
	printf("%d\n",m);
	rep(i,1,m)printf("%d %d\n",ans[i].fi,ans[i].se);
	return 0;
}