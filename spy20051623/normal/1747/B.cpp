#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
const int N=1e5+5;
int a[N];

void solve(){
	int n;
	cin>>n;
	vector<pii> v;
	int l=1,r=3*n;
	while(l<r){
		v.push_back({l,r});
		l+=3;
		r-=3;
	}
	cout<<v.size()<<'\n';
	for(auto i:v)cout<<i.first<<' '<<i.second<<'\n';
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