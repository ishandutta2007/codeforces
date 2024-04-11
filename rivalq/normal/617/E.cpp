//https://codeforces.com/problemset/problem/617/E
#pragma GCC optimize "trapv" 
#include<bits/stdc++.h>
#define rep(i,a,n)     for(int i=a;i<n;i++)
#define rep3(n)        for(int i=0;i<n;i++)
#define inarr(arr,n)   rep(i,a,n)cin>>arr[i]
#define ll             long long int
#define pb             push_back
#define all(v)         v.begin(),v.end()
#define endl           "\n"
#define eb             emplace_back
#define x              first
#define y              second
#define gcd(a,b)       __gcd(a,b)
#define mem1(a)        memset(a,-1,sizeof(a))
#define pres(a,x)      a.find(x)!=a.end()
#define sz(a)          (int)a.size()
#define pii            pair<int,int>
#define IOS            ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define ret            return 0
#define pi             3.1415926536
#define hell           1000000007
#define narak          998244353
const int inf1=1e9;
const ll inf2=1e18;
const int N=200000;
using namespace std;
int dirs[4][2] ={{1,0},{-1,0},{0,1},{0,-1}};
inline int64_t gilbertOrder(int x, int y, int pow, int rotate) {
	if (pow == 0) {
		return 0;
	}
	int hpow = 1 << (pow-1);
	int seg = (x < hpow) ? (
		(y < hpow) ? 0 : 3
	) : (
		(y < hpow) ? 1 : 2
	);
	seg = (seg + rotate) & 3;
	const int rotateDelta[4] = {3, 0, 0, 1};
	int nx = x & (x ^ hpow), ny = y & (y ^ hpow);
	int nrot = (rotate + rotateDelta[seg]) & 3;
	int64_t subSquareSize = int64_t(1) << (2*pow - 2);
	int64_t ans = seg * subSquareSize;
	int64_t add = gilbertOrder(nx, ny, pow-1, nrot);
	ans += (seg == 1 || seg == 2) ? add : (subSquareSize - add - 1);
	return ans;
}
int A[N];
int BL[N];
int mp[1100001]={0};
int k;
int pre[N];
struct query{
    int l,r,id,ord;
    inline void order(){
        ord=gilbertOrder(l,r,21,0);
    }
}q[N];
inline bool operator<(const query &a,const query &b){
       return BL[a.l]==BL[b.l]?a.r<b.r:BL[a.l]<BL[b.l];
}
struct mo{
    int vis[N];
    ll res=0;
    int cl,cr;
    ll ans[N];
    inline void check(int i,int A[]){
       if(vis[i]){
         mp[pre[i]]--;
         res-=mp[pre[i]^k];
       }
       else{
         res+=mp[pre[i]^k];
         mp[pre[i]]++;
       }
      vis[i]=1-vis[i];
    }
    void compute(int m,int A[]){
        cl=0,cr=-1;
        for(int i=0;i<m;i++){
            while(cl<q[i].l)check(cl++,A);
            while(cl>q[i].l)check(--cl,A);
            while(cr<q[i].r)check(++cr,A);
            while(cr>q[i].r)check(cr--,A);
            ans[q[i].id]=res;
        }
        for(int i=0;i<m;i++)cout<<ans[i]<<endl;
    }
    
}mo;
int solve(){
    int n,m;cin>>n>>m>>k;           
    rep3(n)cin>>A[i+1];
    rep3(n)pre[i+1]=A[i+1]^pre[i];
    rep3(m){
        int l,r;cin>>l>>r;
        q[i].l=--l;
        q[i].r=r;
        q[i].id=i;
    } 
    int block=sqrt(n);
    for(int i=0;i<=n;i++)BL[i]=i/block;
    sort(q,q+m);
    mo.compute(m,A);
 ret;
}
int main(){
    IOS;
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #ifdef cat
    cat();
    #endif
    int t=1;//cin>>t;
    while(t--){
        solve();
    }
    ret;
}