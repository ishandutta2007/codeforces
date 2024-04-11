#include<bits/stdc++.h>
#define ll long long
#define pll pair<ll,ll>
#define MP make_pair
#define PB push_back
#define F first
#define S second
using namespace std;
bool no;
const ll inf=1e18;
ll ans,last=inf;
int main()
{
	ll n,d,money=0;cin>>n>>d;
	for(ll i=1;i<=n;i++){
		ll x;cin>>x;
		money+=x;
		last=max(last,money);
		if(x==0&&money<0){
			if(last-money<=d){
				last=last-money;
				money=0;
			}
			else{
				ans++;
				money=0;
				last=0;
			}
		}
		if(money>d)no=1;
	}
	if(no)cout<<-1;
	else cout<<ans;
}