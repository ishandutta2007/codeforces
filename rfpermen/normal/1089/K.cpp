#include <bits/stdc++.h>

#pragma GCC optimize("O2")
using namespace std;
#define ll long long
#define ull unsigned long long
#define rep(i,n,N) for(int i=n;i<=N;i++)
#define rap(i,n,N) for(int i=(int)n;i>=(int)N;i--)
#define mp make_pair
#define pb push_back
#define pob pop_back
#define pf push_front
#define pof pop_front
#define fi first
#define se second
#define lc (id<<1)
#define rc ((id<<1)|1)
#define db(x) cout << ">>>>>>" << #x << " -> " << x << endl;
#define all(x) x.begin(),x.end()
#define pii pair<int,int> 
#define pll pair<ll,ll>
#define piii pair<int,pii>
#define piiii pair<pii,pii>
#define psi pair<string,int>
#define endl "\n"
const int MAX=1e6+5;
const ll MAX2 = 11;
const int MOD=1000000000 + 7;
const ll INF=20000;
const int dr[]={1,0,-1,0,1,1,-1,-1};
const int dc[]={0,1,0,-1,1,-1,1,-1};
const double pi = acos(-1);
const double eps = 1e-9;

int n,q,t,val,x[MAX];
char com;
pll tree[1<<21];

void upd(int id,int le,int ri){
	if(le==ri){tree[id].fi = tree[id].se = val; return;}
	int mid = le+ri>>1;
	if(t<=mid)upd(lc,le,mid);
	else upd(rc,mid+1,ri);
	tree[id] = {tree[lc].fi + tree[rc].fi,max(tree[rc].se,tree[lc].se+tree[rc].fi-(ri-mid))};
}
pll que(int id,int le,int ri){
	if(le>t)return {0,0};
	if(ri<=t)return {tree[id].fi,tree[id].se+n-t};
	int mid = le+ri>>1;
	pll t1 = que(lc,le,mid);
	pll t2 = que(rc,mid+1,ri);
	return {t1.fi + t2.fi,max(t2.se,t1.se+t2.fi-(ri-mid))};
}

int main(){
//	cout<<fixed<<setprecision(2);
//    freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	n = 1000000;
    cin>>q;
    rep(i,1,q){
    	cin>>com>>t;
    	if(com=='+'){
    		cin>>val;
    		upd(1,1,n);
    		x[i] = t;
		}
		else if(com=='-'){
			val = 0, t = x[t];
			upd(1,1,n);
		}
		else cout<<que(1,1,n).se<<endl;
	}
    return 0;
}