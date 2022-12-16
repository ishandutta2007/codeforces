#include<bits/stdc++.h>
#define ll long long
#define pll pair<ll,ll>
#define MP make_pair
#define PB push_back
#define F first
#define S second
using namespace std;
const ll maxn=1e5+10,inf=1e18;
ll Ms[maxn],Me[maxn],a[maxn];
int main(){
	ll n,k;cin>>n>>k;
	ll Max=-inf,Min=inf;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
		Max=max(Max,a[i]);
		Min=min(Min,a[i]);
	}
	if(k==1)cout<<Min;
	else if(k==2)cout<<max(a[1],a[n]);
	else cout<<Max;
}