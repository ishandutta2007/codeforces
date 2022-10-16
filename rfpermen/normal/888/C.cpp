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
const int MAX=100005;
const int MOD=1000000000 + 7;
const int nr[]={1,-1,0,0,1,1,-1,-1};
const int nc[]={0,0,1,-1,1,-1,1,-1};
int n,x[27],y[27],mn;
string s;
int main(){
	//cout<<fixed<<setprecision(9);
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin>>s;
	n=s.size()-1;
	mn=n+1;
	memset(y,-1,sizeof y);
	rep(i,0,n){
		rep(j,0,25)x[j]++;
		y[s[i]-'a'] = max(x[s[i]-'a'],y[s[i]-'a']);
		x[s[i]-'a'] = 0;
	}
	rep(i,0,25){
		if(y[i]!=-1){
			mn = min(mn,max(y[i],x[i]+1));
		}
	}
	cout<<mn<<endl;
	return 0;
}