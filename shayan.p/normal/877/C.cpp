#include<bits/stdc++.h>
#define ll long long
#define pll pair<ll,ll>
#define MP make_pair
#define PB push_back
#define F first
#define S second
using namespace std;
ll n;
void zoj(){
	for(ll i=2;i<=n;i+=2)cout<<i<<" ";
}
void fard(){
	for(ll i=1;i<=n;i+=2)cout<<i<<" ";
}
int main(){
	cin>>n;
	cout<<n+(n/2)<<endl;
	zoj();fard();zoj();
}