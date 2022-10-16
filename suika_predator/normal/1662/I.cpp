#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF=1e13;
ll n,m;
ll p[200050],x[200050];
ll a[200050];
ll sum[200050];
int main(){
	ios_base::sync_with_stdio(false);
	cin >> n >> m;
	for (int i=1;i<=n;i++) cin >> p[i];
	for (int i=1;i<=m;i++) cin >> x[i];
	sort(x+1,x+m+1);
	x[0]=-INF;
	x[m+1]=INF;
	for (int i=1;i<=n;i++){
		sum[i]=sum[i-1]+p[i];
		a[i]=(i-1)*100;
	}
	ll ans=0;
	for (int pos=0,l=1,r=1;pos<=m;pos++){
		if (!(x[pos]<a[l] && a[l]<=x[pos+1])) continue;
		if (l>n) break;
		for (r=l;r+1<=n && a[r+1]<=x[pos+1];) r++;
		for (int i=l;i<=r;i++){
			ll pt=min(a[i]*2-x[pos],x[pos+1]);
			ll mid=(pt+x[pos+1]+1)/2;
			int it=lower_bound(a+1,a+n+1,mid)-a-1;
			it=min(it,r);
			ans=max(ans,sum[it]-sum[i-1]);
		}
		l=r+1;
	}
	cout << ans << "\n";
	return 0;
}