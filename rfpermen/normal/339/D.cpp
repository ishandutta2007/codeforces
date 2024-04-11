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
#define sf se.fi
#define ss se.se
#define pii pair<int,int> 
#define pll pair<ll,ll>
#define piii pair<int,pii>
#define piiii pair<piii,pii>
#define endl "\n"
const int MAX=131072+5;
const ll MAX2 = 11;
const int MOD=1000000000 + 7;
const ll INF=20000;
const int dr[]={1,0,-1,0,1,1,-1,-1};
const int dc[]={0,1,0,-1,1,-1,1,-1};
const double pi = acos(-1);

int n,q,x[MAX],tree[2*MAX],sz,a,v;
bool st;

void build(int id,int l,int r,bool nw){
	if(l==r){
		tree[id] = x[l];
		return;
	}
	int m = (l+r)/2;
	build(id*2,l,m,nw^1);
	build(id*2+1,m+1,r,nw^1);
	if(nw)tree[id] = tree[id*2]|tree[id*2+1];
	else  tree[id] = tree[id*2]^tree[id*2+1];
	return;
}

void upd(int id,int l,int r,bool nw){
	if(l==r){
		tree[id] = v;
		return;
	}
	int m = (l+r)/2;
	if(a<=m)upd(id*2,l,m,nw^1);
	else upd(id*2+1,m+1,r,nw^1);
	if(nw)tree[id] = tree[id*2]|tree[id*2+1];
	else  tree[id] = tree[id*2]^tree[id*2+1];
	return;
}

int main(){
//	cout<<fixed<<setprecision(10);
    //freopen("input.txt", "r", stdin);
	//freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>sz>>q; st = sz&1, n = 1;
    rep(i,1,sz)n*=2;
    rep(i,1,n)cin>>x[i];
    build(1,1,n,st);
    while(q--){
    	cin>>a>>v;
    	upd(1,1,n,st);
    	cout<<tree[1]<<endl;
	}
    return 0;
}