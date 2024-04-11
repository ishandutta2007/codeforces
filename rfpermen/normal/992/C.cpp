#include <bits/stdc++.h>

#pragma GCC optimize("O2")
using namespace std;
#define ll long long
#define rep(i,n,N) for(ll i=n;i<=N;i++)
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
//#define endl "\n"
const ll MAX=1e5+5;
const int MOD=1000000000 + 7;
const ll INF=1e18;
const int nr[]={0,-1,0,1,1,1,-1,-1,  2,2,-2,-2,1,1,-1,-1};
const int nc[]={1,0,-1,0,1,-1,1,-1,  1,-1,1,-1,2,-2,2,-2};
ll n,k,a,b;
ll pow(ll x,ll y, ll z){
	if(y==0)return 1;
	if(y==1)return x;
	ll temp= pow(x,y/2,z)%z;
	if(y%2==0) return (temp*temp)%z;
	if(y%2==1) return (((temp*temp)%z)*(x%z))%z;
}

int main(){
    //cout<<fixed<<setprecision(3);
    //freopen("input.txt", "r", stdin);
	//freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>k; k++;
    if(!n)return cout<<0<<endl,0;
    b=2;
    n%=MOD;
    a=pow(b,k,MOD);
    b=pow(b,k-1,MOD);
    n*=a;
    n%=MOD;
    cout<<(MOD+n-b+1)%MOD<<endl;
    return 0;
}