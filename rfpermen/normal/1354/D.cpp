#include <bits/stdc++.h>
 
#pragma GCC optimize("O2")
//#pragma GCC optimize("unroll-loops")
using namespace std;
#define ll long long
#define ull unsigned long long
#define rep(i,n,N) for(ll i=n;i<=N;++i)
#define rap(i,n,N) for(ll i=n;i>=N;--i)
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
#define piii pair<int,pii>
#define piiii pair<pii,pii>
#define psi pair<string,int>
#define endl '\n'
const int MAX = 1e6+5;
const ll MAX2 = 11;
const ll MOD = 1000000007;
const ll MOD2 = 1000005329;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 2000;

int n,q,tree[1<<21],x;

void upd(int id,int le,int ri){
	if(le==ri){++tree[id]; return;}
	int mid = le+ri>>1;
	if(x<=mid)upd(lc,le,mid);
	else upd(rc,mid+1,ri);
	tree[id] = tree[lc]+tree[rc];
	return;
}

void del(int id,int le,int ri,int o){
	if(le==ri){--tree[id]; return;}
	int mid = le+ri>>1;
	if(tree[lc]>=o)del(lc,le,mid,o);
	else del(rc,mid+1,ri,o-tree[lc]);
	tree[id] = tree[lc]+tree[rc];
	return;
}

int main(){
//	cout<<fixed<<setprecision(10);
//    freopen("input.txt", "r", stdin);
//	freopen("input.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>q;
    rep(i,1,n)cin>>x, upd(1,1,n);
    while(q--){
    	cin>>x;
    	if(x>0)upd(1,1,n);
    	else del(1,1,n,-x);
	}
	if(!tree[1])cout<<"0\n";
	else {
		int id = 1, le = 1, ri = n;
		while(le!=ri){
			if(tree[lc])ri = le+ri>>1, id = lc;
			else le = (le+ri>>1)+1, id = rc;
		}
		cout<<le<<endl;
	}
    return 0;
}