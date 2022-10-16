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
#define piii pair<int,pii>
#define piiii pair<pii,pii>
#define psi pair<string,int>
#define endl '\n'
const int MAX = 1e5+5;
const ll MAX2 = 11;
const int MOD = 1000000007;
const ll MOD2 = 1000005329;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const long double EPS = 1e-18;
const int block = 2000;

int n,m,z,k,a,b,p[MAX],fa,fb;
ll sz[MAX],c;
priority_queue<pll, vector<pll>, greater<pll>> pq;

int par(int z){
	if(p[z]==z)return z;
	return p[z] = par(p[z]);
}

int main(){
//	cout<<fixed<<setprecision(10);
//    freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m>>z>>k;
    rep(i,1,n)p[i] = i;
    while(m--){
    	cin>>a>>b>>c;
    	fa = a, fb = b;
    	a = par(a), b = par(b);
    	if(a==b){sz[a]+=c; continue;}
    	p[b] = a;
    	sz[a]+=sz[b]+c;
	}
	rep(i,1,n)if(par(i)==i)pq.push({sz[i],i});
	if(pq.size()<k || (pq.size()==k && k==n && z) || pq.size()>z+k)return cout<<"NO\n",0;
	cout<<"YES\n";
	while(pq.size()!=k){
		a = pq.top().se; pq.pop();
		b = pq.top().se; pq.pop();
		--z;
		cout<<a<<' '<<b<<endl;
    	fa = a, fb = b;
    	p[b] = a;
    	sz[a]+= sz[a]+sz[b]+sz[b]+1;
    	pq.push({sz[a],a});
	}
	rep(i,1,z)cout<<fa<<' '<<fb<<endl;
    return 0;
}