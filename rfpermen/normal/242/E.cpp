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
#define pdd pair<double,double>
#define endl "\n"
const ll MAX=1e5+5;
const ll MAX2 = 11;
const int MOD=1000000000 + 7;
const ll INF=20000;
const int nr[]={1,0,-1,0,1,1,-1,-1};
const int nc[]={0,1,0,-1,1,-1,1,-1};

int n,x[MAX],tree[3*MAX][20],a,b,q,c,val,bit;
ll ans;
bool lz[3*MAX][20];

inline void f(int &id,int &le,int &ri){
	tree[id][bit] = (ri-le+1) - tree[id][bit];
	if(le!=ri){
		lz[id*2][bit]^=1;
		lz[id*2+1][bit]^=1;
	}
	lz[id][bit] = 0;
	return;
}

void build(int id,int le,int ri){
	if(le==ri){
		if(x[le]&(1<<bit))tree[id][bit] = 1;
		return;
	}
	int mid = (le+ri)/2;
	build(id*2,le,mid);
	build(id*2+1,mid+1,ri);
	tree[id][bit] = tree[id*2][bit] + tree[id*2+1][bit];
	return;
}

void upd(int id,int le,int ri){
	if(lz[id][bit])f(id,le,ri);
	if(le>b || ri<a)return;
	if(le>=a && ri<=b){lz[id][bit] = 1; f(id,le,ri); return;}
	int mid = (le+ri)/2;
	upd(id*2,le,mid);
	upd(id*2+1,mid+1,ri);
	tree[id][bit] = tree[id*2][bit] + tree[id*2+1][bit];
	return;
}

int que(int id,int le,int ri){
	if(lz[id][bit])f(id,le,ri);
	if(le>b || ri<a)return 0;
	if(le>=a && ri<=b)return tree[id][bit];
	
	int mid = (le+ri)/2;
	return que(id*2,le,mid) + que(id*2+1,mid+1,ri);
}

int main(){
	cout<<fixed<<setprecision(6);
    //freopen("input.txt", "r", stdin);
	//freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    rep(i,1,n)cin>>x[i];
    rep(i,0,19)bit = i, build(1,1,n);
    a = 1, b = n;
    cin>>q;
    while(q--){
    	cin>>c>>a>>b;
    	if(c==1){
    		ans = 0;
    		rep(i,0,19)bit = i, ans+=(ll)que(1,1,n)*(1<<i);
    		cout<<ans<<endl;
		}
		else {
    		cin>>val;
			rep(i,0,19)if(val&(1<<i))bit = i, upd(1,1,n);
		}
	}
    return 0;
}