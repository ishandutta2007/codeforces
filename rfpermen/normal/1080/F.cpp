#include <bits/stdc++.h>
 
#pragma GCC optimize("O2")
#pragma GCC optimize("unroll-loops")
 
using namespace std;
#define ll long long
#define ull unsigned long long
#define rep(i,n,N) for(ll i=n;i<=N;++i)
#define asd(i,n,N) for(int i=n;i< N;++i)
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
#define db(x) cout << ">>>> " << #x << " -> " << x << endl
#define mems(x,y) memset(x,y,sizeof x)
#define all(x) x.begin(),x.end()
#define rng() ((rand()<<16)|rand())
#define pii pair<int,int> 
#define pll pair<ll,ll>
#define plll pair<ll,pll>
#define piii pair<int,pii>
#define piiii pair<pii,pii>
#define psi pair<string,int>
//#define endl '\n'
const int MAX = 1e5+5;
const ll MAX2 = 11;
const ll MOD = 1000000007;
const ll MOD2 = 2010405347;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 555;
 
int n,m,k,l,r,a,b,ls,mn;
vector<pii> v[MAX];
vector<pii> tree[1<<18];

void build(int id,int le,int ri){
//	cout<<">> "<<id<<' '<<le<<' '<<ri<<endl;
	if(le==ri){
		sort(all(v[le]));
		reverse(all(v[le]));
		ls = mn = MOD;
		for(pii i:v[le]){
			if(i.fi==ls){
				if(mn>i.se)tree[id][tree[id].size()-1].se = mn = i.se; 
			}
			else mn = min(mn,i.se), ls = i.fi, tree[id].pb({ls,mn});
		}
		return;
	}
	int mid = le+ri>>1;
	build(lc,le,mid), build(rc,mid+1,ri);
	int n = tree[lc].size(), m = tree[rc].size();
	if(n && m){
		b = 0;
		asd(i,0,n){
			while(b!=m && tree[rc][b].fi>tree[lc][i].fi){
//				if(tree[rc][b].fi==tree[lc][i].fi)
//					tree[id].pb({tree[rc][b].fi,max(tree[rc][b].se,tree[lc][i].se)});
//				else 
				if(i!=0)
					tree[id].pb({tree[rc][b].fi,max(tree[rc][b].se,tree[lc][i-1].se)});
				++b;
			}
			if(b!=m && tree[rc][b].fi==tree[lc][i].fi)
				tree[id].pb({tree[lc][i].fi,max(tree[rc][b].se,tree[lc][i].se)}), ++b;
			else if(b==m || (b && tree[rc][b].fi<tree[lc][i].fi))
				tree[id].pb({tree[lc][i].fi,max(tree[rc][b-1].se,tree[lc][i].se)});
		}
		while(b!=m)tree[id].pb({tree[rc][b].fi,max(tree[rc][b].se,tree[lc].back().se)}), ++b;
	}
	reverse(all(tree[lc])), reverse(all(tree[rc]));
//	cout<<"_________"<<endl;
//	for(pii i:tree[lc])cout<<i.fi<<' '<<i.se<<", "; cout<<endl;
//	for(pii i:tree[rc])cout<<i.fi<<' '<<i.se<<", "; cout<<endl;
//	reverse(all(tree[id]));
//	cout<<"= "<<endl;
//	for(pii i:tree[id])cout<<i.fi<<' '<<i.se<<", "; cout<<endl;
//	reverse(all(tree[id]));
	return;
}
vector<pii>::iterator it;
bool que(int id,int le,int ri){
	if(le>b || ri<a)return true;
	if(le>=a && ri<=b){
		it = lower_bound(all(tree[id]),mp(l,0));
		return it!=tree[id].end() && (*it).se<=r;
	}
	int mid = le+ri>>1;
	return que(lc,le,mid) && que(rc,mid+1,ri);
}

int main(){
// cout<<fixed<<setprecision(6);
// freopen("trip.in", "r", stdin);
// freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m>>k;
    rep(i,1,k){
    	cin>>l>>r>>a;
    	v[a].pb({l,r});
	}
//	return 0;
	build(1,1,n);
	reverse(all(tree[1]));
//	cout<<"___________"<<endl;
//	for(pii i:tree[9])cout<<i.fi<<' '<<i.se<<endl;
//	cout<<"___________"<<endl;
//	for(pii i:tree[2])cout<<i.fi<<' '<<i.se<<endl;
//	cout<<"___________\n";
//	for(pii i:tree[3])cout<<i.fi<<' '<<i.se<<endl;
	while(m--){
		cin>>a>>b>>l>>r;
		cout<<(que(1,1,n) ? "yes" : "no")<<endl;
	}
    return 0;
}