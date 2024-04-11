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
#define sf se.fi
#define ss se.se
#define lc (id<<1)
#define rc ((id<<1)|1)
#define db(x) cout << ">>>>>> " << #x << " -> " << x << endl;
#define all(x) x.begin(),x.end()
#define pii pair<int,int> 
#define pll pair<ll,ll>
#define piii pair<int,pii>
#define piiii pair<pii,pii>
#define psi pair<string,int>
#define endl "\n"
const int MAX=1<<18;
const ll MAX2 = 11;
const int MOD=1000000000 + 7;
const ll INF=20000;
const int dr[]={1,0,-1,0,1,1,-1,-1};
const int dc[]={0,1,0,-1,1,-1,1,-1};
const double pi = acos(-1);
const double EPS = 1e-9;

int n,x[MAX],y,a,b;
pii tree[MAX];
ll ans,res[MAX];
void build(int id,int le,int ri){
	if(le==ri){
		tree[id] = {x[le],le}; return;
	}
	int mid = le+ri>>1;
	build(lc,le,mid), build(rc,mid+1,ri);
	if(tree[lc].fi>tree[rc].fi)tree[id] = tree[lc];
	else tree[id] = tree[rc];
}
pii que(int id,int le,int ri){
	if(le>b||ri<a)return {0,0};
	if(le>=a&&ri<=b)return tree[id];
	int mid = le+ri>>1;
	pii t1 = que(lc,le,mid), t2 = que(rc,mid+1,ri);
	if(t1.fi>t2.fi)return t1;
	return t2;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    rep(i,2,n)cin>>x[i-1]; x[n] = n;
    build(1,1,n);
    rap(i,n-1,1){
    	a = i, b = x[i];
    	y = que(1,1,n).se;
    	res[i] = n-i + res[y]-(x[i]-y);
    	ans+=res[i];
	}
	cout<<ans<<endl;
    return 0;
}