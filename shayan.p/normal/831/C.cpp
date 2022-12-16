#include<bits/stdc++.h>
#define ll int
#define pll pair<ll,ll>
#define MP make_pair
#define PB push_back
#define F first
#define S second
using namespace std;
const ll maxn=2010;
ll a[maxn],b[maxn],sum,n,k;
set<ll>s,ans;
int main(){
	cin>>n>>k;
	for(ll i=0;i<n;i++)cin>>a[i];
	for(ll i=0;i<k;i++)cin>>b[i];
	ll sum=0;
	for(ll i=0;i<n;i++){
		sum+=a[i];
		ll is=b[0]-sum;
		ll val=is;
		s.clear();
		for(ll j=0;j<n;j++){
			val+=a[j];
			s.insert(val);
		}
		bool yes=1;
		for(ll j=0;j<k;j++){
			if(!s.count(b[j])){
				yes=0;
				break;
			}
		}
		if(yes){
			ans.insert(is);
		}
	}
	cout<<ans.size();
}