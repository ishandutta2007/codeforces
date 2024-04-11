#include <bits/stdc++.h>
 
#pragma GCC optimize("O2")
#pragma GCC optimize("unroll-loops")
 
using namespace std;
#define ll long long
#define ull unsigned long long
#define rep(i,n,N) for(ll i=n;i<=N;++i)
#define asd(i,n,N) for(int i=n;i< N;++i)
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
const int MAX = 2e5+5;
const ll MAX2 = 11;
const ll MOD = 1000000007;
const ll MOD2 = 2010405347;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 555;

ll n,q,a,b,x[MAX],tree[1<<19],tgt,res,y;

void build(int id,int le,int ri){
	if(le==ri){
		tree[id] = x[le];
		return;
	}
	int mid = le+ri>>1;
	build(lc,le,mid), build(rc,mid+1,ri);
	tree[id] = tree[lc] + tree[rc];
	return;
}
void upd(int id,int le,int ri){
	if(le==ri){
		tree[id] = x[le];
		return;
	}
	int mid = le+ri>>1;
	if(a<=mid)upd(lc,le,mid);
	else upd(rc,mid+1,ri);
	tree[id] = tree[lc] + tree[rc];
	return;
}
int que(int id,int le,int ri){
	if(res>1000000000)return 0;
	if(tree[id]<tgt){
		tgt-= tree[id], res+= tree[id];
		return 0;
	}
	if(le==ri){
		res+= tree[id];
		if((x[le]<<1)==res)return le;
		tgt = res;
		return 0;
	}
	int mid = le+ri>>1;
	int ret = que(lc,le,mid);
	return ret ? ret : que(rc,mid+1,ri);
}

int main(){
// cout<<fixed<<setprecision(6);
// freopen("trip.in", "r", stdin);
// freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>q;
    rep(i,1,n)cin>>x[i];
    build(1,1,n);
    while(q--){
    	cin>>a>>b;
    	x[a] = b;
    	upd(1,1,n);
    	if(x[1]==0){cout<<"1\n"; continue;}
		
		tgt = x[1]<<1, res = 0;
		y = que(1,1,n);
		if(!y)y = -1;
		cout<<y<<endl;
	}
    return 0;
}