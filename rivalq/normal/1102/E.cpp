//https://codeforces.com/contest/1102/problem/E
#pragma GCC optimize "trapv" 
#include<bits/stdc++.h>
#define rep(i,a,n)     for(int i=a;i<n;i++)
#define rep3(n)        for(int i=0;i<n;i++)
#define inarr(arr,n)   rep(i,a,n)cin>>arr[i]
#define int             long long int
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
const int inf2=1e18;
const int N=100000;
using namespace std;
int dirs[4][2] ={{1,0},{-1,0},{0,1},{0,-1}};
int tree[10000000];
int lazy[10000000];
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
        //tree[node]=tree[2*node]+tree[2*node+1];
    }
}
void update(int node, int start, int end, int l, int r, int val){
   if(lazy[node] != 0){ 
        tree[node]=lazy[node];
        if(start != end){
            lazy[node*2]=lazy[node];                 
            lazy[node*2+1]=lazy[node];               
        }
        lazy[node] = 0; 
   } 
   if(start>end || start>r || end<l)return;
   if(start >= l && end <= r){
        tree[node] =  val;
        if(start != end){
            lazy[node*2] = val;
            lazy[node*2+1] = val;
        }
        return;
    }
    int mid = (start+end)/2;
    update(node*2,start,mid,l,r,val);       
    update(node*2+1,mid+1,end,l,r,val);   
    //tree[node]=tree[node*2]+tree[node*2+1]; 
   
}
int query(int node, int start, int end, int l, int r){
   if(start > end or start > r or end < l)return 0;  
   if(lazy[node] != 0){ 
        tree[node]=lazy[node];
        if(start != end){
            lazy[node*2]=lazy[node];                 
            lazy[node*2+1]=lazy[node];               
        }
        lazy[node] = 0; 
   } 
    if(start >= l && end <= r)return tree[node];
    int mid = (start + end) / 2;
    int p1 = query(node*2, start, mid, l, r);       
    int p2 = query(node*2 + 1, mid + 1, end, l, r); 
    return (p1 + p2);
}
int xymodp(int x,int y,int p){
    int a=1;
    x%=p;
    while(y){
        if(y&1)a=(a*x)%p;
        x=(x*x)%p;
        y/=2;
    }
    return a;
}

int solve(){
 mem1(tree);           
 int n;cin>>n;
 set<int>s;
 int cnt=0;  
 map<int,vector<int>>mp;
 int a[n];
 rep3(n){
     int t;cin>>t;
     a[i]=t;
     mp[t].pb(i);
 }       
 for(int i=0;i<n;i++){
     int idx1=mp[a[i]].front();
     int q=query(1,0,n-1,idx1,idx1);
     //cout<<i.x<<" "<<idx1<<" "<<q<<endl;
     if(q!=-1){
         int idx2=mp[a[i]].back();
         update(1,0,n-1,idx1,idx2,q);
     }
     else{
         cnt++;
         int val=cnt;
         int idx2=mp[a[i]].back();
         update(1,0,n-1,idx1,idx2,val);
     }
 }
 cout<<xymodp(2,cnt-1,narak)<<endl;
 ret;
}
signed main(){
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