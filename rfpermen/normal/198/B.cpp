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
#define piii pair<ll,pll>
#define pdd pair<double,double>
#define pdb pair<double,bool>
//#define endl "\n"
#define usi unsigned short int
const ll MAX=1e5+5;
const ll MAX2 = 11;
const int MOD=1000000000 + 7;
const ll INF=1e18;
const int nr[]={1,0,0,-1,1,1,-1,-1};
const int nc[]={0,1,-1,0,1,-1,1,-1};

int n,k,nx,lr,nw,vis[2][MAX];
char x[2][MAX];
queue<pair<bool,int> > q;
bool ans;
pair<bool,int> cur;


int main(){
	//cout<<fixed<<setprecision(10);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>k;
    rep(j,0,1)rep(i,1,n)cin>>x[j][i];
    memset(vis,-1,sizeof vis);
    q.push({0,1});
    vis[0][1] = 1;
    while(!q.empty()){
    	cur = q.front(); q.pop();
    	lr = cur.fi, nw = cur.se;
    	if(nw+k>n){ans = 1; break;}
		rep(i,1,2){
			nx = nw+nc[i];
			if(x[lr][nx]=='-' && vis[lr][nx]==-1 && nx>vis[lr][nw]){
				vis[lr][nx] = vis[lr][nw]+1;
				q.push({lr,nx});
			}
		}
		if(x[lr^1][nw+k]=='-' && vis[lr^1][nw+k]==-1){
			vis[lr^1][nw+k] = vis[lr][nw]+1;
			q.push({lr^1,nw+k});
		}
	}
    if(ans)cout<<"YES";
    else cout<<"NO";
    return 0;
}