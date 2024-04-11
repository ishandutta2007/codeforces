#include<bits/stdc++.h>
#define fi first
#define se second
#define pii pair<int,int>
#define rep(i,j,k) for(int i=(int)j;i<=(int)k;i++)
#define per(i,j,k) for(int i=(int)j;i>=(int)k;i--)
using namespace std;
typedef long long LL;
const int N=(1<<17);
int f[N];
int tmp[1000000];
int a[105];
int n;
pii d[105*105];
int m;
map<int,int>mp;
int getsg(int x){
	if(x<N)return f[x];
	if(mp.find(x)!=mp.end())return mp[x];
	map<int,bool>cg;
	cg.clear();
	rep(i,1,30)if((1<<(i-1))<=x){
		int w=0;
		rep(k,1,30)if(k>=i){
			if(x&(1<<(k-1)))if(k>i)w|=(1<<(k-i-1));
		}
		else if(x&(1<<(k-1)))w|=(1<<(k-1));
		cg[getsg(w)]=1;
	}
	int ans=0;
	while(cg[ans])++ans;
	return mp[x]=ans;
}
int main(){
	rep(i,1,N-1){
		rep(j,1,17)if((1<<(j-1))<=i){
			int w=0;
			rep(k,1,17)if(k>=j){
				if(i&(1<<(k-1)))if(k>j)w|=(1<<(k-j-1));
			}
			else if(i&(1<<(k-1)))w|=(1<<(k-1));
			tmp[f[w]]=i;
		}
		while(tmp[f[i]]==i)++f[i];
	}
	scanf("%d",&n);
	rep(i,1,n){
		scanf("%d",&a[i]);
		int x=a[i];
		for(int j=2;j*j<=x;j++)if(x%j==0){
			int w=0;
			while(x%j==0){x/=j;w++;}
			d[++m]=pii(j,w);
		}
		if(x>1)d[++m]=pii(x,1);
	}
	sort(d+1,d+1+m);
	int sg=0;
	rep(l,1,m){
		int r=l;
		while(r<m&&d[r+1].fi==d[l].fi)++r;
		int w=0;
		rep(i,l,r)w|=(1<<(d[i].se-1));
		l=r;
		sg^=getsg(w);
	}
	if(sg)puts("Mojtaba");
	else puts("Arpa");
	return 0;
}