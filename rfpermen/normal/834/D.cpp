#include <bits/stdc++.h>
 
#pragma GCC optimize("O2", "unroll-loops")
using namespace std;
#define ll long long
#define ull unsigned long long
#define rep(i,n,N) for(ll i=n;i<=N;++i)
#define rap(i,n,N) for(ll i=n;i>=N;--i)
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
#define db(x) cout << ">>>>>> " << #x << " -> " << x << endl;
#define all(x) x.begin(),x.end()
#define pii pair<int,int> 
#define pll pair<ll,ll>
#define piii pair<int,pii>
#define plll pair<ll,pii>
#define piiii pair<pii,pii>
#define psi pair<string,int>
#define endl "\n"
const int MAX = 35e3+5;
const ll MAX2 = 11;
const ll MOD = 1000000007;
const ll INF = 1e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 2000;

struct tr{
	int cnt,le,ri;
}tree[MAX*32];

int n,k,x,dp[55][MAX],rt[MAX],id,ls[MAX],val,tmp;

void upd(int ls,int nw,int le,int ri,int tgt){
	tree[nw] = tree[ls];
	if(le==ri){tree[nw].cnt = val; return;}
	int mid = le+ri>>1;
	if(tgt<=mid)tmp = tree[ls].le, tree[nw].le = ++id, upd(tmp,id,le,mid,tgt);
	else tmp = tree[ls].ri, tree[nw].ri = ++id, upd(tmp,id,mid+1,ri,tgt);
	tree[nw].cnt = tree[tree[nw].le].cnt + tree[tree[nw].ri].cnt;
	return;
}

int que(int nw,int le,int ri,int tgt){
	if(le>=tgt)return tree[nw].cnt;
	int mid = le+ri>>1;
	if(mid<tgt)return que(tree[nw].ri,mid+1,ri,tgt);
	return que(tree[nw].le,le,mid,tgt)+que(tree[nw].ri,mid+1,ri,tgt);
}

void f(int rem,int l,int r,int optl,int optr){
	if(l>r)return;
	int mid = l+r>>1, opt = 0, c, optid;
	for(int i = optl; i<=mid && i<=optr; ++i){
		c = que(rt[mid],1,n,i) + dp[rem-1][i-1];
		if(c >= opt){
			opt = c;
			optid = i;
		}
	}
	dp[rem][mid] = opt;
	f(rem, l, mid-1, optl, optid);
	f(rem, mid+1, r, optid, optr);
}

int main(){
//	cout<<fixed<<setprecision(15);
//    freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>k;
    rep(i,1,n){
    	cin>>x;
    	rt[i] = ++id;
    	val = 1, upd(rt[i-1],rt[i],1,n,i);
    	if(ls[x])val = 0, upd(rt[i],rt[i],1,n,ls[x]);
    	ls[x] = i;
//    	db(que(rt[i],1,n,1));
	}
    rep(i,1,k)f(i,i,n,i,n);
    cout<<dp[k][n]<<endl;
	return 0;
}