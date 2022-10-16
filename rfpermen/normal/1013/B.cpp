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
#define piii pair<ll,pll>
#define pdd pair<double,double>
#define endl "\n"
#define usi unsigned short int
const ll MAX=1e5+5;
const ll MAX2 = 11;
const int MOD=1000000000 + 7;
const ll INF=1e18;
const int nr[]={1,-1,0,0,1,1,-1,-1};
const int nc[]={0,0,1,-1,1,-1,1,-1};

ll n,x,y[MAX],z,a,b,c,ans;
bool st,vis[MAX];

int main(){
	//cout<<fixed<<setprecision(6);
    //freopen("input.txt", "r", stdin);
	//freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>x;
    rep(i,1,n)cin>>y[i], vis[y[i]]=1;
    sort(y+1,y+1+n);
    rep(i,2,n){
    	if(y[i-1]==y[i])return cout<<0<<endl, 0;
	}
	rep(i,1,n)y[i]&=x;
	ans=100;
	sort(y+1,y+1+n);
	rep(i,2,n){
		if(y[i-1]==y[i]){
			if(vis[y[i]])ans = 1;
			if(ans==100)ans = 2;
		}
	}
	if(ans==100)cout<<-1<<endl;
	else cout<<ans<<endl;
    return 0;
}