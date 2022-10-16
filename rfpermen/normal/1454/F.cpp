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
#define ff fi.fi
#define fs fi.se
#define sf se.fi
#define ss se.se
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
#define endl '\n'
const int MAX = 2e5+5;
const ll MAX2 = 11;
const ll MOD = 2105095327;
const ll MOD2 = 2010405347;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 555;

ll tc,n,x[MAX],y[MAX],nw,le,ri,mid,tree[1<<19],a,b;

void build(int id,int le,int ri){
	if(le==ri){
		tree[id] = x[le];
		return;
	}
	int mid = le+ri>>1;
	build(lc,le,mid), build(rc,mid+1,ri);
	tree[id] = min(tree[lc],tree[rc]);
	return;
}

int que(int id,int le,int ri){
	if(le>b||ri<a)return MOD;
	if(le>=a&&ri<=b)return tree[id];
	int mid = le+ri>>1;
	return min(que(lc,le,mid), que(rc,mid+1,ri));
}
bool st;
int main(){
// cout<<fixed<<setprecision(6);
// freopen("trip.in", "r", stdin);
// freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>tc;
    rep(ntc,1,tc){
    	cin>>n;
    	rep(i,1,n)cin>>x[i];
    	y[n+1] = 0;
    	rap(i,n,1)y[i] = max(y[i+1],x[i]);
    	build(1,1,n);
    	st = nw = 0;
    	int res;
    	rep(i,1,n-2){
    		nw = max(nw,x[i]);
//    		if(i==2){
//    			a = 3, b = 7;
//    			cout<<nw<<' '<<que(1,1,n)<<' '<<y[8]<<endl;
//			}
    		le = i+1, ri = n-1;
    		while(le<=ri){
//    			if(i==2)cout<<"<> "<<le<<' '<<ri<<endl;
    			mid = le+ri>>1;
    			a = i+1, b = mid;
    			res = que(1,1,n);
//    			if(i==2)cout<<">> "<<mid<<' '<<res<<' '<<y[mid+1]<<endl;
    			if(res<nw)ri = mid-1;
    			else if(res>nw)le = mid+1;
    			else if(y[mid+1]<nw)ri = mid-1;
    			else if(y[mid+1]>nw)le = mid+1;
    			else {
    				st = 1;
    				cout<<"YES\n"<<i<<' '<<mid-i<<' '<<n-mid<<endl;
    				break;
				}
			}
			if(st)break;
		}
		if(!st)cout<<"NO\n";
	}
    return 0;
}