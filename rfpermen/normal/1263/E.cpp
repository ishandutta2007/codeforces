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
#define ff fi.fi
#define fs fi.se
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
#define pllll pair<pll,pll>
#define piii pair<int,pii>
#define piiii pair<pii,pii>
#define psi pair<string,int>
#define endl '\n'
const int MAX = 1e6+5;
const ll MAX2 = 11;
const ll MOD = 998244353;
const ll MOD2 = 1000005329;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 2000;

int n = 1000000,nw,cnt,ls,ans,val,q,lz[1<<21];
char x[MAX],c;
pii tree[1<<21];

inline void f(int id,int le,int ri){
	tree[id].fi+=lz[id], tree[id].se+=lz[id];
	if(le!=ri)lz[lc]+=lz[id], lz[rc]+=lz[id];
	lz[id] = 0;
	return;
}

void upd(int id,int le,int ri){
	if(lz[id])f(id,le,ri);
	if(ri<nw)return;
	if(le>=nw){
		lz[id] = val;
		f(id,le,ri);
		return;
	}
	int mid = le+ri>>1;
	upd(lc,le,mid), upd(rc,mid+1,ri);
	tree[id].fi = min(tree[lc].fi, tree[rc].fi);
	tree[id].se = max(tree[lc].se, tree[rc].se);
	return;
}

inline void pr(){
	if(ls>=0&&cnt==0)cout<<ans<<' ';
    else cout<<"-1 ";
    return;
}

int main(){
//	cout<<fixed<<setprecision(10);
//    freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>q;
    nw = 1;
    while(q--){
    	cin>>c;
    	if(c=='R')++nw;
		else if(c=='L')nw = max(1,nw-1);
		else if(c=='('){
			if(x[nw]=='(');
			else if(x[nw]==')'){
				cnt+=2;
				val = 2;
				upd(1,1,n);
				ls = tree[1].fi, ans = tree[1].se;
			}
			else {
				cnt+=1;
				val = 1;
				upd(1,1,n);
				ls = tree[1].fi, ans = tree[1].se;
			}
			x[nw] = c;
		}
		else if(c==')'){
			if(x[nw]=='('){
				cnt-=2;
				val = -2;
				upd(1,1,n);
				ls = tree[1].fi, ans = tree[1].se;
			}
			else if(x[nw]==')');
			else {
				cnt-=1;
				val = -1;
				upd(1,1,n);
				ls = tree[1].fi, ans = tree[1].se;
			}
			x[nw] = c;
		}
		else {
			if(x[nw]=='('){
				cnt-=1;
				val = -1;
				upd(1,1,n);
				ls = tree[1].fi, ans = tree[1].se;
			}
			else if(x[nw]==')'){
				cnt+=1;
				val = 1;
				upd(1,1,n);
				ls = tree[1].fi, ans = tree[1].se;
			}
			x[nw] = c;
		}
		pr();
	}
    return 0;
}