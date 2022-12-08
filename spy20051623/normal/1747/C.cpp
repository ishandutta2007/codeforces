#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
const int N=1e5+5;
int a[N];

void solve(){
	int n;
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	if(a[1]==0){
		cout<<"Bob\n";
		return;
	}
	for(int i=2;i<=n;++i){
		if(a[i]<a[1]){
			cout<<"Alice\n";
			return;
		}
	}
	cout<<"Bob\n";
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