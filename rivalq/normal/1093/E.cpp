#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#include<stdio.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

template <class T> using Tree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>; 
#define ook order_of_key
#define fbo find_by_order

#define rep(i,a,n)     for(int i=a;i<n;i++)
#define rep3(n)        for(int i=0;i<n;i++)
#define ll             long long
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


template<typename T1,typename T2>istream& operator>>(istream& in,pair<T1,T2> &a){in>>a.x>>a.y;return in;}
template<typename T1,typename T2>ostream& operator<<(ostream& out,pair<T1,T2> a){out<<a.x<<" "<<a.y;return out;}
template<typename T,typename T1>T maxs(T &a,T1 b){if(b>a)a=b;return a;}
template<typename T,typename T1>T mins(T &a,T1 b){if(b<a)a=b;return a;}
const int N=200005;
struct Fenwick{
     Tree<int> tree[N];

    int query(int i,int r,int l){
        int sum=0;
        while(i){
           sum+=(tree[i].ook({r+1})-tree[i].ook(l));
           i-=i&(-i);
       }  
       return sum;
    }
    void erase(int i,int y,int n){
    	 while(i<=n){
    	 	tree[i].erase(y);
    	 	i+=i&(-i);
    	 }
    }
    void insert(int i,int y,int n){
       while(i<=n){
          tree[i].insert(y);
          i+=i&(-i);
       }
    }
};
Fenwick fn;
int a[N],b[N],p[N],p2[N];
void solve(){
 int n,m;
 scanf("%d%d",&n,&m);
 rep(i,1,n+1){
   scanf("%d",&a[i]);
   p2[a[i]]=i;
 }
 rep(i,1,n+1){
 	scanf("%d",&b[i]);
 	p[b[i]]=i;
 }
 rep(i,1,n+1){
 	a[i]=p[a[i]];
 	fn.insert(i,a[i],n);
 }
 rep3(m){
 	int t;
 	scanf("%d",&t);
 	if(t==1){
 		int la,ra,lb,rb;
 		scanf("%d%d%d%d",&la,&ra,&lb,&rb);
 		int ans=fn.query(ra,rb,lb)-fn.query(la-1,rb,lb);
 		printf("%d\n",ans);
 	}
 	else{
 		int x,y;
 		scanf("%d%d",&x,&y);
        int idx1=p2[b[x]];
        int idx2=p2[b[y]];
        fn.erase(idx1,x,n);
        fn.erase(idx2,y,n);
        fn.insert(idx1,y,n);
        fn.insert(idx2,x,n);
        swap(b[x],b[y]);
 	}
 }
}
signed main(){
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