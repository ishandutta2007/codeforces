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
#define piiii pair<piii,pii>
#define endl "\n"
const ll MAX=1e5+5;
const ll MAX2 = 11;
const int MOD=1000000000 + 7;
const ll INF=20000;
const int nr[]={1,0,-1,0,1,1,-1,-1};
const int nc[]={0,1,0,-1,1,-1,1,-1};

int n,m;
bool vis[51][51],st;
char x[55][55];

bool inside(int r,int c){
	if(r>0 && r<=n && c>0 && c<=m)return 1;
	return 0;
}
int r,c,a,b;
int main(){
	//cout<<fixed<<setprecision(10);
    //freopen("input.txt", "r", stdin);
	//freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m;
    rep(i,1,n)rep(j,1,m)cin>>x[i][j];
    st = 1;
    rep(i,1,n)rep(j,1,m){
    	if(x[i][j]=='B'){
    		memset(vis,0,sizeof vis);
    		vis[i][j] = 1;
    		rep(k,0,3){
    			r = i+nr[k], c= j+nc[k];
    			//cout<<r<<" "<<c<<endl;
    			while(inside(r,c) && x[r][c]=='B'){
    				//cout<<"debug\n";
    				vis[r][c] = 1;
    				rep(o,0,3){
    					if(k%2==o%2)continue;
    					a = r+nr[o], b = c+nc[o];
    					while(inside(a,b) && x[a][b]=='B'){
    						vis[a][b] = 1;
    						a+=nr[o], b+=nc[o];
						}
					}
					r+=nr[k], c+=nc[k];
				}
			}
			rep(k,1,n)rep(o,1,m){//cout<<vis[k][o]; cout<<endl;
				if(x[k][o]=='B' && vis[k][o]==0)return cout<<"NO",0;
			}
		}
	}
	cout<<"YES";
    return 0;
}