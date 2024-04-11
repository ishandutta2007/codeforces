#include <bits/stdc++.h>
#define ll long long int
using namespace std;
ll maxi=1000;

int main() {
	vector<ll>v(maxi);
	ll n,a,b;
	cin>>n;
	string s;
	cin>>s;
	for(ll i=0; i<n; i++) {
		cin>>a>>b;
		ll c=(ll)(s[i]-'0');
		for(ll j=0; j<maxi; j++) {
			v[j]+=c;
			if(j==b) {
				c=c^1;
				b+=a;
			}
		}

	}

	ll cnt=*max_element(v.begin(),v.end());
	cout<<cnt<<endl;
	return 0;
}