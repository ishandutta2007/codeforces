#include <bits/stdc++.h>
 
#pragma GCC optimize("O2")
#pragma GCC optimize("unroll-loops")
 
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
#define db(x) cout << ">>>> " << #x << " -> " << x << endl
#define mems(x,y) memset(x,y,sizeof x)
#define all(x) x.begin(),x.end()
#define pii pair<int,int> 
#define pll pair<ll,ll>
#define plll pair<pll,ll>
#define piii pair<int,pii>
#define piiii pair<pii,pii>
#define psi pair<string,int>
#define endl '\n'
const int MAX = 2e5+5;
const ll MAX2 = 11;
const ll MOD = 1000000007;
const ll MOD2 = 1000005329;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 555;
 
int n,m,a,b,c,z,cl,vis[MAX],x[MAX],y[MAX];
ll res,ans,opt,bs,le,ri,m1,m2,gs,tmp,a1,a2;
vector<pii> v[MAX];
set<piii> s;
 
void f(int nw){
	vis[nw] = cl;
	res+= y[nw] < 0 ? -y[nw] : y[nw];
	for(pii i:v[nw])if(vis[i.fi]!=cl){
		y[i.fi] = i.se-y[nw];
		f(i.fi);
	}
	return;
}

bool dfs(int nw){
	for(pii i:v[nw]){
		if(abs(vis[i.fi])==cl){
			if(vis[nw]!=vis[i.fi]){
				if(y[nw]+y[i.fi]!=i.se)return false;
			}
			else {
				tmp = i.se - (y[nw]+y[i.fi]) >> 1;
				if(vis[nw]<0)tmp*=-1;
				if(gs==INF)gs = tmp;
				else if(gs!=tmp)return false;
			}
		}
		else {
			y[i.fi] = i.se-y[nw];
			vis[i.fi] = -vis[nw];
			if(!dfs(i.fi))return false;
		}
	}
	return true;
}
 
int main(){
//	cout<<fixed<<setprecision(10);
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    z = 2;
    cin>>n>>m;
    rep(i,1,m){
    	cin>>a>>b>>c;
    	if(a>b)swap(a,b);
		if(s.count({(c==1 ? 2 : 1),{a,b}}))return cout<<"NO\n",0;
		else if(!s.count({c,{a,b}})){
			s.insert({c,{a,b}});
			c*=z;
			v[a].pb({b,c}), v[b].pb({a,c});
		}
	}
	rep(i,1,n)if(!vis[i]){
		res = 0, y[i] = 0;
		++cl, vis[i] = cl, gs = INF;
		if(!dfs(i))return cout<<"NO\n",0;
		
		if(gs!=INF)bs = gs;
		else {
			le = -400000, ri = 400000;
			while(ri-le>10){
				m1 = (le+le+ri)/3;
				m2 = (le+ri+ri)/3;
				
				res = 0, y[i] = m1, ++cl, f(i), a1 = res;
				res = 0, y[i] = m2, ++cl, f(i), a2 = res;
				
				if(a1<a2)ri = m2-1;
				else le = m1+1;
			}
			
			opt = INF;
			rep(k,le,ri){
				res = 0, y[i] = k, ++cl, f(i);
				if(res<opt)opt = res, bs = k;
			}
		}
		y[i] = bs, ++cl, f(i);
	}
	
	cout<<"YES\n";
	rep(i,1,n)cout<<(double)y[i]/z<<' '; cout<<endl;
	return 0;
}