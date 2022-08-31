#include<bits/stdc++.h>
#define fi first
#define se second
#define pii pair<int,int>
#define rep(i,j,k) for(int i=(int)j;i<=(int)k;i++)
#define per(i,j,k) for(int i=(int)j;i>=(int)k;i--)
using namespace std;
typedef long long LL;
const int N=310000;
int k,n,c[N];
set<pii> dj;
int tt[N];
int main(){
	scanf("%d%d",&n,&k);
	rep(i,1,n)scanf("%d",&c[i]);
	rep(i,1,k)dj.insert(pii(-c[i],i));
	LL ans=0;
	rep(i,k+1,k+n){
		if(i<=n)dj.insert(pii(-c[i],i));
		pii gt=*dj.begin();
		dj.erase(dj.begin());
		tt[gt.se]=i;
		ans+=(i-gt.se)*1ll*(-gt.fi);
	}
	printf("%I64d\n",ans);
	rep(i,1,n)printf("%d ",tt[i]);
	return 0;
}