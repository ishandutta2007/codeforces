#include <bits/stdc++.h>
 
#pragma GCC optimize("O3")
//#pragma GCC optimize("unroll-loops")
 
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
#define out(x,y) cout << ">> " << x << " " << y << endl
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
const int MAX = 1e3+5;
const ll MOD = 1000000007;
const ll MOD2 = 2010405347;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 555;

int n,m,k,r[MAX][MAX],c[MAX][MAX],enr,enc,x,y,nx,ny,vis[MAX][MAX];
set<int> a[MAX],b[MAX];
char z;
queue<pii> q;
vector<pii> del;

inline bool cekr(int c,int a,int b){
	if(b<a)swap(a,b);
	return r[b][c]-r[a-1][c]==0;
}
inline bool cekc(int r,int a,int b){
	if(b<a)swap(a,b);
	return c[r][b]-c[r][a-1]==0;
}

int main(){
// cout<<fixed<<setprecision(10);
// freopen("trip.in", "r", stdin);
// freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m>>k;
    rep(i,1,n)rep(j,1,m){
    	cin>>z;
    	r[i][j] = r[i-1][j];
    	c[i][j] = c[i][j-1];
    	if(z=='#')++r[i][j], ++c[i][j];
    	else a[i].insert(j), b[j].insert(i);
	}
	auto it = a[0].begin();
	cin>>x>>y>>enr>>enc;
	mems(vis,-1);
	vis[x][y] = 0;
	a[x].erase(y), b[y].erase(x);
	q.push({x,y});
	while(!q.empty()){
		x = q.front().fi, y = q.front().se;
		q.pop();
		del.clear();
		it = a[x].lower_bound(y);
		while(it!=a[x].end()){
			if((*it)>y+k || !cekc(x,y,*it))break;
			vis[x][*it] = vis[x][y]+1;
			del.pb({x,*it});
			q.push({x,*it});
			++it;
		}
		it = a[x].lower_bound(y);
		while(it!=a[x].begin()){
			--it;
			if((*it)<y-k || !cekc(x,y,*it))break;
			vis[x][*it] = vis[x][y]+1;
			del.pb({x,*it});
			q.push({x,*it});
		}
		
		it = b[y].lower_bound(x);
		while(it!=b[y].end()){
			if((*it)>x+k || !cekr(y,x,*it))break;
			vis[*it][y] = vis[x][y]+1;
			del.pb({*it,y});
			q.push({*it,y});
			++it;
		}
		it = b[y].lower_bound(x);
		while(it!=b[y].begin()){
			--it;
			if((*it)<x-k || !cekr(y,x,*it))break;
			vis[*it][y] = vis[x][y]+1;
			del.pb({*it,y});
			q.push({*it,y});
		}
		for(pii i:del)a[i.fi].erase(i.se), b[i.se].erase(i.fi);
	}
	cout<<vis[enr][enc]<<endl;
    return 0;
}