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

int main(){
    //cout<<fixed<<setprecision(3);
    //freopen("input.txt", "r", stdin);
	//freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m;
    cin>>y>>ls;
    z = ls+y-1;
    while(--m){
    	cin>>x>>nw;
    	if(abs(x-y)<abs(ls-nw))return cout<<"IMPOSSIBLE",0;
    	z = max(z,max(ls+((x-y)-abs(ls-nw))/2,nw+((x-y)-abs(ls-nw))/2));
    	y = x;
    	ls= nw;
	}
	z = max(z,ls+abs(n-y));
	cout<<z<<endl;
    return 0;
}