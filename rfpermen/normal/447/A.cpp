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
#define ff fi.fi
#define fs fi.se
#define sf se.fi
#define ss se.se
#define pii pair<int,int> 
#define pll pair<ll,ll>
#define piii pair<int,pii>
#define endl "\n"
const ll MAX=2e5+5;
const int MOD=1000000000 + 7;
const ll INF=2*1e18;
const int nr[]={1,-1,0,0,1,1,-1,-1,  2,2,-2,-2,1,1,-1,-1};
const int nc[]={0,0,1,-1,1,-1,1,-1,  1,-1,1,-1,2,-2,2,-2};

int n,m,y,z,x,ls,nw;
bool v[305];

int main(){
    //cout<<fixed<<setprecision(3);
    //freopen("input.txt", "r", stdin);
	//freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>x>>y;
    rep(i,1,y){
    	cin>>z;
    	z%=x;
    	if(v[z])return cout<<i,0;
    	v[z] = 1;
	}
	cout<<-1;
    return 0;
}