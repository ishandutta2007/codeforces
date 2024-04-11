#include<bits/stdc++.h>
#define ll long long
#define pll pair<ll,ll>
#define MP make_pair
#define PB push_back
#define F first
#define S second
using namespace std;
int main(){
	ll n,a,b;cin>>n>>a>>b;
	for(ll i=0;i<=10000000;i++){
		if(n-(i*a)>=0&&(n-(a*i))%b==0){
			cout<<"YES"<<endl<<i<<" "<<(n-(a*i))/b<<endl;
			return 0;
		}
	}
	cout<<"NO";
}