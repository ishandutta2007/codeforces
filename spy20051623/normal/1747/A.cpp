#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=1e5+5;
int a[N];

void solve(){
	int n;
	cin>>n;
	ll sum=0;
	for(int i=0;i<n;++i){
		cin>>a[i];
		sum+=a[i];
	}
	cout<<abs(sum)<<'\n';
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int t;
	cin>>t;
	while(t--){
		solve();
	}
}