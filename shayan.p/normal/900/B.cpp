#include<bits/stdc++.h>
#define ll long long
#define pll pair<ll,ll>
#define MP make_pair
#define PB push_back
#define F first
#define S second
using namespace std;
void taghsim(vector<ll>&v,ll a,ll b){
	a*=10;
	for(ll i=0;i<1000;i++){
		v.PB(a/b);
		a=a%b;
		a*=10;
	}
}
int main(){
	ll a,b,c;cin>>a>>b>>c;
	vector<ll>v;
	taghsim(v,a,b);
	for(ll i=0;i<v.size();i++){
		if(v[i]==c){
			cout<<i+1;
			return 0;
		}
	}
	cout<<-1;
}