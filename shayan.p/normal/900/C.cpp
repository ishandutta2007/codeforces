#include<bits/stdc++.h>
#define ll long long
#define pll pair<ll,ll>
#define MP make_pair
#define PB push_back
#define F first
#define S second
using namespace std;
const ll maxn=1e5+10;
ll dp[3][maxn];
ll a[maxn];
ll is[maxn];
ll brake[maxn];
set<ll>s;
int main(){
	ll n;cin>>n;
	for(ll i=0;i<n;i++)cin>>a[i];
	s.clear();
	for(ll i=0;i<n;i++){
		set<ll>::iterator it=s.upper_bound(a[i]),cop;
		cop=it;
		if(cop==s.end())is[a[i]]=1;
		else if(++cop==s.end())brake[*it]++;
		s.insert(a[i]);
	}
	ll Max=1;
	for(ll i=1;i<=n;i++){
		if(brake[i]-is[i]>brake[Max]-is[Max])Max=i;
	}
	cout<<Max;
}