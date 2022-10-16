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
const int MAX = 2e5+5;
const ll MAX2 = 11;
const ll MOD = 1000000007;
const ll MOD2 = 1000005329;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 2000;
 
int n,q,p[MAX][62],hs[128],id,tree[1<<19],a,b,k;
string s;
bool st[MAX];
char c;

int par(int z){
	if(p[z][id]==z)return z;
	return p[z][id] = par(p[z][id]);
}

void build(int id,int le,int ri){
	if(le==ri){tree[id] = 1; return;}
	int mid = le+ri>>1;
	build(lc,le,mid), build(rc,mid+1,ri);
	tree[id] = tree[lc] + tree[rc];
	return;
}

void upd(int id,int le,int ri){
	if(le==ri){tree[id] = 0; return;}
	int mid = le+ri>>1;
	if(a<=mid)upd(lc,le,mid);
	else upd(rc,mid+1,ri);
	tree[id] = tree[lc] + tree[rc];
	return;
}

int que(int id,int le,int ri){
	if(le==ri)return le;
	int mid = le+ri>>1;
	if(tree[lc]>=k)return que(lc,le,mid);
	return k-=tree[lc], que(rc,mid+1,ri);
}
 
int main(){
//	cout<<fixed<<setprecision(4);
//    freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    rep(i,'0','9')hs[i] = id++;
    rep(i,'a','z')hs[i] = id++;
    rep(i,'A','Z')hs[i] = id++;
    cin>>n>>q>>s;
    build(1,1,n);
    s = 'o'+s;
    rep(i,0,61)p[n+1][i] = n+1;
    rep(i,1,n)p[i][hs[s[i]]] = i;
	rap(i,n,1){
		rep(j,0,61){
			if(!p[i][j])p[i][j] = p[i+1][j];
		}
	}
	while(q--){
		cin>>a>>b>>c;
		k = a, a = que(1,1,n);
		k = b, b = que(1,1,n);
		id = hs[c];
		a = par(a);
		while(a<=b){
			p[a][id] = a+1;
			st[a] = 1;
			upd(1,1,n);
			a = par(a);
		}
	}
	rep(i,1,n)if(!st[i])cout<<s[i]; cout<<endl;
    return 0;
}