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
const int N=410000;
const int base=9999997;
const int P=1000000007;
int n,m;
char a[N],b[N];
int s[N],t[N];
int pre[N];
int po[N];
int tmp[N];
int rank[N];
int key[N];
int now;
int pi[37];
int rc1[37];
int rc2[37];
vector<int>lu;
int main(){
	scanf("%d%d",&n,&m);
	scanf("%s",a+1);
	scanf("%s",b+1);
	rep(i,1,n)s[i]=a[i]-'a'+1;
	rep(i,1,m)t[i]=b[i]-'a'+1;
	int top=0;
	rep(i,1,m){
		if(tmp[t[i]])t[i]=tmp[t[i]];
		else{
			tmp[t[i]]=++top;rc1[top]=t[i];
			t[i]=top;
		}
	}
	int std=0;
	per(i,m,1){
		std=std*1ll*base%P;
		std=(std+t[i])%P;
	}
	po[0]=1;
	rep(i,1,n+5)po[i]=po[i-1]*1ll*base%P;
	
	now=0;
	per(i,n,1){
		int v=s[i];
		int u=s[i+m];
		rep(j,1,26)if(j^v)if(pre[j])if(rank[j])if(pre[j]<=pre[v]||pre[v]==0){
			now=(now+key[j])%P;rank[j]++;
		}
		now=(now-key[v]*1ll*(rank[v]-1))%P;rank[v]=1;
		now=now*1ll*base%P;
		rep(j,1,26)key[j]=key[j]*1ll*base%P;
		
		key[v]=(key[v]+1)%P;now=(now+1)%P;
		pre[v]=i;
		if(i+m<=n){
			key[u]=(key[u]-po[m])%P;
			now=(now-(po[m]*1ll*rank[u]))%P;
			if(pre[u]==i+m){
				pre[u]=0;
				rank[u]=0;
			}
		}
		rep(j,1,26)rc2[j]=0;
		rep(j,1,26)rc2[rank[j]]=j;
		rep(j,1,26)pi[j]=0;
		if(now<0)now+=P;
		if(i+m-1<=n&&std==now){
			int kd=0;
			rep(j,1,26)if(pre[j]<=i+m-1&&pre[j]>=i){kd++;}
			bool fl=1;
			if(kd!=top)fl=0;
			rep(j,1,26)if(rc1[j]){
				if(pi[rc1[j]]&&pi[rc1[j]]!=rc2[j])fl=0;
				pi[rc1[j]]=rc2[j];
				if(pi[rc2[j]]&&pi[rc2[j]]!=rc1[j])fl=0;
				pi[rc2[j]]=rc1[j];
			}
			if(fl)lu.pb(i);
		}
	}
	printf("%d\n",(int)lu.size());
	per(i,lu.size()-1,0)printf("%d ",lu[i]);
	return 0;
}