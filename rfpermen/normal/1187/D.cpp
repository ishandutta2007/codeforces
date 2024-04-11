#include <bits/stdc++.h>
 
#pragma GCC optimize("O2")
using namespace std;
#define ll long long
#define ull unsigned long long
#define rep(i,n,N) for(ll i=n;i<=N;++i)
#define rap(i,n,N) for(ll i=n;i>=N;--i)
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
#define db(x) cout << ">>>>>> " << #x << " -> " << x << endl;
#define all(x) x.begin(),x.end()
#define pii pair<int,int> 
#define pll pair<ll,ll>
#define piii pair<int,pii>
#define plll pair<ll,pii>
#define piiii pair<pii,pii>
#define psi pair<string,int>
#define endl "\n"
const int MAX = 3e5+5;
const ll MAX2 = 11;
const ll MOD = 1000000007;
const ll INF = 1e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 450;
 
 
int q,n,tree[1<<20],x[MAX],y[MAX],cnt[MAX],a,b,dv;
stack<int> pos[MAX];
bool jaw;
 
void build(int id,int le,int ri){
	if(le==ri){
		tree[id] = x[le];
		return;
	}
	int mid = le+ri>>1;
	build(lc,le,mid), build(rc,mid+1,ri);
	tree[id] = max(tree[lc],tree[rc]);
	return;
}
 
void upd(int id,int le,int ri){
	if(le==ri){
		tree[id] =0;
		return;
	}
	int mid = le+ri>>1;
	if(a<=mid)upd(lc,le,mid);
	else upd(rc,mid+1,ri);
	tree[id] = max(tree[lc],tree[rc]);
	return;
}
 
int que(int id,int le,int ri){
	if(le>b||ri<a)return 0;
	if(le>=a&&ri<=b)return tree[id];
	int mid = le+ri>>1;
	return max(que(lc,le,mid), que(rc,mid+1,ri));
}
 
int main(){
//	cout<<fixed<<setprecision(15);
//    freopen("class_treasurer.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>q;
    while(q--){
    	cin>>n;
    	rep(i,1,n){
    		cnt[i] = 0;
    		while(!pos[i].empty())pos[i].pop();
		}
    	rep(i,1,n)cin>>x[i], ++cnt[x[i]], pos[x[i]].push(i);
    	rep(i,1,n)cin>>y[i], --cnt[y[i]];
    	jaw = 1;
    	rep(i,1,n)if(cnt[i]!=0){
			jaw = 0;
			break;
		}
		if(!jaw){cout<<"NO\n"; continue;}
		build(1,1,n);
		dv = 0;
		rap(i,n,1){
			if(i==pos[y[i]].top()-dv)a = pos[y[i]].top(), pos[y[i]].pop(), upd(1,1,n);
			else {
				if(i<pos[y[i]].top()-dv){
					jaw = 0;
					break;
				}
				a = pos[y[i]].top(), b = n;
				if(que(1,1,n)<=y[i]){
					upd(1,1,n);
					dv++;
					pos[y[i]].pop();
				}
				else {
					jaw = 0;
					break;
				}
			}
		}
		if(!jaw)cout<<"NO\n";
		else cout<<"YES\n";
	}
	return 0;
}