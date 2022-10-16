#include <bits/stdc++.h>

#pragma GCC optimize("O2")
using namespace std;
#define ll long long
#define ull unsigned long long
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
#define lc (id<<1)
#define rc ((id<<1)|1)
#define db(x) cout << ">>>>>> " << #x << " -> " << x << endl;
#define all(x) x.begin(),x.end()
#define pii pair<int,int> 
#define pll pair<ll,ll>
#define piii pair<int,pii>
#define piiii pair<pii,pii>
#define psi pair<string,int>
#define endl "\n"
const int MAX = 2e5+5;
const ll MAX2 = 11;
const int MOD = 998244353;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;

int n,k,tree[1<<19],sz,x[MAX],a,b;
vector<int> v[MAX];
void build(int id,int le,int ri){
	if(le==ri){
		tree[id] = x[le]; return;
	}
	int mid = le+ri>>1;
	build(lc,le,mid), build(rc,mid+1,ri);
	tree[id] = min(tree[lc],tree[rc]);
}
int que(int id,int le,int ri){
	if(le>b||ri<a)return 1e9;
	if(le>=a&&ri<=b)return tree[id];
	int mid = le+ri>>1;
	return min(que(lc,le,mid),que(rc,mid+1,ri));
}

int main(){
//	cout<<fixed<<setprecision(10);
//    freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>k;
    rep(i,1,n){
    	cin>>x[i];
    	if(!x[i])x[i] = 1e9;
    	else v[x[i]].pb(i);
	}
	build(1,1,n);
	rep(i,1,k){
		if(v[i].size()<2)continue;
		sz = v[i].size()-1;
		rep(j,1,sz){
			a = v[i][j-1], b = v[i][j];
			if(que(1,1,n)<i)return cout<<"NO",0;
		}
	}
	if(v[k].empty()){
		rep(i,1,n){
			if(x[i]==1e9){
				x[i] = k;
				break;
			}
			if(i==n)return cout<<"NO",0;
		}
	}
	if(x[1]==1e9)x[1] = 1;
	cout<<"YES\n";
	rep(i,1,n){
		if(x[i]==1e9)x[i] = x[i-1];
		cout<<x[i]<<" ";
	}
	return 0;
}