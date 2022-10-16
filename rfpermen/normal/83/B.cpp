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
const int block = 2000;
 
ll n,k,sz,id,mn,nw,y[MAX];
pll x[MAX];
bool vis[MAX];
queue<int> q;
 
int main(){
//	cout<<fixed<<setprecision(10);
//    freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    ll tm;
    cin>>n>>k;
    rep(i,1,n)cin>>y[i], x[i] = {y[i],i};
    sort(x+1,x+1+n);
    sz = n, tm = id = 1;
    while(k>sz&&sz){
    	if(x[id].fi==tm){
    		k-=sz;
    		while(x[id].fi==tm)vis[x[id].se] = 1, ++id, --sz;
    		++tm;
		}
		else {
			if(k/sz < x[id].fi - tm){
				tm+= k/sz;
				k%= sz;
			}
			else {
				k-= (x[id].fi - tm)*sz;
				tm = x[id].fi;
			}
		}
	}
	if(!sz)return cout<<"-1\n",0;
	rep(i,1,n)if(!vis[i])q.push(i);
	while(k){
		--k;
		nw = q.front(); q.pop();
		if(y[nw]!=tm)q.push(nw);
	}
	while(!q.empty())cout<<q.front()<<' ', q.pop();
    return 0;
}