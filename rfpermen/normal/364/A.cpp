#include <bits/stdc++.h>

#pragma GCC optimize("O2")
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
#define sf se.fi
#define ss se.se
#define pii pair<int,int> 
#define pll pair<ll,ll>
#define piii pair<int,pii>
#define plll pair<ll,pll>
#define endl "\n"
const ll MAX=2e5+5;
const int MOD=1000000000 + 7;
const ll INF=1e18;
const int nr[]={0,1,0,-1,1,1,-1,-1,  2,2,-2,-2,1,1,-1,-1};
const int nc[]={1,0,-1,0,1,-1,1,-1,  1,-1,1,-1,2,-2,2,-2};

int a,n,x[4005],sqr,y;
ll ans;
string s;
map<int,int> m;

int main(){
    cout<<fixed<<setprecision(9);
    //freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>a>>s;
    n = s.size();
    rep(i,1,n)x[i] = s[i-1]-'0';
    rep(i,1,n){
    	y = 0;
    	rep(j,i,n)y+=x[j], m[y]++;//, cout<<y<<endl,z[4005][4005]
	}
//	rep(i,1,n)rep(j,1,n)z[i][j] = x[i]*x[j];
//	rep(i,1,n){
//		rep(j,1,n)cout<<z[i][j]<<" ";
//		cout<<endl;
//	}
	if(!a)return cout<<(ll)m[0]*n*(n+1)-(ll)m[0]*m[0],0;
    sqr = sqrt(a);
    rep(i,1,sqr){
    	if(a%i)continue;
    	if(a/i!=i)ans+=(ll)m[i]*m[a/i]*2;
    	else ans+=(ll)m[i]*m[a/i];
	}
	cout<<ans;
    return 0;
}