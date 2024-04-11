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
int n,m;
char a[52][21];
LL can[1<<20];
int cnt[1<<20];
int f[22];
int calc(LL x){
	return cnt[x&((1<<20)-1)]+cnt[(x>>20)&((1<<20)-1)]+cnt[(x>>40)&((1<<20)-1)];
}
db g[22];
int main(){
	scanf("%d",&n);
	rep(i,1,n)scanf("%s",a[i]+1);m=strlen(a[1]+1);
	
	rep(i,1,n)rep(j,1,n)if(i^j){
		int b=0;
		rep(k,1,m)if(a[i][k]==a[j][k])b|=(1<<(k-1));
		can[b]|=(1ll<<(i-1));
	}
	
	rep(i,1,(1<<20)-1)cnt[i]=cnt[i/2]+(i&1);
	
	per(i,(1<<m)-1,0)rep(j,1,m)if(i&(1<<(j-1)))can[i^(1<<(j-1))]|=can[i];
	
	rep(i,0,(1<<m)-1){
		rep(j,1,m)if(i&(1<<(j-1))){
			LL need=can[i^(1<<(j-1))]&((1ll<<n)-1-can[i]);
			if(!need)continue;
			f[cnt[i^(1<<(j-1))]]+=calc(need);
		}
	}
	
	db ans=0;
	rep(i,0,m-1){
		db ret=1;
		rep(j,1,i){ret*=(i-j+1);ret/=(m-j+1);}
		ret/=((m-i)*1.);
		
		ans+=ret*(i+1)*f[i];
	}
	
	printf("%.13lf\n",ans/n);
	return 0;
}