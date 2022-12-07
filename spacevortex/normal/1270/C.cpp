#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=4e5+50;
ll n,W,S,B;
ll a[N];
void Solve()
{
	ll i,vl;
	cin>>n;
	S=0;W=0;
	for(i=1;i<=n;i++) cin>>a[i],S+=a[i],W^=a[i];
	if(S&1ll) B=(1ll<<50)-1;
	else B=(1ll<<50)-2;
	vl=((B^W)*2ll-S-B)/2ll;
	cout<<3<<endl;
	cout<<B<<" "<<vl<<" "<<vl<<endl;
	//2,251,799,813,685,232
}
int main()
{
	ios::sync_with_stdio(false);
	ll T;
	cin>>T;
	while(T--) Solve();
}