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
#define ff fi.fi
#define fs fi.se
#define pii pair<int,int> 
#define pll pair<ll,ll>
#define piii pair<pii,int>
#define piiii pair<piii,pii>
#define pdd pair<double,double>
//#define endl "\n"
const ll MAX=1e5+5;
const ll MAX2 = 11;
const int MOD=1000000000 + 7;
const ll INF=20000;
const int nr[]={1,0,-1,0,1,1,-1,-1};
const int nc[]={0,1,0,-1,1,-1,1,-1};

int n,m,tree[3*MAX],lz[3*MAX],a,b,val,ret;
piii q[MAX];

inline void f(int &id,int &le,int &ri){
	tree[id]|=lz[id];
	if(le!=ri){
		lz[id*2]|=lz[id];
		lz[id*2+1]|=lz[id];
	}
	lz[id] = 0;
	return;
}

void upd(int id,int le,int ri){
	if(lz[id])f(id,le,ri);
	if(le>b || ri<a)return;
	if(le>=a && ri<=b){lz[id] = val; f(id,le,ri); return;}
	int mid = (le+ri)/2;
	upd(id*2,le,mid);
	upd(id*2+1,mid+1,ri);
	tree[id] = tree[id*2]&tree[id*2+1];
}

int que(int id,int le,int ri){
	if(lz[id])f(id,le,ri);
	if(le>b || ri<a)return ret;
	if(le>=a && ri<=b)return tree[id];
	int mid = (le+ri)/2;
	int t1 = que(id*2,le,mid);
	int t2 = que(id*2+1,mid+1,ri);
	return t1&t2;
}

int main(){
	//cout<<fixed<<setprecision(6);
    //freopen("input.txt", "r", stdin);
	//freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m;
    rep(i,1,m){
    	cin>>q[i].ff>>q[i].fs>>q[i].se;
    	a = q[i].ff, b = q[i].fs, val = q[i].se;
    	upd(1,1,n);
	}
	ret = (1<<30)-1;
	rep(i,1,m){
    	a = q[i].ff, b = q[i].fs, val = q[i].se;
    	if(val != que(1,1,n))return cout<<"NO\n",0;
	}
	cout<<"YES\n";
	rep(i,1,n){
		a = b = i;
		cout<<que(1,1,n)<<" ";
	}
    return 0;
}