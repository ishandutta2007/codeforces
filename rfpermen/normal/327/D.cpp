#include <bits/stdc++.h>
 
#pragma GCC optimize("O2")
#pragma GCC optimize("unroll-loops")
 
using namespace std;
#define ll long long
#define ull unsigned long long
#define rep(i,n,N) for(int i=n;i<=N;++i)
#define asd(i,n,N) for(int i=n;i< N;++i)
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
#define db(x) cout << ">>>> " << #x << " -> " << x << endl
#define mems(x,y) memset(x,y,sizeof x)
#define all(x) x.begin(),x.end()
#define rng() ((rand()<<16)|rand())
#define pii pair<int,int> 
#define pll pair<ll,ll>
#define plll pair<ll,pll>
#define piii pair<int,pii>
#define piiii pair<pii,pii>
#define psi pair<string,int>
#define endl '\n'
const int MAX = 5e2+5;
const ll MAX2 = 11;
const ll MOD = 1000000007;
const ll MOD2 = 2010405347;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 555;

int n,m,vis[MAX][MAX],r,c,nr,nc,cnt,mx;
char x[MAX][MAX];
queue<pii> q;
vector<pii> v[MAX*MAX];

int main(){
// cout<<fixed<<setprecision(10);
// freopen("trip.in", "r", stdin);
// freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m;
    mems(x,'#');
    rep(i,1,n)rep(j,1,m)cin>>x[i][j];
    rep(i,1,n)rep(j,1,m)if(x[i][j]=='.'){
    	x[i][j] = '#';
    	q.push({i,j});
    	while(!q.empty()){
    		r = q.front().fi, c = q.front().se, q.pop();
    		v[vis[r][c]].pb({r,c});
    		rep(k,0,3){
    			nr = r+dr[k], nc = c+dc[k];
    			if(x[nr][nc]=='.'){
    				x[nr][nc] = '#';
    				vis[nr][nc] = vis[r][c]+1;
    				q.push({nr,nc});
				}
			}
		}
	}
	n*= m;
	rap(i,n,0)if(!v[i].empty()){
		mx = i;
		break;
	}
	rep(i,0,mx){
		cnt+= v[i].size();
		if(i!=0 && i!=mx)cnt+= v[i].size()*2;
	}
	cout<<cnt<<endl;
	if(mx==0){
		for(pii i:v[0])cout<<"B "<<i.fi<<' '<<i.se<<endl;
	}
	else {
		rap(i,mx-1,0){
			for(pii j:v[i])cout<<"B "<<j.fi<<' '<<j.se<<endl;
			for(pii j:v[i+1])cout<<"R "<<j.fi<<' '<<j.se<<endl;
			if(i)for(pii j:v[i])cout<<"D "<<j.fi<<' '<<j.se<<endl;
		}
	}
    return 0;
}