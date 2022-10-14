//https://codeforces.com/contest/446/problem/C
#include<bits/stdc++.h>
#define rep(i,a,n)     for(int i=a;i<n;i++)
#define rep3(n)        for(int i=0;i<n;i++)
#define inarr(arr,n)   rep(i,a,n)cin>>arr[i]
#define ll             long long int
#define pb             push_back
#define all(v)         v.begin(),v.end()
#define pll            pair<ll,ll>
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
const ll mod=1e9+9;
const int inf1=1e9;
const ll inf2=1e18;
const int N=300000;
using namespace std;
int dirs[4][2] ={{1,0},{-1,0},{0,1},{0,-1}};
ll fib[N+15];
ll tree[4*N];
pair<pll,ll> lazy[4*N];
bool isl[4*N]={false};
ll get(int n){ 
    if(n<=0)return 0;
    return fib[n];
}
ll sum(int n,ll a,ll b){
    if(n==1){
        //cout<<"*"<<a<<endl;
        return a;
    }   
    return (b*fib[n+1]+a*fib[n]-b+mod)%mod;
}
void makelazy(int node,int m,ll a,ll b){
    isl[node]=1;
    if(m==0){
        //cout<<"in"<<a<<" "<<node<<endl;
        lazy[node].x.x+=a;
        lazy[node].x.x%=mod;
        lazy[node].x.y+=b;
        lazy[node].x.y%=mod;
        return;
    }
    //cout<<"in "<<a<<" "<<node<<" "<<m<<endl;
    lazy[node].x.x+=((a*get(m-1))%mod+(b*get(m))%mod);lazy[node].x.x%=mod;
    lazy[node].x.y+=((a*get(m))%mod+(b*get(m+1))%mod);lazy[node].x.y%=mod;
}
void makeactive(int node,int start,int end){
    tree[node]+=sum(end-start+1,lazy[node].x.x,lazy[node].x.y);tree[node]%=mod;
    lazy[node].x.x=0;
    lazy[node].x.y=0;
    isl[node]=0;
}
void buildtree(ll arr[],int start,int end,int node){
    if(start==end){
        tree[node]=arr[start];
        return ;
    }
    else{
        int mid=(start+end)/2;
        buildtree(arr,start,mid,2*node);
        buildtree(arr,mid+1,end,2*node+1);
        // write func here
        tree[node]=tree[2*node]+tree[2*node+1];
    }
}
void update(int node, int start, int end, int l, int r, int a,int b){
   if(isl[node]){ 
        if(start != end){
            isl[2*node]=1;
            lazy[2*node].x.x+=lazy[node].x.x;lazy[2*node].x.x%=mod;
            lazy[2*node].x.y+=lazy[node].x.y;lazy[2*node].x.y%=mod;               
            makelazy(2*node+1,(start+end)/2-start+1,lazy[node].x.x,lazy[node].x.y);               
        }
        makeactive(node,start,end); 
   } 
   if(start>end || start>r || end<l)return;
   if(start >= l && end <= r){
        makelazy(node,start-l,a,b);
        if(start != end){
            isl[2*node]=1; 
            lazy[2*node].x.x+=lazy[node].x.x;lazy[2*node].x.x%=mod;
            lazy[2*node].x.y+=lazy[node].x.y;lazy[2*node].x.y%=mod; 
            makelazy(2*node+1,(start+end)/2-start+1,lazy[node].x.x,lazy[node].x.y);
        }
        makeactive(node,start,end);
        return;
    }
    int mid = (start+end)/2;
    update(node*2,start,mid,l,r,a,b);       
    update(node*2+1,mid+1,end,l,r,a,b);   
    tree[node]=tree[node*2]+tree[node*2+1]; 
   
}
ll query(int node, int start, int end, int l, int r){
   if(start > end or start > r or end < l)return 0;  
   if(isl[node]){ 
        if(start != end){
            isl[2*node]=1;
            lazy[2*node].x.x+=lazy[node].x.x;lazy[2*node].x.x%=mod;
            lazy[2*node].x.y+=lazy[node].x.y;lazy[2*node].x.y%=mod; 
            makelazy(2*node+1,(start+end)/2-start+1,lazy[node].x.x,lazy[node].x.y);           
        }
        makeactive(node,start,end);
   } 
    if(start >= l && end <= r)return tree[node];
    int mid = (start + end) / 2;
    ll p1 = query(node*2, start, mid, l, r);       
    ll p2 = query(node*2 + 1, mid + 1, end, l, r); 
    return ((p1 + p2)%mod+mod)%mod;
}
int solve(){   
 int n,q;cin>>n>>q;           
 ll arr[n];rep3(n)cin>>arr[i];
 buildtree(arr,0,n-1,1);
 rep3(q){
     int t;
     cin>>t;
     if(t==1){
         int l,r;cin>>l>>r;
         update(1,0,n-1,l-1,r-1,1,1);
     }
     else{
         int l,r;cin>>l>>r;
         cout<<query(1,0,n-1,l-1,r-1)%mod<<endl;
     }
     /**cout<<"-----"<<endl;
     cout<<query(1,0,n-1,0,0)<<endl;
     cout<<query(1,0,n-1,1,1)<<endl;
     cout<<query(1,0,n-1,2,2)<<endl;
     cout<<query(1,0,n-1,3,3)<<endl;**/

 }
 ret;
}
int main(){
    IOS;
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    fib[0]=0;
    fib[1]=1;
    for(int i=2;i<N+15;i++)fib[i]=(fib[i-1]+fib[i-2])%mod;
    #ifdef cat
    cat();
    #endif
    int t=1;//cin>>t;
    while(t--){
        solve();
    }
    ret;
}