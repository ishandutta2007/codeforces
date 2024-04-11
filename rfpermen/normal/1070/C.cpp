#include <bits/stdc++.h>

#pragma GCC optimize("O2")
using namespace std;
#define ll long long
#define rep(i,n,N) for(int i=n;i<=N;i++)
#define rap(i,n,N) for(int i=(int)n;i>=(int)N;i--)
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
#define pii pair<int,int> 
#define pll pair<ll,ll>
#define piii pair<int,pii>
#define endl "\n"
const int MAX = 1e6+5;
const int MOD=1000000000 + 7;
const ll INF=1e18;
const int nr[]={0,1,0,-1,1,1,-1,-1,  2,2,-2,-2,1,1,-1,-1};
const int nc[]={1,0,-1,0,1,-1,1,-1,  1,-1,1,-1,2,-2,2,-2};

const int mx = 1e6;
int n,m,k,l,r,c,p,id,rem,val,a;
ll ans,ret;
piii x[2*MAX];
pll tree[4*MAX];

void upd(int id,int le,int ri){
	if(le==ri){
		tree[id].fi+=val;
		tree[id].se = tree[id].fi*le;
		return;
	}
	int mid = (le+ri)/2;
	if(a<=mid)upd(id*2,le,mid);
	else upd(id*2+1,mid+1,ri);
	tree[id] = {tree[id*2].fi+tree[id*2+1].fi,tree[id*2].se+tree[id*2+1].se};
	return;
}
ll que(int id,int le,int ri){
	if(!rem)return 0;
	if(le==ri){
		ret = min((ll)rem,tree[id].fi)*le;
		rem-= min((ll)rem,tree[id].fi);
		return ret;
	}
	if(tree[id].fi<=rem)return rem-=tree[id].fi, tree[id].se;
	int mid = (le+ri)/2;
	return que(id*2,le,mid) + que(id*2+1,mid+1,ri);
}

int main(){
//    cout<<fixed<<setprecision(9);
//    freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>k>>m;
    while(m--){
    	cin>>l>>r>>c>>p;
    	x[++id] = {l,{c,p}};
    	x[++id] = {r+1,{-c,p}};
	}
	sort(x+1,x+1+id);
	id = 1;
	rep(i,1,n){
		while(x[id].fi==i){
			a = x[id].ss;
			val = x[id].sf;
			upd(1,1,mx);
			id++;
		}
		rem = k;
		ans += que(1,1,mx);
	}
	cout<<ans<<endl;
    return 0;
}