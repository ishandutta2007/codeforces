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
#define sf se.fi
#define ss se.se
#define pii pair<int,int> 
#define pll pair<ll,ll>
#define piii pair<int,pii>
#define piiii pair<piii,pii>
#define endl "\n"
const ll MAX=1e2+5;
const ll MAX2 = 11;
const int MOD=1000000000 + 7;
const ll INF=20000;
const int nr[]={1,0,-1,0,1,1,-1,-1};
const int nc[]={0,1,0,-1,1,-1,1,-1};

int n,m,q,x,y,r[505],mx,cnt;
bool c[505][505];

int main(){
//	cout<<fixed<<setprecision(0);
    //freopen("input.txt", "r", stdin);
	//freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m>>q;
    rep(i,1,n){
    	cnt = mx = 0;
    	rep(j,1,m){
    		cin>>c[i][j];
    		if(c[i][j])cnt++;
    		else mx = max(mx,cnt), cnt = 0;
		}
		r[i] = max(mx,cnt);
	}
	while(q--){
		cin>>x>>y;
		c[x][y]^=1;
		cnt = mx = 0;
    	rep(j,1,m){
    		if(c[x][j])cnt++;
    		else mx = max(mx,cnt), cnt = 0;
		}
		r[x] = max(mx,cnt);
		mx = 0;
		rep(i,1,n)mx = max(mx,r[i]);
		cout<<mx<<endl;
	}
    return 0;
}