 #include <bits/stdc++.h>

#pragma GCC optimize("O3")
using namespace std;
#define ll long long
#define ull unsigned long long
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

ll n,x[MAX],k[MAX],tree[1<<18],lz[1<<18],q,a,b,y,z,val;
char ty;
inline void f(int &id,int &le,int &ri){
	tree[id] = lz[id]*(ri-le+1);
	if(le!=ri)lz[lc] = lz[rc] = lz[id];
	lz[id] = -3e9;
}
void build(int id,int le,int ri){
	lz[id] = -3e9;
	if(le==ri){tree[id] = x[le]; return;}
	int mid = le+ri>>1;
	build(lc,le,mid), build(rc,mid+1,ri);
	tree[id] = tree[lc] + tree[rc];
}
void upd(int id,int le,int ri){
	if(lz[id]>-2e9)f(id,le,ri);
	if(le>b||ri<a)return;
	if(le>=a&&ri<=b){lz[id] = val; f(id,le,ri); return;}
	int mid = le+ri>>1;
	upd(lc,le,mid), upd(rc,mid+1,ri);
	tree[id] = tree[lc] + tree[rc];
}
ll que(int id,int le,int ri){
	if(lz[id]>-2e9)f(id,le,ri);
	if(le>b||ri<a)return 0;
	if(le>=a&&ri<=b)return tree[id];
	int mid = le+ri>>1;
	return que(lc,le,mid) + que(rc,mid+1,ri);
}

int main(){
//	cout<<fixed<<setprecision(10);
//    freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int le,ri,mid;
    cin>>n;
    rep(i,1,n)cin>>x[i];
    rep(i,2,n)cin>>k[i], k[i]+=k[i-1], x[i]-=k[i];
    rep(i,2,n)k[i]+=k[i-1];
    build(1,1,n);
    cin>>q;
    while(q--){
    	cin>>ty>>a>>b;
    	if(ty=='+'){
    		y = a, val = b, b = a;
    		if(!val)continue;
    		val+= que(1,1,n);
    		le = a, ri = n;
    		while(le<=ri){
    			mid = le+ri>>1;
    			a = b = mid;
    			if(que(1,1,n)<val)z = mid, le = mid+1;
    			else ri = mid-1;
			}
			a = y, b = z;
			upd(1,1,n);
		}
		else cout<<que(1,1,n)+k[b]-k[a-1]<<endl;
	}
	return 0;
}