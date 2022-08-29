#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<map>
#include<set>
#include<string>
#include<vector>
#include<assert.h>
#define pb push_back
#define rep(i,j,k) for(int i=(j);i<=(int)k;i++)
#define per(i,j,k) for(int i=(j);i>=(int)k;i--)
#define lowbit(x) ((x)&(-(x)))
#define fi first
#define se second
#define pii pair<int,int>
#define VI vector<int>
#define S(x) x.size()
using namespace std;
typedef long long LL;
typedef double db;
int m;
const int N=110000;
const int P=1000000009;
int x[N],y[N];vector<int>p[N];
set<int>q;
map<pii,int>mp;
int cnt(int xx,int yy){
	int p=0;
	for(int i=-1;i<=1;i++)p+=(mp[pii(xx+i,yy-1)]>0);
	return p;
}
void lahui(int xx,int yy){
	if(cnt(xx,yy)==1){
		for(int i=-1;i<=1;i++)if(mp[pii(xx+i,yy-1)]){
			if(q.find(mp[pii(xx+i,yy-1)])!=q.end())q.erase(mp[pii(xx+i,yy-1)]);
		}
	}
}
void tp(int xx,int yy){
	if(q.find(mp[pii(xx,yy)])!=q.end())return;
	for(int i=-1;i<=1;i++)if(mp[pii(xx+i,yy+1)])if(cnt(xx+i,yy+1)==1)return;
	q.insert(mp[pii(xx,yy)]);
}
void del(int ni){
	int xx=x[ni];
	int yy=y[ni];
	mp[pii(xx,yy)]=0;
	
	for(int i=-1;i<=1;i++)if(mp[pii(xx+i,yy+1)])lahui(xx+i,yy+1);
	for(int i=-1;i<=1;i++)if(mp[pii(xx+i,yy-1)])tp(xx+i,yy-1);
}
int main(){
	scanf("%d",&m);
	rep(i,1,m){
		scanf("%d%d",&x[i],&y[i]);
		mp[pii(x[i],y[i])]=i;
	}
	
	rep(i,1,m){
		bool fl=1;
		for(int j=-1;j<=1;j++)if(mp[pii(x[i]+j,y[i]+1)])if(cnt(x[i]+j,y[i]+1)==1)fl=0;
		if(fl)q.insert(i);
	//	printf("_%d %d\n",fl,i);
	}
	
	int ans=0;
	
	rep(i,1,m){
		//printf("%d %d\n",*q.begin(),q.size());
		ans=ans*1ll*m%P;
		if(i&1){
			int u=*(--q.end());
			q.erase(u);
			del(u);
			ans=(ans+u-1)%P;
		}
		else{
			int u=*(q.begin());
			q.erase(u);
			del(u);
			ans=(ans+u-1)%P;
		}
	}
	printf("%d\n",ans);
	return 0;
}