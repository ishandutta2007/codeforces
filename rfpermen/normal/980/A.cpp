#include <bits/stdc++.h>

#pragma GCC optimize("O3")
using namespace std;
#define ll long long
#define rep(i,n,N) for(int i=n;i<=N;i++)
#define rap(i,n,N) for(int i=(int)n;i>=(int)N;i--)
#define mp make_pair
#define pb push_back
#define pob pop_back
#define pf push_front
#define pof pop_front
#define fi first
#define se second
#define pii pair<int,int> 
#define pll pair<ll,ll>
#define piii pair<int,pii>
const ll MAX=200005;
const int MOD=1000000000 + 7;
const ll INF=20000;
const int nr[]={1,-1,0,0,1,1,-1,-1};
const int nc[]={0,0,1,-1,1,-1,1,-1};
ll x[2];
string s;

int main(){
    cout<<fixed<<setprecision(9);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin>>s;
	rep(i,0,s.size()-1){
		if(s[i]=='o')x[0]++;
		else x[1]++;
	}
	//cout<<x[0]<<" "<<x[1]<<endl;
	if(x[0]==0)cout<<"YES"<<endl;
	else if(x[1]%x[0]==0)cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
    return 0;
}