#include <bits/stdc++.h>

#pragma GCC optimize("O2")
using namespace std;
#define ll long long
#define rep(i,n,N) for(ll i=n;i<=N;i++)
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
#define endl "\n"
const ll MAX=2e5+5;
const int MOD=1000000000 + 7;
const ll INF=1e18;
const int nr[]={0,1,0,-1,1,1,-1,-1,  2,2,-2,-2,1,1,-1,-1};
const int nc[]={1,0,-1,0,1,-1,1,-1,  1,-1,1,-1,2,-2,2,-2};

int n,q,x[MAX],hs[MAX],tree[3*MAX],lz[3*MAX],a,b,c,val,k;
pii z[MAX];
pair<int,bool> y[MAX];
vector<int> v[MAX];

inline void f(int &id,int &le,int &ri){
	if(le==ri){
		if(y[le].se)y[le].fi+=lz[id];
		else y[le].fi-=lz[id];
	}
	else {
		lz[id*2]+=lz[id];
		lz[id*2+1]+=lz[id];
	}
	lz[id] = 0;
	return;
}

void upd(int id,int le,int ri){
	if(lz[id]!=0)f(id,le,ri);
	
	if(le>b || ri<a)return;
	if(le>=a && ri<=b){lz[id] = val; f(id,le,ri); return;}
	
	int mid = (le+ri)/2;
	upd(id*2,le,mid);
	upd(id*2+1,mid+1,ri);
	return;
}

int que(int id,int le,int ri){
	if(lz[id]!=0)f(id,le,ri);
	
	if(le==ri)return y[le].fi;
	
	int mid = (le+ri)/2;
	if(a<=mid)return que(id*2,le,mid);
	return que(id*2+1,mid+1,ri);
}

void dfs(int id,bool st){
	k++;
//	cout<<" ---> "<<id<<" "<<k<<endl;
	z[k].fi = k;
	y[k] = {x[id],st};
	hs[id] = k;
	
	for(auto i:v[id]){
		if(hs[i])continue;
		dfs(i,st^1);
	}
	
	z[hs[id]].se = k;
	return;
}

int main(){
    //cout<<fixed<<setprecision(9);
    //freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>q;
    rep(i,1,n)cin>>x[i];
    rep(i,2,n){
    	cin>>a>>b;
    	v[a].pb(b);
    	v[b].pb(a);
	}
	dfs(1,1);
//	rep(i,1,n)cout<<hs[i]<<" "; cout<<endl;
	while(q--){
		cin>>c>>a;
		a = hs[a];
//		cout<<"Hash = "<<a<<endl;
		if(c==1){
			cin>>val;
			b = z[a].se;
			if(!y[a].se)val*=-1;
			upd(1,1,n);
		}
		else {
			cout<<que(1,1,n)<<endl;
		}
	}
    return 0;
}