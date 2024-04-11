#include<bits/stdc++.h>
#define pii pair<int,int>
#define fi first
#define se second
#define rep(i,j,k) for(int i=(int)j;i<=(int)k;i++)
#define per(i,j,k) for(int i=(int)j;i>=(int)k;i--)
using namespace std;
typedef long long LL;
const int N=110000;
LL pr[N];
int prv[N];
LL sf[N];
int sfv[N];
int n,a[N];
int main(){
	scanf("%d",&n);
	rep(i,1,n)scanf("%d",&a[i]);
	rep(i,1,n){
		pr[i]=pr[i-1];
		prv[i]=max(a[i],prv[i-1]+1);
		pr[i]+=prv[i]-a[i];
	}
	per(i,n,1){
		sf[i]=sf[i+1];
		sfv[i]=max(a[i],sfv[i+1]+1);
		sf[i]+=sfv[i]-a[i];
	}
	LL ans=1ll<<60;
	rep(i,1,n){
		LL res=sf[i]+pr[i]-(prv[i]-a[i])-(sfv[i]-a[i]);
		res+=max(prv[i],sfv[i])-a[i];
		if(res<ans)ans=res;
	}
	cout<<ans<<endl;
	return 0;
}