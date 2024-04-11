//https://codeforces.com/problemset/problem/242/E
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
const int N=100000;
using namespace std;
int dirs[4][2] ={{1,0},{-1,0},{0,1},{0,-1}};
ll tree[1000000][21];
ll lazy[1000000];
void fun(int node,int val,int start,int end){
      int sz=end-start+1;
      for(int j=20;j>=0;j--){
            int k=1<<j;
            if(k&val){
                tree[node][20-j]=sz-tree[node][20-j];
            }
        }
}
void buildtree(int arr[],int start,int end,int node){
    if(start==end){
        for(int j=20;j>=0;j--){
            int k=1<<j;
            if(k&arr[start])tree[node][20-j]++;
        }
        return ;
    }
    else{
        int mid=(start+end)/2;
        buildtree(arr,start,mid,2*node);
        buildtree(arr,mid+1,end,2*node+1);
        // write func here
        for(int i=0;i<21;i++){
            tree[node][i]=tree[2*node][i]+tree[2*node+1][i];
        }
    }
}
void update(int node, int start, int end, int l, int r, ll val){
   if(lazy[node] != 0){ 
        fun(node,lazy[node],start,end);
        if(start != end){
            lazy[node*2]^=lazy[node];                 
            lazy[node*2+1]^=lazy[node];               
        }
        lazy[node] = 0; 
   } 
   if(start>end || start>r || end<l)return;
   if(start >= l && end <= r){
        fun(node,val,start,end);
        if(start != end){
            lazy[node*2] ^= val;
            lazy[node*2+1] ^= val;
        }
        return;
    }
    int mid = (start+end)/2;
    update(node*2,start,mid,l,r,val);       
    update(node*2+1,mid+1,end,l,r,val);   
    for(int i=0;i<21;i++){
            tree[node][i]=tree[2*node][i]+tree[2*node+1][i];
    }
   
}
ll query(int node, int start, int end, int l, int r){
   if(start > end or start > r or end < l)return 0;  
   if(lazy[node] != 0){ 
        fun(node,lazy[node],start,end);
        if(start != end){
            lazy[node*2]^=lazy[node];                 
            lazy[node*2+1]^=lazy[node];               
        }
        lazy[node] = 0; 
   } 
    if(start >= l && end <= r){
       ll ans=0;
       for(int j=20;j>=0;j--){
            ll k=1<<j;
            ans=ans+k*tree[node][20-j];
        }
        return ans;
    }
    int mid = (start + end) / 2;
    ll p1 = query(node*2, start, mid, l, r);       
    ll p2 = query(node*2 + 1, mid + 1, end, l, r); 
    return (p1 + p2);
}
int solve(){    
  int n;cin>>n;          
  int arr[n];rep3(n)cin>>arr[i];
  buildtree(arr,0,n-1,1);
  int m;cin>>m;
  rep3(m){
      int t;cin>>t;
      if(t==1){
          int l,r;cin>>l>>r;
          l--,r--;
          cout<<query(1,0,n-1,l,r)<<endl;
      }
      else{
          int l,r;cin>>l>>r;
          ll val;cin>>val;
          update(1,0,n-1,l-1,r-1,val);
      }
  }          
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