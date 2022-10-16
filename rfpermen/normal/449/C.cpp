#include <bits/stdc++.h>
 
#pragma GCC optimize("O3")
#pragma GCC target("tune=native")
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
#define pllll pair<pll,pll>
#define piii pair<ll,pii>
#define piiii pair<pii,pii>
#define psi pair<string,int>
#define endl '\n'
const int MAX = 1e5+5;
const ll MOD = 1000000007;
const ll MOD2 = 2010405347;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 600;

int n,nw,cl[MAX],a,b;
bool p[MAX],st[MAX];
set<int> v[MAX];
vector<pii> ans;

int main(){
//	cout<<fixed<<setprecision(10);
// freopen("trip.in", "r", stdin);
// freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    for(int i = 2; i*i<MAX; ++i){
    	if(p[i])continue;
    	for(int j = i*i; j<MAX; j+=i)p[j] = 1;
	}
	cin>>n;
	rap(i,n,2)if(!p[i]){
		nw = i;
		while(nw<=n){
			if(!cl[nw])cl[nw] = i, v[i].insert(nw);
			else if(!st[cl[nw]]){
				v[cl[nw]].erase(nw);
				v[i].insert(nw);
				st[cl[nw]] = 1;
				cl[nw] = i;
			}
			nw+= i;
		}
		if(!(v[i].size()&1))st[i] = 1;
	}
	rep(i,1,n){
		while(v[i].size()>1){
			a = *v[i].begin();
			v[i].erase(a);
			b = *v[i].begin();
			v[i].erase(b);
			ans.pb({a,b});
		}
	}
	cout<<ans.size()<<endl;
	for(pii i:ans)cout<<i.fi<<' '<<i.se<<endl;
    return 0;
}