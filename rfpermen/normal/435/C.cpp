#include <bits/stdc++.h>

#pragma GCC optimize("O2")
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
const int MAX = 1e3+5;
const int MOD=1000000000 + 7;
const ll INF=1e18;
const int nr[]={0,1,0,-1,1,1,-1,-1,  2,2,-2,-2,1,1,-1,-1};
const int nc[]={1,0,-1,0,1,-1,1,-1,  1,-1,1,-1,2,-2,2,-2};

int n,x,mn,mx,id,nw;
char c[2005][1005];

int main(){
//    cout<<fixed<<setprecision(9);
//    freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    memset(c,' ',sizeof c);
    id = 1000;
    mn = 1001;
    rep(i,1,n){
    	cin>>x;
    	if(i&1){
    		while(x--){
	    		id++;
	    		mx = max(mx,id);
	    		c[id][++nw] = '/';
			}
			id++;
		}
		else {
			while(x--){
	    		id--;
	    		mn = min(mn,id);
	    		c[id][++nw] = '\\';
			}
			id--;
		}
	}
	rap(i,mx,mn){
		rep(j,1,nw)cout<<c[i][j]; cout<<'\n';
	}
    return 0;
}