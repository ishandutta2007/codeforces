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
const int MAX = 1e4+5;
const ll MAX2 = 11;
const ll MOD = 1000000007;
const ll MOD2 = 1000000006;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 316;

int n,a,b,id,bit[MAX];
ll ans;
piii x[MAX],y[MAX];
vector<pii> del;

inline void upd(int i,int val){
	for(; i<=10001; i+=i&-i)bit[i]+= val;
	return;
}

int ret;
inline int que(int i){
	ret = 0;
	for(; i>0; i-=i&-i)ret+= bit[i];
	return ret;
}

inline int q(int a,int b){
	if(a>b)return 0;
	return que(b) - que(a-1);
}

int main(){
//	cout<<fixed<<setprecision(2);
//    freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int x1,x2,y1,y2;
    cin>>n;
    while(n--){
    	cin>>x1>>y1>>x2>>y2;
    	if(x1>x2)swap(x1,x2);
    	if(y1>y2)swap(y1,y2);
    	y1+= 5001, y2+= 5001;
    	if(y1==y2)x[++a] = {x1,{x2,y1}};
		else y[++b] = {x1,{y1,y2}};
	}
	sort(y+1,y+1+b);
	
	rep(i,1,b){
		memset(bit,0,sizeof bit);
		del.clear();
		rep(j,1,a)if(x[j].fi<=y[i].fi)del.pb(x[j].se), upd(x[j].ss,1);
		sort(all(del));
		
		n = del.size(), id = 0;
		
		rep(j,i+1,b){
			while(id!=n&&y[j].fi>del[id].fi)upd(del[id].se,-1), ++id;
			
			ret = q(max(y[i].sf,y[j].sf),min(y[i].ss,y[j].ss));
			ans+= ret*(ret-1)>>1;
		}
	}
	
	cout<<ans<<endl;
    return 0;
}