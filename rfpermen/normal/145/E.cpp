#include <bits/stdc++.h>
 
#pragma GCC optimize("O3")
using namespace std;
#define ll long long
#define ull unsigned long long
#define rep(i,n,N) for(int i=n;i<=N;++i)
#define rap(i,n,N) for(int i=n;i>=N;--i)
#define mp make_pair
#define pb push_back
#define pob pop_back
#define pf push_front
#define pof pop_front
#define fi first
#define se second
//#define ff fi.fi
//#define fs fi.se
//#define sf se.fi
//#define ss se.se
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
const int MAX = 1e6+5;
const ll MAX2 = 11;
const ll MOD = 1000000007;
const ll MOD2 = 1000005329;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 2000;

struct tr{
	int nol,stu,cnt,rev;
}tree[1<<21];
bool lz[1<<21];

int n,q,a,b;
char c[MAX];
string ty;

inline void f(int &id,int &le,int &ri){
	swap(tree[id].nol,tree[id].stu);
	swap(tree[id].cnt,tree[id].rev);
	if(le!=ri)lz[lc]^=1, lz[rc]^=1;
	lz[id] = 0;
	return;
}
inline tr merge(tr a,tr b){
	tr ret;
	ret.nol = a.nol+b.nol, ret.stu = a.stu+b.stu;
	ret.cnt = max(a.nol+b.cnt,a.cnt+b.stu), ret.rev = max(a.stu+b.rev, a.rev+b.nol);
	return ret;
}
void build(int id,int le,int ri){
	if(le==ri){
		if(c[le]=='4')tree[id].cnt = tree[id].rev = tree[id].nol = 1;
		else tree[id].cnt = tree[id].rev = tree[id].stu = 1;
		return;
	}
	int mid = le+ri>>1;
	build(lc,le,mid), build(rc,mid+1,ri);
	tree[id] = merge(tree[lc],tree[rc]);
	return;
}
void upd(int id,int le,int ri){
	if(lz[id])f(id,le,ri);
	if(le>b||ri<a)return;
	if(le>=a&&ri<=b){f(id,le,ri); return;}
	int mid = le+ri>>1;
	upd(lc,le,mid), upd(rc,mid+1,ri);
	tree[id] = merge(tree[lc],tree[rc]);
	return;
}


int main(){
//	cout<<fixed<<setprecision(10);
//    freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>q;
    rep(i,1,n)cin>>c[i];
    build(1,1,n);
    while(q--){
    	cin>>ty;
    	if(ty[0]=='c')cout<<tree[1].cnt<<endl;
    	else cin>>a>>b, upd(1,1,n);
	}
    return 0;
}