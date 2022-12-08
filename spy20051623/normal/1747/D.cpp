#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
const int N=2e5+5;
int a[N],b[N];
map<int,set<int>> mp[2];
set<int> s;

void solve(){
	int n,m;
	cin>>n>>m;
	mp[0][0].insert(0);
	for(int i=1;i<=n;++i){
		cin>>a[i];
		b[i]=b[i-1]^a[i];
		mp[i&1][b[i]].insert(i);
		if(a[i])s.insert(i);
	}
	s.insert(1e9);
	while(m--){
		int l,r;
		cin>>l>>r;
		if(b[l-1]!=b[r]){
			cout<<"-1\n";
			continue;
		}
		if(*s.lower_bound(l)>r){
			cout<<"0\n";
			continue;
		}
		if((r-l+1)%2){
			cout<<"1\n";
			continue;
		}
		if(a[l]==0||a[r]==0){
			cout<<"1\n";
			continue;
		}
		auto it=mp[l&1][b[l-1]].lower_bound(l+2);
		if(it!=mp[l&1][b[l-1]].end()&&*it<r)cout<<"2\n";
		else cout<<"-1\n";
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int t=1;
//	cin>>t;
	while(t--){
		solve();
	}
}