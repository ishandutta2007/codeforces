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
//#define ff fi.fi
//#define fs fi.se
//#define sf se.fi
//#define ss se.se
#define lc (id<<1)
#define rc ((id<<1)|1)
#define db(x) cerr << ">>>>>> " << #x << " -> " << x << endl
#define nani(x) cerr <<  "Line " << __LINE__ << ": " << #x << " is " << x << endl
#define all(x) x.begin(),x.end()
#define pii pair<int,int> 
#define pll pair<ll,ll>
#define plll pair<ll,pll>
#define pllll pair<pll,pll>
#define piii pair<int,pii>
#define piiii pair<pii,pii>
#define psi pair<string,int>
#define endl '\n'
const int MAX = 15+5;
const ll MAX2 = 11;
const ll MOD = 1000000007;
const ll MOD2 = 1000005329;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 2000;
 
int n,m,r,c,nr,nc,mv;
char x[MAX][MAX],nw,uj;
map<vector<int>, int> vis;
queue<vector<int>> q;
vector<int> v,nx;
bool st;

int main(){
//	cout<<fixed<<setprecision(10);
//    freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
//    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m;
    memset(x,'#',sizeof x);
    rep(i,1,n)rep(j,1,m)cin>>x[i][j];
    rep(i,1,n)rep(j,1,m){
    	if(x[i][j]=='1'){
    		r = i, c = j;
    		nw = '1';
    		do{
    			v.pb(r*20+c);
    			x[r][c] = '.';
    			st = 0;
    			rep(k,0,3){
    				nr = r+dr[k], nc = c+dc[k];
    				if(x[nr][nc]==nw+1){
    					r = nr, c = nc, ++nw;
    					st = 1;
    					break;
					}
				}
			}while(st);
			uj = nw;
		}
	}
	int cr,cc;
	vis[v] = 0;
	q.push(v);
	while(!q.empty()){
		v = q.front(); q.pop();
		mv = vis[v];
		nw = '0';
		for(auto i:v)x[i/20][i%20] = ++nw;
//		cout<<"____________\n";
//		rep(i,1,n){
//			rep(j,1,m)cout<<x[i][j];
//			cout<<endl;
//		}
		r = v[0]/20, c = v[0]%20;
//		cout<<">> "<<r<<' '<<c<<endl;
		
		rep(o,0,3){
			nr = r+dr[o], nc = c+dc[o];
			if(x[nr][nc]=='@')return cout<<mv+1<<endl,0;
			if(x[nr][nc]=='#' || (x[nr][nc]>'1' && x[nr][nc]!=uj))continue;
			nx.clear();
			nx.pb(nr*20+nc);
			nw = '1';
			while(nw!=uj){
    			rep(k,0,3){
    				cr = nr+dr[k], cc = nc+dc[k];
    				if(x[cr][cc]==nw){
    					nr = cr, nc = cc;
    					nx.pb(nr*20+nc);
    					++nw;
    					break;
					}
				}
			}
			if(vis.count(nx))continue;
			vis[nx] = mv+1;
			q.push(nx);
		}
		x[r][c] = '.';
		nw = '1';
		do{
			rep(k,0,3){
				nr = r+dr[k], nc = c+dc[k];
				if(x[nr][nc]==nw+1){
					r = nr, c = nc, ++nw;
					break;
				}
			}
			x[r][c] = '.';
		}while(nw!=uj);
	}
    cout<<"-1\n";
    return 0;
}