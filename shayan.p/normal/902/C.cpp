// Believe in yourself...
#include<bits/stdc++.h>
#define ll long long
#define pll pair<ll,ll>
#define MP make_pair
#define PB push_back
#define F first
#define S second
using namespace std;
const ll maxn=2e5+10;
ll h[maxn],par[maxn];
ll sp1,sp2,sp;
bool yes;
int main(){
	ll n;cin>>n;n++;
	ll bef=0,use=1;
	for(ll i=0;i<n;i++)
		cin>>h[i];
	bef=1;
	par[1]=0;
	use=2;
	for(ll i=1;i<n;i++){
		ll usbef=use;
		for(use;use<usbef+h[i];use++){
			par[use]=bef;
		}
		if(!yes&&h[i]!=1&&h[i-1]!=1){
			sp=usbef;
			sp1=bef;
			sp2=bef+1;
			yes=1;
		}
		bef=usbef;
	}
	if(!yes)cout<<"perfect";
	else{
		cout<<"ambiguous\n";
		for(ll i=1;i<use;i++){
			if(i==sp)cout<<sp1<<" ";
			else cout<<par[i]<<" ";
		}
		cout<<endl;
		for(ll i=1;i<use;i++){
			if(i==sp)cout<<sp2<<" ";
			else cout<<par[i]<<" ";
		}
	}
}