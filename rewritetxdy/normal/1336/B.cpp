#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const int N = 1e5+10;

ll t,n,m,k,c[N],v[N],w[N];

inline ll cal(ll x,ll y,ll z){
	return (c[x]-v[y])*(c[x]-v[y])+(v[y]-w[z])*(v[y]-w[z])+(w[z]-c[x])*(w[z]-c[x]);
}

int main()
{	
//	freopen("b.in","r",stdin);
//	freopen("b.out","w",stdout);
	scanf("%lld",&t);
	while(t--){
		scanf("%lld%lld%lld",&n,&m,&k);
		for(int i=1;i <= n;i++) scanf("%lld",&c[i]);
		for(int i=1;i <= m;i++) scanf("%lld",&v[i]);
		for(int i=1;i <= k;i++) scanf("%lld",&w[i]);
		sort(c+1,c+1+n);
		sort(v+1,v+1+m);
		sort(w+1,w+1+k);
		ll x=1,y=1,z=1,ans=(ll)3e18;
		while(x+y+z <= n+m+k){
			ans = min(ans,cal(x,y,z));
			ll q = (ll)3e18,f = 0;
			if(x < n && cal(x+1,y,z) < q) q = cal(x+1,y,z) , f = 1;
			if(y < m && cal(x,y+1,z) < q) q = cal(x,y+1,z) , f = 2;
			if(z < k && cal(x,y,z+1) < q) q = cal(x,y,z+1) , f = 3;
/*			if(x < n) q = min(q,c[x+1]);
			if(y < m) q = min(q,v[y+1]);
			if(z < k) q = min(q,w[z+1]);
			if(x < n && c[x+1] == q) f = 1;
			if(y < m && v[y+1] == q){
				if(!f) f = 2;
				else f = c[x] <= v[y] ? 1 : 2;
			}
			if(z < k && w[z+1] == q){
				if(!f) f = 3;
				else if(f == 1)
					f = c[x] <= w[z] ? 1 : 3;
				else
					f = v[y] <= w[z] ? 2 : 3;
			}
*/			if(f == 1) x++;
			else if(f == 2) y++;
			else z++;
		}
		printf("%lld\n",ans);
	}
}