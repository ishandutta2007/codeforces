#include<bits/stdc++.h>
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


template<typename T1,typename T2>istream& operator>>(istream& in,pair<T1,T2> &a){in>>a.x>>a.y;return in;}
template<typename T1,typename T2>ostream& operator<<(ostream& out,pair<T1,T2> a){out<<a.x<<" "<<a.y;return out;}
template<typename T,typename T1>T maxs(T &a,T1 b){if(b>a)a=b;return a;}
template<typename T,typename T1>T mins(T &a,T1 b){if(b<a)a=b;return a;}
const int N=200005;
struct Fenwick{
     Tree<int> tree[N];
 
    int query(int i,int l,int r){
        int sum=0;
        while(i>0){
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

int solve(){
 int n,q;cin>>n>>q;
 vector<int>p(n+1);
 for(int i=1;i<=n;i++)fn.insert(i,i,n),p[i]=i;
 int cnt=0;
 rep3(q){
     int x,y;cin>>x>>y;
     if(x>y)swap(x,y);
     if(x==y){
     	cout<<cnt<<endl;continue;
     }
     if(p[y]>p[x])cnt++;
     else cnt--;
     if(x+1==y){
     	 fn.erase(x,p[x],n);
         fn.erase(y,p[y],n);
         fn.insert(x,p[y],n);
         fn.insert(y,p[x],n);
         swap(p[x],p[y]);
         cout<<cnt<<endl;
         continue;
     }
     int l=x+1;
     int r=y-1;
     int len=r-l+1;
     int val=2*(fn.query(r,1,p[y])-fn.query(l-1,1,p[y]))-len;
     int val2=2*(fn.query(r,p[x],n)-fn.query(l-1,p[x],n))-len;
     cnt+=val+val2;
     fn.erase(x,p[x],n);
     fn.erase(y,p[y],n);
     fn.insert(x,p[y],n);
     fn.insert(y,p[x],n);
     swap(p[x],p[y]);
     cout<<cnt<<endl;
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