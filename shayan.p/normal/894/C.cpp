#include<bits/stdc++.h>
#define ll long long
#define pll pair<ll,ll>
#define MP make_pair
#define PB push_back
#define F first
#define S second
using namespace std;
const ll maxn=2000;
ll a[maxn];
int main()
{
	ll m;cin>>m;
	for(ll i=0;i<m;i++)cin>>a[i];
	for(ll i=1;i<m;i++){
		if(a[i]%a[0]!=0){
			cout<<-1;
			return 0;
		}
	}
	cout<<2*m-1<<endl;
	cout<<a[0]<<" ";
	for(ll i=1;i<m;i++)cout<<a[i]<<" "<<a[0]<<" ";
}