#include<bits/stdc++.h>
#define fi first
#define se second 
#define mp make_pair
using namespace std;
int q,n,a[300030],ans,dp[300030],ma,last;//,tr[300030];
pair<int,int> f[300030];
/*int low(int x){return x&(-x);}
int get(int x){
	int res=0;
	while (x){
		res=max(res,tr[x]);
		x-=low(x);
	}
	return res;
}
void insert(int x,int y){
	while (x<=n){
		tr[x]=max(tr[x],y);
		x+=low(x);
	}
}*/
int main(){
	//freopen("B.in","r",stdin);
	scanf("%d",&q);
	while (q--){
		ans=0;
		ma=0;
		scanf("%d",&n);
		for (int i=1;i<=n;i++) f[i]=mp(0,0);//,tr[i]=0;
		for (int i=1;i<=n;i++){
			scanf("%d",&a[i]);
			if (f[a[i]].fi==0){
				f[a[i]].fi=i;
				ans++;
			}
			f[a[i]].se=i;
		}
		last=0;
		for (int i=1;i<=n;i++)
		if (f[i].fi){
			if (f[i].fi>f[last].se) dp[i]=dp[last]+1;
			else dp[i]=1;
			ma=max(ma,dp[i]);
			last=i;
		}
		printf("%d\n",ans-ma);
	}
}