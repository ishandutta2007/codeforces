#include <bits/stdc++.h>
 
#pragma GCC optimize("O3")
using namespace std;
#define ll long long
#define ull unsigned long long
#define rep(i,n,N) for(ll i=n;i<=N;++i)
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
#define sf se.fi
#define ss se.se
#define lc (id<<1)
#define rc ((id<<1)|1)
#define db(x) cerr << ">>>>>> " << #x << " -> " << x << endl
#define nani(x) cerr <<  "Line " << __LINE__ << ": " << #x << " is " << x << endl
#define all(x) x.begin(),x.end()
#define pii pair<int,int> 
#define pll pair<ll,ll>
#define plll pair<ll,pll>
#define piii pair<int,pii>
#define piiii pair<pii,pii>
#define psi pair<string,int>
#define endl '\n'
const int MAX = 5e3+5;
const ll MAX2 = 11;
const ll MOD = 1000000007;
const ll MOD2 = 1000005329;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 2000;

ll k,n[16],x[16][MAX],ttl[16],tgt,en,zz,c[16],p[16];
map<ll,int> pos;
bool dp[1<<15],vis[1<<15];

bool f(int mask){
	if(mask==en){cout<<"Yes\n"; return true;}
	if(vis[mask])return dp[mask];
	vis[mask] = true;
	int st, tmp = mask, ls, nw, res;
	ll fn;
	bool sta;
	stack<int> rese;
	rep(i,0,k){
		if(!(mask&(1<<i))){
			st = i;
			break;
		}
	}
	tmp|=(1<<st);
	rep(i,1,n[st]){
		fn = tgt - ttl[st] + x[st][i];
		if(!pos.count(fn))continue;
		res = pos[fn];
		if(tmp&(1<<res))continue;
		sta = true;
		ls = st;
		while(1){
			c[res] = fn, p[res] = ls;
			rese.push(1<<res);
			tmp|=(1<<res);
			fn = tgt - ttl[res] + fn;
			if(fn==x[st][i])break;
			if(!pos.count(fn)){sta = false; break;}
			ls = res, res = pos[fn];
			if(tmp&(1<<res)){sta = false; break;}
		}
		if(!sta || !f(tmp))while(!rese.empty())tmp^=rese.top(), rese.pop();
		else {
			c[st] = fn, p[st] = res;
			return dp[mask] = true;
		}
	}
	return false;
}

int main(){
//	cout<<fixed<<setprecision(4);
//    freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>k; en = (1<<k)-1, --k;
    rep(i,0,k){
    	cin>>n[i];
    	rep(j,1,n[i])cin>>x[i][j], pos[x[i][j]] = i, ttl[i]+=x[i][j];
    	tgt+= ttl[i];
	}
	if(tgt%(k+1))return cout<<"No\n",0;
	tgt/=k+1;
	rep(i,0,k)if(ttl[i]==tgt)zz|=(1<<i), c[i] = x[i][1], p[i] = i;
	if(!f(zz))return cout<<"No\n",0;
	rep(i,0,k)cout<<c[i]<<' '<<p[i]+1<<endl;
    return 0;
}