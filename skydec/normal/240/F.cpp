#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<map>
#include<vector>
#define rep(i,j,k) for(int i=j;i<=k;i++)
#define per(i,j,k) for(int i=j;i>=k;i--)
#define lowbit(x) ((x)&(-(x)))
using namespace std;
#define MAXN 110000
int c[MAXN*4][26];int lazy[MAXN*4];int len[MAXN*4];
int n,m;int cnt[26];
void down(int x){
	if(lazy[x]==-1)return;
	lazy[x*2]=lazy[x*2+1]=lazy[x];
	rep(i,0,25)c[x*2][i]=c[x*2+1][i]=0;
	c[x*2][lazy[x*2]]=len[x*2];
	c[x*2+1][lazy[x*2+1]]=len[x*2+1];
	lazy[x]=-1;
}
void build(int now,int l,int r){
	if(l==r){len[now]=1;return;}
	int mid=(l+r)>>1;
	build(now*2,l,mid);
	build(now*2+1,mid+1,r);
	len[now]=len[now*2]+len[now*2+1];
}
void cover(int now,int l,int r,int x,int y,int v){
	if(l!=r)down(now);
	if(x<=l&&r<=y){
		rep(i,0,25)c[now][i]=0;
		c[now][v]=len[now];
		lazy[now]=v;
		return;
	}
	int mid=(l+r)>>1;
	if(x<=mid)cover(now*2,l,mid,x,y,v);
	if(y>mid)cover(now*2+1,mid+1,r,x,y,v);
	rep(i,0,25)c[now][i]=c[now*2][i]+c[now*2+1][i];
}
void calc(int now,int l,int r,int x,int y){
	if(l!=r)down(now);
	if(x<=l&&r<=y){
		rep(i,0,25)cnt[i]+=c[now][i];
		return;
	}
	int mid=(l+r)>>1;
	if(x<=mid)calc(now*2,l,mid,x,y);
	if(y>mid)calc(now*2+1,mid+1,r,x,y);
}
int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	scanf("%d%d",&n,&m);build(1,1,n);
	memset(lazy,-1,sizeof lazy);
	rep(i,1,n){
		char p=getchar();
		while(!(p<='z'&&p>='a'))p=getchar();
		cover(1,1,n,i,i,p-'a');
	}
	rep(kk,1,m){
		int l,r;scanf("%d%d",&l,&r);
		memset(cnt,0,sizeof cnt);
		calc(1,1,n,l,r);
		int u=0;rep(i,0,25)if(cnt[i]&1)u++;
		if(u>1)continue;
		if((r-l+1)&1){
			rep(i,0,25)if(cnt[i]&1)u=i;
			cover(1,1,n,(l+r)/2,(l+r)/2,u);
			cnt[u]--;
			rep(i,0,25)if(cnt[i]){
				cnt[i]/=2;
				cover(1,1,n,l,l+cnt[i]-1,i);
				cover(1,1,n,r-cnt[i]+1,r,i);
				l+=cnt[i];
				r-=cnt[i];
			}
		}
		else
		{
			rep(i,0,25)if(cnt[i]){
				cnt[i]/=2;
				cover(1,1,n,l,l+cnt[i]-1,i);
				cover(1,1,n,r-cnt[i]+1,r,i);
				l+=cnt[i];
				r-=cnt[i];
			}
		}
	}
	rep(i,1,n){
		memset(cnt,0,sizeof cnt);
		calc(1,1,n,i,i);
		rep(j,0,25)if(cnt[j]){
			printf("%c",j+'a');
			break;
		}
	}
	return 0;
}