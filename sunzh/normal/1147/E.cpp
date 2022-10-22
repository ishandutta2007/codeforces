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
bool eq[100010];
PII a[100010];
int cnt;int col[100010];
vector<int>ans[3];
char str[100010];
bool pr[100010];
int main(){
	T=read();
	while(T--){
		n=read();
		if(n==1){
			printf("A 1 0 0\n1\n\n\n");fflush(stdout);continue ;
		}
		for(int i=0;i<3;++i) vector<int>().swap(ans[i]);
		printf("Q %d ",n>>1);
		for(int i=1;i<n;i+=2) printf("%d %d ",i,i+1);printf("\n");fflush(stdout);
		scanf("%s",str+1);
		for(int i=1;i<n;i+=2) eq[i]=str[i+1>>1]-'0';
		if(n-1>>1){
			printf("Q %d ",n-1>>1);
			for(int i=2;i<n;i+=2) printf("%d %d ",i,i+1);printf("\n");fflush(stdout);
			scanf("%s",str+1);
			for(int i=2;i<n;i+=2) eq[i]=str[i>>1]-'0';
		}cnt=0;
		for(int i=1;i<=n;++i){
			int j=i;while(j<n&&eq[j]) ++j;
			a[++cnt]=mp(i,j);i=j;
		}
		if(cnt>=3){
			vector<PII>ve;
			for(int i=3;i<=cnt;i+=4){
				ve.pb(mp(i-2,i));if(i+1<=cnt) ve.pb(mp(i-1,i+1));
			}
			printf("Q %d ",ve.size());
			for(PII i:ve) printf("%d %d ",a[i.fi].fi,a[i.se].fi);printf("\n");fflush(stdout);
			scanf("%s",str+1);
			for(int i=0;i<ve.size();++i) pr[ve[i].se]=str[i+1]-'0';
		}
		if(cnt>=5){
			vector<PII>ve;
			for(int i=5;i<=cnt;i+=4){
				ve.pb(mp(i-2,i));if(i+1<=cnt) ve.pb(mp(i-1,i+1));
			}
			printf("Q %d ",ve.size());
			for(PII i:ve) printf("%d %d ",a[i.fi].fi,a[i.se].fi);printf("\n");fflush(stdout);
			scanf("%s",str+1);
			for(int i=0;i<ve.size();++i) pr[ve[i].se]=str[i+1]-'0';
		}
		col[1]=0;col[2]=1;
		for(int i=3;i<=cnt;++i){
			if(pr[i]) col[i]=col[i-2];else{
				bool vis[3]={0,0,0};vis[col[i-2]]=vis[col[i-1]]=1;
				for(int j=0;j<3;++j) if(!vis[j]) col[i]=j;
			}
		}
		for(int i=1;i<=cnt;++i){
			for(int j=a[i].fi;j<=a[i].se;++j) ans[col[i]].pb(j);
		}
		printf("A %d %d %d\n",ans[0].size(),ans[1].size(),ans[2].size());
		for(int i=0;i<3;++i){
			for(int j:ans[i]) printf("%d " ,j);printf("\n");
		}fflush(stdout);
	}
}