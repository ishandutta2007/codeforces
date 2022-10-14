// Jai Shree Ram  
  
#include<bits/stdc++.h>
using namespace std;

#define rep(i,a,n)     for(int i=a;i<n;i++)
#define ll             long long
#define int            long long
#define pb             push_back
#define all(v)         v.begin(),v.end()
#define endl           "\n"
#define x              first
#define y              second
#define gcd(a,b)       __gcd(a,b)
#define mem1(a)        memset(a,-1,sizeof(a))
#define mem0(a)        memset(a,0,sizeof(a))
#define sz(a)          (int)a.size()
#define pii            pair<int,int>
#define hell           1000000007
#define elasped_time   1.0 * clock() / CLOCKS_PER_SEC



template<typename T1,typename T2>istream& operator>>(istream& in,pair<T1,T2> &a){in>>a.x>>a.y;return in;}
template<typename T1,typename T2>ostream& operator<<(ostream& out,pair<T1,T2> a){out<<a.x<<" "<<a.y;return out;}
template<typename T,typename T1>T maxs(T &a,T1 b){if(b>a)a=b;return a;}
template<typename T,typename T1>T mins(T &a,T1 b){if(b<a)a=b;return a;}






const int N=1e9+5;
const int M=1e7;



struct node{	
	int l;int r;
	int val;
}t[M];
int cnt=0;

int n = 1e5 + 5;

void extend(int v){
	if(t[v].l==0){
		t[v].l=++cnt;
		t[v].r=++cnt;
	}
}

void pushdown(int v,int tl,int tr,int val){
	if(tl!=tr){
		extend(v);
		maxs(t[t[v].l].val,val);
		maxs(t[t[v].r].val,val);
	}
}	

void update(int v,int l,int r,int val,int tl=1,int tr=n){
	if(tl>r || l>tr)return;
	if(l<=tl && tr<=r){
		maxs(t[v].val,val);
		return;
	}
	extend(v);
	int mid=(tl+tr)/2;
	update(t[v].l,l,r,val,tl,mid);
	update(t[v].r,l,r,val,mid+1,tr);
}

void query(int v,int i,int &mx,int tl=1,int tr=n){
	if(tl==tr){
		maxs(mx,t[v].val);
		return;
	}
	maxs(mx,t[v].val);
	int mid=(tl+tr)/2;
	extend(v);
	if(i<=mid)query(t[v].l,i,mx,tl,mid);
	else query(t[v].r,i,mx,mid+1,tr);
}



int solve(){
 		int n,m; cin >> n >> m;
 		int ans = 0;
 		vector<int>root(n+1);
 		rep(i,1,n+1){
 			root[i] = ++cnt;	
 		}
 		rep(i,0,m){
 			int x,y,w; cin >> x >> y >> w;
 			int dp_x = 0;
 			query(root[x],w-1,dp_x);
 			dp_x++;
 			maxs(ans,dp_x);
 			update(root[y],w,1e5,dp_x);
 		}
 		cout << ans << endl;
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