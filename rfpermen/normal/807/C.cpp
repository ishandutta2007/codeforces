#include <bits/stdc++.h>

#pragma GCC optimize("O3")
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
#define pii pair<int,int> 
#define pll pair<ll,ll>
#define piii pair<int,pii>
//#define endl "\n"
const ll MAX=100005;
const int MOD=1000000000 + 7;
const ll INF=1e18;
const int nr[]={1,-1,0,0,1,1,-1,-1};
const int nc[]={0,0,1,-1,1,-1,1,-1};
ll T,x,y,p,q,tx,ty,le,ri,mid,tbh,ans;
int main(){
    //cout<<fixed<<setprecision(3);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>T;
    while(T--){
    	cin>>x>>y>>p>>q;
    	if(p==0){
    		if(x!=0)cout<<-1<<endl;
    		else cout<<0<<endl;
    		continue;
		}
		if(p==q){
			if(x<y)cout<<-1<<endl;
			else cout<<0<<endl;
			continue;
		}
		le=1, ri=1e9;
		while(le<=ri){
			mid=(le+ri)/2;
			ty=mid*q; tx=mid*p;
			tbh=ty-y;
			if(ty<y || tx<x)le=mid+1;
			else if(x+tbh>=tx)ans=tbh, ri=mid-1;
			else le=mid+1;
		}
		cout<<ans<<endl;
	}
    return 0;
}