#include<bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3")
#define ll long long
#define rep(i,n,N) for(int i=(int)n;i<=(int)N;i++)
#define rap(i,n,N) for(int i=(int)n;i>=(int)N;i--)
#define pii pair<int,int>
#define pll pair<ll,ll>
#define mp make_pair
#define pb push_back
#define pob pop_back
#define pf push_front
#define pof pop_front
#define fi first
#define se second
const int MAX=200005;
const int MOD=1000000000 + 7;
int n,last,id,cnt,tmp,dp[105][2];
pii x[105];
int cv(int idx, int stat){
	if(idx>id)return 0;
	if(stat==1)return dp[idx][1] = cv(idx+1,1) + x[idx].fi*x[idx].se;
	return dp[idx][0] = max(cv(idx+1,0) + ((x[idx].se+1)%2)*x[idx].fi , cv(idx+1,1) + x[idx].fi*x[idx].se);
}
int main(){
	//cout<<fixed<<setprecision(9);
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin>>n>>last;
	cnt=1;
	rep(i,2,n){
		cin>>tmp;
		if(tmp!=last)id++, x[id] = mp(cnt,last), cnt=1;
		else cnt++;
		last=tmp;
	}
	id++, x[id] = mp(cnt,last);
	//rep(i,1,id)cout<<x[i].fi<<" "<<x[i].se<<endl;
	//cout<<id<<endl;
	cout<<cv(1,0)<<endl;
	return 0;
}