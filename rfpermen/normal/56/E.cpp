#include <bits/stdc++.h>
 
#pragma GCC optimize("O3")
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
const int MAX = 1e5+5;
const ll MAX2 = 11;
const ll MOD = 1000000007;
const ll MOD2 = 1000005329;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 2000;

int n,ans[MAX],tree[1<<18],tgt,res,a,b,val;
piii x[MAX];

void upd(int id,int le,int ri){
	if(le==ri){
		tree[id] = val;
		return;
	}
	int mid = le+ri>>1;
	if(a<=mid)upd(lc,le,mid);
	else upd(rc,mid+1,ri);
	tree[id] = max(tree[lc],tree[rc]);
	return;
}

int que(int id,int le,int ri){
	if(le>b||ri<a)return 0;
	if(le>=a&&ri<=b)return tree[id];
	int mid = le+ri>>1;
	return max(que(lc,le,mid),que(rc,mid+1,ri));
}
 
int main(){
//	cout<<fixed<<setprecision(4);
//    freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int le,ri,mid;
    cin>>n;
    rep(i,1,n)cin>>x[i].fi>>x[i].sf, x[i].ss = i;
    sort(x+1,x+1+n);
    rap(i,n,1){
    	tgt = x[i].fi+x[i].sf;
    	a = le = i, ri = n;
    	while(le<=ri){
    		mid = le+ri>>1;
    		if(x[mid].fi<tgt)b = mid, le = mid+1;
    		else ri = mid-1;
		}
		val = max(que(1,1,n),(int)i);
		upd(1,1,n);
		ans[x[i].ss] = val-i+1;
	}
	rep(i,1,n)cout<<ans[i]<<' '; cout<<endl;
    return 0;
}