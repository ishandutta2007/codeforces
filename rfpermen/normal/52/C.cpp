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
const int MAX=2e5+5;
const ll MAX2 = 11;
const int MOD=1000000000 + 7;
const ll INF=20000;
const int dr[]={1,0,-1,0,1,1,-1,-1};
const int dc[]={0,1,0,-1,1,-1,1,-1};
const double pi = acos(-1);

int n,m,x[MAX],cnt,q[3],a,b,v,tmp;
ll tree[3*MAX],lz[3*MAX];
bool neg;
string s;

inline void f(int &id,int &le,int &ri){
	tree[id]+=lz[id];
	if(le!=ri){
		lz[id*2]+=lz[id];
		lz[id*2+1]+=lz[id];
	}
	lz[id] = 0;
	return;
}

void build(int id,int le,int ri){
	if(le==ri){
		tree[id] = x[le];
		return;
	}
	int mid = (le+ri)/2;
	build(id*2,le,mid);
	build(id*2+1,mid+1,ri);
	tree[id] = min(tree[id*2],tree[id*2+1]);
}

void upd(int id,int le,int ri,int l,int r){
	if(lz[id]!=0)f(id,le,ri);
	if(le>r || ri<l)return;
	if(le>=l && ri<=r){lz[id] = v; f(id,le,ri); return;}
	int mid = (le+ri)/2;
	upd(id*2,le,mid,l,r);
	upd(id*2+1,mid+1,ri,l,r);
	tree[id] = min(tree[id*2],tree[id*2+1]);
}

ll que(int id,int le,int ri,int l,int r){
	if(lz[id]!=0)f(id,le,ri);
	if(le>r || ri<l)return 1e18;
	if(le>=l && ri<=r)return tree[id];
	int mid = (le+ri)/2;
	ll t1 = que(id*2,le,mid,l,r);
	ll t2 = que(id*2+1,mid+1,ri,l,r);
	return min(t1,t2);
}

int main(){
//	cout<<fixed<<setprecision(10);
    //freopen("input.txt", "r", stdin);
	//freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n; n--;
    rep(i,0,n)cin>>x[i];
    build(1,0,n);
    cin>>m;
    cin.ignore(1);
    while(m--){
    	getline(cin,s);
    	cnt = 0, s+=' ';
		for(auto i:s){
			if(i==' '){
				if(neg)tmp*=-1;
				q[cnt++] = tmp;
				tmp = neg = 0;
			}
			else if(i=='-')neg=1;
			else tmp = tmp*10 + i-'0';
		}
		a = q[0], b = q[1], v = q[2];
		if(cnt == 2){
			if(a<=b)cout<<que(1,0,n,a,b)<<endl;
			else cout<<min(que(1,0,n,0,b),que(1,0,n,a,n))<<endl;
		}
		else {
			if(a<=b)upd(1,0,n,a,b);
			else upd(1,0,n,0,b), upd(1,0,n,a,n);
		}
	}
    return 0;
}