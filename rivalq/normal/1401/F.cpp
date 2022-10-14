#include<bits/stdc++.h>

#define rep(i,a,n)     for(int i=a;i<n;i++)
#define rep3(n)        for(int i=0;i<n;i++)
#define ll             long long
#define int            long long
#define pb             push_back
#define all(v)         v.begin(),v.end()
#define endl           "\n"
#define eb             emplace_back
#define x              first
#define y              second
#define gcd(a,b)       __gcd(a,b)
#define mem1(a)        memset(a,-1,sizeof(a))
#define mem0(a)        memset(a,0,sizeof(a))
#define pres(a,x)      a.find(x)!=a.end()
#define sz(a)          (int)a.size()
#define pii            pair<int,int>
#define hell           1000000007
#define elasped_time   1.0 * clock() / CLOCKS_PER_SEC
using namespace std;


template<typename T1,typename T2>istream& operator>>(istream& in,pair<T1,T2> &a){in>>a.x>>a.y;return in;}
template<typename T1,typename T2>ostream& operator<<(ostream& out,pair<T1,T2> a){out<<a.x<<" "<<a.y;return out;}
template<typename T,typename T1>T maxs(T &a,T1 b){if(b>a)a=b;return a;}
template<typename T,typename T1>T mins(T &a,T1 b){if(b<a)a=b;return a;}
const int N=1e6+5;
int a[N];
int level[N];
int t[N];
int chl[N],chr[N];
bool lazy[N],inv[20];
int n;

void build(int v,int tl,int tr,int l){
	level[v]=l;
	if(tl==tr){
		t[v]=a[tl];return;
	}
	int mid=(tl+tr)/2;
	chl[v]=2*v;
	chr[v]=2*v+1;
	build(2*v,tl,mid,l-1);
	build(2*v+1,mid+1,tr,l-1);
	t[v]=t[2*v]+t[2*v+1];
}
void reverse(int k,int n){
	for(int i=1;i<=k;i++){
		inv[i]^=1;
	}
}
void swap(int k,int n){
	inv[k+1]^=1;
}
void update(int v,int tl,int tr,int idx,int val){
	int k=level[v];
	if(lazy[v]!=inv[k]){
		lazy[v]^=1;
		chl[v]=chl[v]+chr[v]-(chr[v]=chl[v]);

	}
	if(tl==tr){
		t[v]=val;return;
	}
	int mid=(tl+tr)/2;
	if(mid>=idx){
		update(chl[v],tl,mid,idx,val);
		t[v]=t[2*v]+t[2*v+1];
	}
	else{
		update(chr[v],mid+1,tr,idx,val);
		t[v]=t[2*v]+t[2*v+1];
	}
}
int query(int v,int tl,int tr,int l,int r){
	if(tl>r || l>tr)return 0;
	int k=level[v];
	if(lazy[v]!=inv[k]){
		lazy[v]^=1;
		chl[v]=chl[v]+chr[v]-(chr[v]=chl[v]);

	}
	if(l<=tl && tr<=r)return t[v];
	int mid=(tl+tr)/2;
	return query(chl[v],tl,mid,l,r)+query(chr[v],mid+1,tr,l,r);
}
int solve(){
 	cin>>n;
 	int q;cin>>q;
 	int m=(1<<n);
 	rep(i,1,m+1){
 		cin>>a[i];
 	}
 	build(1,1,m,n);
 	rep3(q){
 		int t;cin>>t;
 		if(t==1){
 			int x,k;cin>>x>>k;
 			update(1,1,m,x,k);
 		}
 		else if(t==2){
 			int k;cin>>k;
 			reverse(k,m);
 		}
 		else if(t==3){
 			int k;cin>>k;
 			swap(k,m);
 		}
 		else{
 			int l,r;cin>>l>>r;
 			cout<<query(1,1,m,l,r)<<endl;
 		}
 	}
 	
 return 0;
}
signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #ifdef SIEVE
    sieve();
    #endif
    #ifdef NCR
    init();
    #endif
    int t=1;//cin>>t;
    while(t--){
        solve();
    }
    return 0;
}