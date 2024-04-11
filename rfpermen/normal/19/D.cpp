#include <bits/stdc++.h>
 
#pragma GCC optimize("O2")
#pragma GCC optimize("unroll-loops")
 
using namespace std;
#define ll long long
#define ull unsigned long long
#define rep(i,n,N) for(int i=n;i<=N;++i)
#define asd(i,n,N) for(int i=n;i< N;++i)
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
#define db(x) cout << ">>>> " << #x << " -> " << x << endl
#define mems(x,y) memset(x,y,sizeof x)
#define all(x) x.begin(),x.end()
#define pii pair<int,int> 
#define pll pair<ll,ll>
#define plll pair<pll,ll>
#define piii pair<pii,int>
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
const int block = 555;
 
int n,a,b,ty[MAX],x[MAX],y[MAX],chx[MAX],chy[MAX],id,tree[1<<19],val;
map<int,int> hx,hy;
set<int> cx[MAX];
string s;

void upd(int id,int le,int ri){
	if(le==ri){tree[id] = val; return;}
	int mid = le+ri>>1;
	if(a<=mid)upd(lc,le,mid);
	else upd(rc,mid+1,ri);
	tree[id] = max(tree[lc],tree[rc]);
	return;
}

int que(int id,int le,int ri){
	if(tree[id]<val)return -1;
	if(le==ri)return le;
	int mid = le+ri>>1;
	if(a<=mid){
		int t1 = que(lc,le,mid);
		if(t1!=-1)return t1;
	}
	return que(rc,mid+1,ri);
}

int main(){
//	cout<<fixed<<setprecision(10);
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    rep(i,1,n){
    	cin>>s>>x[i]>>y[i];
    	if(s[0]=='a')ty[i] = 1;
    	else if(s[0]=='r')ty[i] = -1;
    	else ++x[i], ++y[i];
    	hx[x[i]], hy[y[i]];
	}
	for(auto &i:hy)i.se = ++id, chy[id] = i.fi;
	id = 0;
	for(auto &i:hx)i.se = ++id, chx[id] = i.fi;
	rep(i,1,n){
		x[i] = hx[x[i]], y[i] = hy[y[i]];
		a = x[i], val = y[i];
//		cout<<">> "<<a<<' '<<val<<endl;
		if(ty[i]==1){
			cx[a].insert(val);
			if(*cx[a].rbegin()==val)upd(1,1,id);
		}
		else if(ty[i]==-1){
			if(*cx[a].rbegin()==val){
				cx[a].erase(val);
				
				if(cx[a].empty())val = 0;
				else val = *cx[a].rbegin();
				upd(1,1,id);
			}
			else cx[a].erase(val);
		}
		else {
			b = que(1,1,id);
//			db(b);
//			db(*cx[b].lower_bound(val));
			if(b==-1)cout<<"-1\n";
			else cout<<chx[b]<<' '<<chy[*cx[b].lower_bound(val)]<<endl;
		}
	}
	return 0;
}