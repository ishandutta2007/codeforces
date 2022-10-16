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
#define ff fi.fi
#define fs fi.se
#define pii pair<int,int> 
#define pll pair<ll,ll>
#define piii pair<ll,pll>
#define pdd pair<double,double>
#define endl "\n"
#define usi unsigned short int
const ll MAX=1e5+5;
const ll MAX2 = 11;
const ll MOD=1000000000 + 7;
const ll INF=1e18;
const int nr[]={1,-1,0,0,1,1,-1,-1};
const int nc[]={0,0,1,-1,1,-1,1,-1};

int n,k,x[MAX],mx,mn;

int main(){
	cout<<fixed<<setprecision(0);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>k;
    mx = 0;
    mn = 100;
    rep(i,1,n)cin>>x[i], mn = min(x[i],mn), mx = max(x[i],mx);
    if(mx-mn>k)return cout<<"NO",0;
    cout<<"YES\n";
    rep(i,1,n){
    	rep(j,1,mn)cout<<1<<" ";
    	rep(j,mn+1,x[i])cout<<j-mn<<" ";
    	cout<<endl;
	}
    return 0;
}