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
#define endl "\n"
const ll MAX=1e5+5;
const int MOD=1000000000 + 7;
const ll INF=1e18;
const int nr[]={0,-1,0,1,1,1,-1,-1,  2,2,-2,-2,1,1,-1,-1};
const int nc[]={1,0,-1,0,1,-1,1,-1,  1,-1,1,-1,2,-2,2,-2};

int n,x;
map<int,int> a,b,c;

int main(){
    //cout<<fixed<<setprecision(3);
    //freopen("input.txt", "r", stdin);
	//freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    rep(i,1,n)cin>>x, a[x]++;
    rep(i,2,n)cin>>x, b[x]++;
    rep(i,3,n)cin>>x, c[x]++;
    for(auto i:a){
    	if(!b.count(i.fi))cout<<i.fi<<endl;
		else if(b[i.fi]<a[i.fi])cout<<i.fi<<endl;
	}
    for(auto i:b){
    	if(!c.count(i.fi))cout<<i.fi<<endl;
		else if(c[i.fi]<b[i.fi])cout<<i.fi<<endl;
	}
    return 0;
}