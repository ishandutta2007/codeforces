#include <bits/stdc++.h>

using namespace std;
using nagai=long long;
#define sz(x) int((x).size())

const int N=1000100;
vector<int>g[N],gr[N];
int n,m;
bool used[N];
vector<int>ord;
void ts(int u){
	if(used[u])return;
	used[u]=true;
	for(int v:g[u])
		ts(v);
	ord.push_back(u);
}
void d(int u){
	if(used[u])return;
	used[u]=true;
	for(int v:g[u])
		d(v);
}
void dr(int u){
	if(used[u])return;
	used[u]=true;
	for(int v:gr[u])
		dr(v);
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--){
		cin>>n>>m;
		for(int i=0;i<n;++i)
			g[i].clear();
		for(int i=0;i<n;++i)
			gr[i].clear();
		for(int i=0;i<m;++i){
			 int a,b;
			 cin>>a>>b;
			 --a,--b;
			 g[a].push_back(b);
			 gr[b].push_back(a);
		}
		ord.clear();
		fill(used,used+n,false);
		for(int i=0;i<n;++i)
			ts(i);
		reverse(ord.begin(),ord.end());
		fill(used,used+n,false);
		int last=-1;
		for(int x:ord)
			if(!used[x]){
				last=x;
				dr(x);
			}
		int x=last;
		fill(used,used+n,false);
		d(x);
		int c=count(used,used+n,true);
		if(c<n){
			cout<<"Yes\n";
			cout<<c<<' '<<n-c<<'\n';
			for(int i=0;i<n;++i)
				if(used[i])
					cout<<i+1<<' ';
			cout<<'\n';
			for(int i=0;i<n;++i)
				if(!used[i])
					cout<<i+1<<' ';
			cout<<'\n';
		}
		else{
			cout<<"No\n";
		}
	}
	return 0;
}