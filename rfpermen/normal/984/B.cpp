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
#define pii pair<int,int> 
#define pll pair<ll,ll>
#define piii pair<int,pii>

const ll MAX=205;
const int MOD=1000000000 + 7;
const ll INF=20000;
const int nr[]={1,-1,0,0,1,1,-1,-1,0};
const int nc[]={0,0,1,-1,1,-1,1,-1,0};
ll n,m,cnt;
char grid[MAX][MAX];
int main(){
    cout<<fixed<<setprecision(9);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m;
    rep(i,1,n)rep(j,1,m)cin>>grid[i][j];
    rep(i,1,n)rep(j,1,m){
    	if(grid[i][j]=='.'){
    		rep(k,0,7)if(grid[i+nr[k]][j+nc[k]]=='*')return cout<<"NO", 0;
		}
		else if(grid[i][j]-'0'>0 && grid[i][j]-'0'<9){
			cnt=0;
			rep(k,0,7)if(grid[i+nr[k]][j+nc[k]]=='*')cnt++;
			if(cnt!=grid[i][j]-'0')return cout<<"NO", 0;
		}
	}
	cout<<"YES";
    return 0;
}