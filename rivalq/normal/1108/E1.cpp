//https://codeforces.com/contest/1108/problem/E1
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
const int N=100000;
using namespace std;
int dirs[4][2] ={{1,0},{-1,0},{0,1},{0,-1}};
int tree[1000000]={0};
int lazy[1000000]={0};
void buildtree(int arr[],int start,int end,int node){
    if(start==end){
        tree[node]=arr[start];
        return ;
    }
    else{
        int mid=(start+end)/2;
        buildtree(arr,start,mid,2*node);
        buildtree(arr,mid+1,end,2*node+1);
        // write func here
        tree[node]=max(tree[2*node],tree[2*node+1]);
    }
}
void update(int node, int start, int end, int l, int r, int val){
   if(lazy[node] != 0){ 
        tree[node]+=lazy[node];
        if(start != end){
            lazy[node*2]+=lazy[node];                 
            lazy[node*2+1]+=lazy[node];               
        }
        lazy[node] = 0; 
   } 
   if(start>end || start>r || end<l)return;
   if(start >= l && end <= r){
        tree[node]+=val;
        if(start != end){
            lazy[node*2] += val;
            lazy[node*2+1] += val;
        }
        return;
    }
    int mid = (start+end)/2;
    update(node*2,start,mid,l,r,val);       
    update(node*2+1,mid+1,end,l,r,val);   
    tree[node]=max(tree[node*2],tree[node*2+1]); 
   
}
int query(int node, int start, int end, int l, int r){
   if(start > end or start > r or end < l)return -inf1;  
   if(lazy[node] != 0){ 
        tree[node]+=lazy[node];
        if(start != end){
            lazy[node*2]+=lazy[node];                 
            lazy[node*2+1]+=lazy[node];               
        }
        lazy[node] = 0; 
   } 
    if(start >= l && end <= r)return tree[node];
    int mid = (start + end) / 2;
    int p1 = query(node*2, start, mid, l, r);       
    int p2 = query(node*2 + 1, mid + 1, end, l, r); 
    return max(p1,p2);
}
int solve(){
  int n,m;cin>>n>>m;
  int a[n+1],b[m][2];
  rep3(n){
      cin>>a[i+1];
      a[i+1]=-a[i+1];
  } 
  buildtree(a,1,n,1);   
  map<pii,int>mp1;
  map<pii,int,greater<pii>>mp2;  
  auto itr1=mp1.begin();
  auto itr2=mp2.begin();       
  rep3(m){
      cin>>b[i][0]>>b[i][1];
      mp1[{b[i][0],i}]=b[i][1];
   }
   int ma=0;
   vector<int> idx;
   for(int i=1;i<=n;i++){
      int val=-a[i];
      vector<int> v;
      for(int j=0;j<m;j++){
          if(i>=b[j][0] && i<=b[j][1])continue;
          else{
            v.pb(j+1);
            update(1,1,n,b[j][0],b[j][1],1);
          }
      }
      int x=query(1,1,n,1,n)+val;
      if(ma<x){
        ma=x;
        idx=v;
      }
      for(int j=0;j<m;j++){
          if(i>=b[j][0] && i<=b[j][1])continue;
          else{
            update(1,1,n,b[j][0],b[j][1],-1);
          }
      }
  } 
  cout<<ma<<endl;
  cout<<sz(idx)<<endl;
  for(auto i:idx)cout<<i<<" ";cout<<endl;
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