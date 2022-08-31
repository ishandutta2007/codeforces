#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<map>
#include<vector>
#define pb push_back
#define rep(i,j,k) for(int i=(j);i<=(int)k;i++)
#define per(i,j,k) for(int i=(j);i>=(int)k;i--)
#define lowbit(x) ((x)&(-(x)))
#define fi first
#define se second
#define pii pair<int,int>
#define pll pair<LL,LL>
using namespace std;
typedef long long LL;
typedef double db;
LL Pow[21];
map<pll,pll>mp;
pll work(LL ma,LL n){
	if(!ma&&!n)return pll(0,0);
	if(n<10)return pll(1,n-max(ma,n));
	pll ok=pll(ma,n);
	if(mp.find(ok)!=mp.end())return mp[ok];
	LL ans=0;
	LL x=n;int p=0;
	while(x>=10)x/=10,p++;
	for(;x>=0;x--){
		pll rp=work(max(ma,x),n-x*Pow[p]);
		ans+=rp.fi;n=x*Pow[p]+rp.se;
		if(rp.se==0&&x){
			n-=max(ma,x);
			ans++;
		}
	}
	return mp[ok]=pll(ans,n);
}
int main(){
	LL n;scanf("%I64d",&n);
	Pow[0]=1;rep(i,1,20)Pow[i]=Pow[i-1]*10ll;
	printf("%I64d\n",work(0,n).fi);
	return 0;
}