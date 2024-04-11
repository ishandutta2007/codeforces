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
#define ss first.second
#define ff first.first
#define pii pair<int,int> 
#define pll pair<ll,ll>
#define piii pair<pii,int>

const ll MAX=5005;
const int MOD=1000000000 + 7;
const ll INF=20000;
const int nr[]={1,-1,0,0,1,1,-1,-1,0};
const int nc[]={0,0,1,-1,1,-1,1,-1,0};
int n,x[MAX],q,l,r,rng[MAX][MAX],sz,ans[MAX][MAX];
vector<piii> nw,ubah;
int main(){
    cout<<fixed<<setprecision(9);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    rep(i,1,n)cin>>x[i], nw.pb(mp(mp(i,i),x[i]));
    cin>>q;
    sz=nw.size();sz--;
    while(sz!=-1){
    	rep(i,0,sz)rng[nw[i].ff][nw[i].ss]=nw[i].se;
    	rep(i,1,sz)ubah.pb(mp(mp(nw[i-1].ff,nw[i].ss),nw[i-1].se^nw[i].se));
    	nw.clear();
    	sz--;
    	rep(i,0,sz)nw.pb(ubah[i]);
    	ubah.clear();
	}
	rep(i,1,n){
		ans[i][i] = rng[i][i];
		rep(j,i+1,n)ans[i][j] = max(ans[i][j-1],rng[i][j]);
	}
	rap(j,n,2){
		rap(i,j-1,1)ans[i][j] = max(ans[i+1][j],ans[i][j]);
	}
    while(q--){
    	cin>>l>>r;
    	cout<<ans[l][r]<<endl;
	}
    return 0;
}