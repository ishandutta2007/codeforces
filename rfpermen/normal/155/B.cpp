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
#define sf se.fi
#define ss se.se
#define pii pair<int,int> 
#define pll pair<ll,ll>
#define piii pair<int,pii>
#define endl "\n"
const ll MAX=1e3+5;
const ll MAX2 = 11;
const int MOD=1000000000 + 7;
const ll INF=20000;
const int nr[]={1,-1,0,0,1,1,-1,-1};
const int nc[]={0,0,1,-1,1,-1,1,-1};

int n,nw,ans;
piii x[MAX],y[MAX];
bool vis[MAX];

int main(){
	cout<<fixed<<setprecision(10);
    //freopen("input.txt", "r", stdin);
	//freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    rep(i,1,n){
    	cin>>x[i].fi>>x[i].sf; x[i].ss = i;
    	y[i] = x[i]; swap(y[i].fi,y[i].sf);
	}
	sort(x+1,x+1+n);
	reverse(x+1,x+1+n);
	sort(y+1,y+1+n);
	reverse(y+1,y+1+n);
	nw = 1;
	rep(i,1,n){
		if(y[i].fi==0)break;
		vis[y[i].ss] = 1;
		ans+=y[i].sf;
		nw+=y[i].fi-1;
	}
	rep(i,1,n){
		if(nw==0)break;
		if(vis[x[i].ss])continue;
		ans+=x[i].fi;
		nw--;
	}
	cout<<ans<<endl;
    return 0;
}