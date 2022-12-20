#include<bits/stdc++.h>
#define ll long long
#define pll pair<ll,ll>
#define MP make_pair
#define PB push_back
#define F first
#define S second
using namespace std;
const ll maxn=2e5+10;
set<ll>st;
ll ans,a[maxn];
int main(){
	ll n,m,k;cin>>n>>m>>k;
	for(ll i=0;i<n;i++)cin>>a[i];
	sort(a,a+n);
	ll last=0;//akharini ke nayoomade
	for(ll i=0;i<n;i++){
		while(last<n&&a[last]-a[i]<m){
			st.insert(last);
			last++;
		}
		while(st.size()>=k){
			st.erase((--st.end()));
			ans++;
		}
		st.erase(i);
	}
	cout<<ans;
}