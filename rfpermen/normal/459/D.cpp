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
//#define ff fi.fi
//#define fs fi.se
//#define sf se.fi
//#define ss se.se
#define pii pair<int,int> 
#define pll pair<ll,ll>
#define piii pair<int,pii>
#define plll pair<pll,ll>
#define endl "\n"
const ll MAX=1e6+5;
const int MOD=1000000000 + 7;
const ll INF=2e18;
const int nr[]={1,-1,0,0,1,1,-1,-1,  2,2,-2,-2,1,1,-1,-1};
const int nc[]={0,0,1,-1,1,-1,1,-1,  1,-1,1,-1,2,-2,2,-2};

int n,x[MAX],bit[MAX],ret;
ll ans;
map<int,int> pf,sf;

inline void upd(int i,int y){
	for(; i<=n ; i+=(i&-i))bit[i]+=y;
}

inline int que(int i){
	ret = 0;
	for(; i>0 ; i-=(i&-i))ret+=bit[i];
	return ret;
}

int main(){
    //cout<<fixed<<setprecision(3);
    //freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    rep(i,1,n)cin>>x[i];
    rap(i,n,1){
    	sf[x[i]]++;
    	upd(sf[x[i]],1);
	}
	rep(i,1,n){
    	upd(sf[x[i]],-1);
    	sf[x[i]]--;
    	pf[x[i]]++;
    	ans+=que(pf[x[i]]-1);
	}
	cout<<ans<<endl;
    return 0;
}