#include <bits/stdc++.h>

using namespace std;
using nagai = long long;
#define sz(x) int((x).size())

const int N=600600;
int a[N],b[N];

int n;
vector<int>mx;
pair<int,int>t[2*N];
pair<int,int> get(int l,int r){
	l+=N;
	r+=N;
	pair<int,int>ans={-1,-1};
	while(l<r){
		if(l&1)
			ans=max(ans,t[l++]);
		if(r&1)
			ans=max(ans,t[--r]);
		l/=2,r/=2;
	}
	return ans;
}
void st(int x,int y,int z){
	x+=N;
	t[x]={y,z};
	while(x>1)
		t[x>>1]=max(t[x],t[x^1]),x>>=1;
}
#define prev aeushtaoeustnh
int dp[N];
int prev[N];
void solve(){
	fill(t,t+2*N,make_pair(-1,-1));
	vector<int>ord(n);
	iota(ord.begin(),ord.end(),0);
	sort(ord.begin(),ord.end(),[&](int a,int b){
				return ::b[a]>::b[b];
			});
	int m=-1,mi=-1;
	for(int i:ord){
		if(a[i]>b[i])continue;
		auto p=get(a[i],N);
		if(p.first==-1)p={0,-1};
		dp[i]=p.first+1;
		prev[i]=p.second;
		st(b[i],dp[i],i);
		if(dp[i]>m)m=dp[i],mi=i;
	}
	vector<int>ans;
	while(mi!=-1)
		ans.push_back(mi),mi=prev[mi];
	reverse(ans.begin(),ans.end());
	if(ans.size()>mx.size())mx=ans;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i=0;i<n;++i)
		cin>>a[i]>>b[i],--a[i],--b[i];
	solve();
	for(int i=0;i<n;++i)
		a[i]=2*n-a[i]-1,b[i]=2*n-b[i]-1;
	solve();
	cout<<mx.size()<<'\n';
	for(int x:mx)
		cout<<x+1<<' ';
	cout<<'\n';
	return 0;
}