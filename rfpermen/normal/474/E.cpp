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
#define plll pair<ll,pll>
#define endl "\n"
const ll MAX=1e5+5;
const int MOD=1000000000 + 7;
const ll INF=1e18;
const int nr[]={0,1,0,-1,1,1,-1,-1,  2,2,-2,-2,1,1,-1,-1};
const int nc[]={1,0,-1,0,1,-1,1,-1,  1,-1,1,-1,2,-2,2,-2};

int n,d,k,a,b,val,pos,mx,st,num[3*MAX],par[MAX];
ll y[3*MAX],ls;
pii tree[11*MAX],ty;
plll x[MAX];
map<ll,int> m;

void upd(int id,int le,int ri){
	if(le==ri){tree[id] = {val,le}; return;}
	
	int mid = (le+ri)/2;
	if(a<=mid)upd(id*2,le,mid);
	else upd(id*2+1,mid+1,ri);
	
	if(tree[id*2]>tree[id*2+1])tree[id] = tree[id*2];
	else tree[id] = tree[id*2+1];
}

pii que(int id,int le,int ri){
	if(le>b || ri<a)return {0,0};
	if(le>=a && ri<=b)return tree[id];//cout<<"tree = "<<tree[id].fi<<" "<<tree[id].se<<endl,
	
	int mid = (le+ri)/2;
	pii t1 = que(id*2,le,mid);
	pii t2 = que(id*2+1,mid+1,ri);
	if(t1.fi>t2.fi)return t1;
	return t2;
}

int main(){
    cout<<fixed<<setprecision(9);
    //freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>d;
    rep(i,1,n){
    	cin>>x[i].fi;
    	y[i*3-2] = x[i].fi;
    	y[i*3-1] = x[i].sf = max(0LL,x[i].fi-d);
    	y[i*3] = x[i].ss = x[i].fi+d;
	}
	n*=3;
	sort(y+1,y+1+n);
	ls = -1;
	rep(i,1,n)if(ls!=y[i])ls = y[i], m[ls] = ++k;
	n/=3;
	rep(i,1,n)x[i] = {m[x[i].fi],{m[x[i].sf],m[x[i].ss]}};
	rap(i,n,1){
		a = 1, b = x[i].sf;
		ty = que(1,1,k);
		val = ty.fi, pos = ty.se;
		a = x[i].ss, b = k;
		ty = que(1,1,k);
		if(ty.fi>val)val = ty.fi, pos = ty.se;
		val++;
		if(val>n)cout<<i<<" "<<x[i].fi<<endl;
		par[i] = num[pos];
		num[x[i].fi] = i;
		a = x[i].fi;
		upd(1,1,k);
		if(val>mx)mx = val, st = i;
	}
	cout<<mx<<endl;
	while(st)cout<<st<<" ", st = par[st];
cout<<endl;
    return 0;
}