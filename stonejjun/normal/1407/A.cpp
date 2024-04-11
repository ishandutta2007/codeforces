#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<ll,ll> pii;

#define ff first
#define ss second
#define ep emplace_back
#define eb emplace
#define pb push_back

ll arr[1010101];
ll chk[1010101];
ll ans[1010101];

string s;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	ll t;
	cin>>t;
	while(t--){
	ll i,j,k,l,m,n;
	cin>>n;
	ll cnt0=0,cnt1=0;
	for(i=1;i<=n;i++){
		cin>>arr[i];
		if(arr[i]) cnt1++;
		else cnt0++;
	}
	if(cnt0>=cnt1){
		cout<<(n+1)/2<<'\n';
		for(i=1;i<=(n+1)/2;i++)
			cout<<'0'<<' ';
	}
	else{
		if(cnt1%2) cnt1--;
		cout<<cnt1<<'\n';
		for(i=1;i<=cnt1;i++)
			cout<<"1 ";
	}
	cout<<'\n';
}
}