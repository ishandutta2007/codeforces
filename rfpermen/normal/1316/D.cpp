#include <bits/stdc++.h>
 
#pragma GCC optimize("O3")
using namespace std;
#define ll long long
#define ull unsigned long long
#define rep(i,n,N) for(int i=n;i<=N;++i)
#define rap(i,n,N) for(int i=n;i>=N;--i)
#define mp make_pair
#define pb push_back
#define pob pop_back
#define pf push_front
#define pof pop_front
#define fi first
#define se second
#define ff fi.fi
#define fs fi.se
#define sf se.fi
#define ss se.se
#define lc (id<<1)
#define rc ((id<<1)|1)
#define db(x) cout << ">>>>>> " << #x << " -> " << x << endl
#define all(x) x.begin(),x.end()
#define pii pair<int,int> 
#define pll pair<ll,ll>
#define plll pair<ll,pll>
#define pllll pair<pll,pll>
#define piii pair<int,pii>
#define piiii pair<pii,pii>
#define psi pair<string,int>
#define endl '\n'
const int MAX = 1e3+5;
const ll MAX2 = 11;
const ll MOD = 1000000007;
const ll MOD2 = 1000000006;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,-1,0,1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 316;
 
int n,a,b,nr,nc;
char ans[MAX][MAX],o[4];
pii x[MAX][MAX],z[MAX][MAX];

queue<pii> q;

int main(){
//	cout<<fixed<<setprecision(2);
//    freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    o[0] = 'D', o[1] = 'L', o[2] = 'U', o[3] = 'R';
    cin>>n;
    rep(i,1,n)rep(j,1,n){
    	cin>>x[i][j].fi>>x[i][j].se;
    	if(x[i][j]==mp(i,j))q.push({i,j});
	}
    while(!q.empty()){
    	a = q.front().fi, b = q.front().se; q.pop();
    	if(z[a][b].fi)continue;
    	if(x[a][b]==mp(a,b))z[a][b] = {a,b}, ans[a][b] = 'X';
    	else {
    		rep(k,0,3){
    			nr = a+dr[k], nc = b+dc[k];
    			if(z[nr][nc]==x[a][b]){
    				z[a][b] = x[a][b];
    				ans[a][b] = o[k];
    				break;
				}
			}
		}
		if(!z[a][b].fi)continue;
		
    	rep(k,0,3){
    		nr = a+dr[k], nc = b+dc[k];
    		if(!z[nr][nc].fi&&x[nr][nc].fi>0)q.push({nr,nc});
		}
	}
	rep(i,1,n)rep(j,1,n){
		if(!ans[i][j]&&x[i][j].fi!=-1)return cout<<"INVALID\n",0;
		if(x[i][j].fi==-1){
			if(ans[i][j])continue;
			rep(k,0,3){
				nr = i+dr[k], nc = j+dc[k];
				if(x[nr][nc]==x[i][j]){
					if(!ans[nr][nc])ans[nr][nc] = o[(k+2)%4];
					ans[i][j] = o[k];
				}
			}
			if(!ans[i][j])return cout<<"INVALID\n",0;
		}
	}
	cout<<"VALID\n";
	rep(i,1,n){
		rep(j,1,n)cout<<ans[i][j]; cout<<endl;
	}
    return 0;
}