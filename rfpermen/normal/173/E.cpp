#include <bits/stdc++.h>
#pragma GCC optimize("O2")
using namespace std;
#define ll long long
#define rep(i,n,N) for(ll i=n;i<=N;++i)
#define rap(i,n,N) for(int i=(int)n;i>=(int)N;i--)
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
#define pii pair<int,int> 
#define pll pair<int,ll>
#define piii pair<int,pii>
#define piiii pair<pii,pii>
#define endl "\n"
const ll MAX=1e5+5;
const ll MAX2 = 11;
const int MOD=1000000000 + 7;
const ll INF=20000;
const int nr[]={1,0,-1,0,1,1,-1,-1};
const int nc[]={0,1,0,-1,1,-1,1,-1};
const double pi = acos(-1);

int n,hs[MAX],bit[MAX],tree[3*MAX],ans[MAX],ret,l,r,m,cek,a,b,k,q,sz[MAX],ls;
pii org[MAX];
piii x[MAX];
piiii que[MAX];

inline void update(int i){
	for(; i<=n; i+=(i&-i))bit[i]++;
	return;
}
inline int ty(int i){
	ret = 0;
	for(; i; i-=(i&-i))ret+=bit[i];
	return ret;
}

void upd(int id,int le,int ri){
	if(le==ri){tree[id] = sz[le]; return;}
	int mid = (le+ri)/2;
	if(a<=mid)upd(id*2,le,mid);
	else upd(id*2+1,mid+1,ri);
	tree[id] = max(tree[id*2],tree[id*2+1]);
	return;
}
int query(int id,int le,int ri){
	if(le>b || ri<a)return -1;
	if(le>=a && ri<=b)return tree[id];
	int mid = (le+ri)/2;
	return max(query(id*2,le,mid),query(id*2+1,mid+1,ri));
}

int main(){
	cout<<fixed<<setprecision(10);
    //freopen("input.txt", "r", stdin);
	//freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>k;
    rep(i,1,n)cin>>x[i].sf, x[i].ss = i;
    rep(i,1,n)cin>>x[i].fi;
    sort(x+1,x+1+n);
    rep(i,1,n)hs[x[i].ss] = i, org[i] = {x[i].sf,i};
    sort(org+1,org+1+n);
//    cout<<endl;
//	rep(i,1,n)cout<<"org ke-"<<i<<" = "<<x[i].fi<<" "<<x[i].sf<<endl;
//	cout<<endl;
    ls = 1;
    rep(i,1,n){
    	while(ls!=n+1, org[i].fi==org[ls].fi)update(org[ls].se), ls++;
//    	cout<<"res "<<org[i].fi<<" "<<x[org[i].se].fi<<endl;//<<" "<<ls<<i<<" "
    	cek = x[org[i].se].fi-k;
    	l = 1, r = n;
    	while(l<=r){
    		m = (l+r)/2;
    		if(x[m].fi>=cek)a = m, r = m-1;
    		else l = m+1;
		}
    	cek = x[org[i].se].fi+k;
    	l = 1, r = n;
		while(l<=r){
			m = (l+r)/2;
			if(x[m].fi>cek)r = m-1;
			else b = m, l = m+1;
		}
		sz[org[i].se] = ty(b)-ty(a-1);
//		cout<<"range = "<<a<<" "<<b<<" dan hasilnya = "<<sz[org[i].se]<<endl<<endl;
	}
	cin>>q;
	rep(i,1,q){
		cin>>a>>b;
		a = hs[a], b = hs[b];
		que[i].ff = max(x[a].sf,x[b].sf);
		que[i].fs = i;
		cek = max(x[a].fi,x[b].fi)-k;
		l = 1, r = n;
		while(l<=r){
			m = (l+r)/2;
			if(x[m].fi>=cek)ret = m, r = m-1;
			else l = m+1;
		}
		que[i].sf = ret;
		cek = min(x[a].fi,x[b].fi)+k;
		l = 1, r = n;
		while(l<=r){
			m = (l+r)/2;
			if(x[m].fi>cek)r = m-1;
			else ret = m, l = m+1;
		}
		que[i].ss = ret;
	}
	memset(tree,-1,sizeof tree);
	sort(que+1,que+1+q);
	reverse(que+1,que+1+q);
	ls = n;
	rep(i,1,q){
		while(ls && org[ls].fi>=que[i].ff){
			a = org[ls].se;
			upd(1,1,n);
			ls--;
		}
//		cout<<que[i].ff<<" "<<que[i].fs<<" "<<que[i].sf<<" "<<que[i].ss<<" , udh berapa org "<<n-ls<<" "<<tree[1]<<endl;
		a = que[i].sf, b = que[i].ss;
		ans[que[i].fs] = query(1,1,n);
	}
	rep(i,1,q)cout<<ans[i]<<endl;
    return 0;
}