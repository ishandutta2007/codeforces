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
const ll MAX=2e5+5;
const ll MAX2 = 11;
const int MOD=1000000000 + 7;
const ll INF=20000;
const int nr[]={1,0,-1,0,1,1,-1,-1};
const int nc[]={0,1,0,-1,1,-1,1,-1};

int n,m,tmp,a,b,ans;
bool vis[7],st;

int main(){
//	cout<<fixed<<setprecision(0);
    //freopen("input.txt", "r", stdin);
	//freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m;
    tmp = 7, a = 1;
    while(tmp<n)tmp*=7, a++;
    tmp = 7, b = 1;
    while(tmp<m)tmp*=7, b++;
    if(a+b>7)return cout<<0,0;
    n--, m--;
    rep(i,0,n){
    	memset(vis,0,sizeof vis);
    	tmp = i, st = 0;
    	rep(k,1,a){
    		st|=vis[tmp%7];
    		vis[tmp%7] = 1;
    		tmp/=7;
		}
    	if(st)continue;
    	rep(j,0,m){
    		memset(vis,0,sizeof vis);
	    	tmp = i, st = 0;
	    	rep(k,1,a){
	    		vis[tmp%7] = 1;
	    		tmp/=7;
			}
			tmp = j;
			rep(k,1,b){
    			st|=vis[tmp%7];
	    		vis[tmp%7] = 1;
	    		tmp/=7;
			}
			if(!st)ans++;
		}
	}
	cout<<ans<<endl;
    return 0;
}