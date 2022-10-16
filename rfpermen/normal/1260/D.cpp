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
const int MAX = 5e5+10;
const ll MAX2 = 11;
const ll MOD = 998244353;
const ll MOD2 = 1000005329;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 2000;

ll tc,n,k,m,x[MAX],le,ri,mid,ans,tgt,l[MAX],r[MAX],d[MAX],res,sz,ls,pos,a,b;
priority_queue<pll, vector<pll>, greater<pll>> pq;
bool vis[MAX];
vector<pll> v;

int main(){
//	cout<<fixed<<setprecision(10);
//    freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m>>k>>tgt;
    rep(i,1,n)cin>>x[i];
    sort(x+1,x+1+n);
    reverse(x+1,x+1+n);
    rep(i,1,k)cin>>l[i]>>r[i]>>d[i], --l[i];
    vis[0] = 1;
    le = 1, ri = n;
    while(le<=ri){
    	mid = le+ri>>1;
    	while(!pq.empty())pq.pop();
    	v.clear();
    	rep(i,1,k)if(d[i]>x[mid])vis[i] = 1, pq.push({l[i],i}), v.pb({r[i],i});
    	if(v.empty()){ans = mid, le = mid+1; continue;}
    	sort(all(v));
    	pq.push({m,0});
    	pos = ls = res = pq.top().fi;
    	sz = v.size()-1;
    	rep(i,0,sz){
    		res+= v[i].fi - pos;
    		pos = v[i].fi;
    		vis[v[i].se] = 0;
    		if(i!=sz){
    			while(!vis[pq.top().se])pq.pop();
    			a = pq.top().fi;
    			if(a>pos)res+= pos-ls, res+= a-ls, ls = pos = a;
			}
		}
		res+= m+pos-ls-ls+1;
//		cout<<">> "<<mid<<' '<<res<<endl;
    	if(res<=tgt)ans = mid, le = mid+1;
    	else ri = mid-1;
	}
	cout<<ans<<endl;
    return 0;
}