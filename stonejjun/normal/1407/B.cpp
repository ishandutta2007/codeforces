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
		for(i=1;i<=n;i++){
			cin>>arr[i];
			chk[i]=0;
		}
		sort(arr+1,arr+1+n);
		chk[n]=1;
		ans[1]=arr[n];
		ll gcd=arr[n];

		for(i=2;i<=n;i++){
			//cout<<i<<' '<<arr[i]<<'\n';
			ll mx=0;
			ll pos=0;
			for(j=1;j<=n;j++){
				if(__gcd(gcd,arr[j])>mx&&chk[j]==0){
					mx=__gcd(gcd,arr[j]);
					pos=j;
				}
			}
			gcd=__gcd(gcd,arr[pos]);
			ans[i]=arr[pos];
			chk[pos]=1;
		}
		for(i=1;i<=n;i++)
			cout<<ans[i]<<' ';
		cout<<'\n';
	}
}