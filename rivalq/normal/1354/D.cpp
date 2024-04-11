#include<bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
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
template<typename T>
struct Fenwick{
    vector<T> tree;
    Fenwick(int n){
        tree.resize(n);
    }

    T query(int i){
        int sum=0;
        while(i){
           sum+=tree[i];
           i-=i&(-i);
       }  
       return sum;
    }
    void update(int i,int n,T val){
       while(i<=n){
          tree[i]+=val;
          i+=i&(-i);
       }
    }
    int find(int x,int n){
        int sum=0;
        int idx=0;
    	for(int i=20;i>=0;i--){
           if(idx+(1<<i)<=n && sum+tree[idx+(1<<i)]<x){
           	   sum+=tree[idx+(1<<i)];
               idx+=(1<<i); 
           }
    	}
    	return idx+1;
    }
};

int solve(){
 int n,q;cin>>n>>q;
 Fenwick<int>fn(n+1);
 rep3(n){
 	int t;cin>>t;
 	fn.update(t,n,1);
 }
 rep3(q){
 	int k;cin>>k;
 	if(k>0){
 		fn.update(k,n,1);
 	}
 	else{
 		k=abs(k);
 		int lo=1;
 		int hi=n;
 		int ans=fn.find(k,n);
 		fn.update(ans,n,-1);
 	}
 }
 int val=fn.query(n);
 if(val==0){
 	cout<<0<<endl;return 0;
 }
 for(int i=1;i<=n;i++){
 	 int k=fn.query(i)-fn.query(i-1);
 	 if(k>0){
 	 	cout<<i<<endl;return 0;
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