//https://codeforces.com/problemset/problem/91/B
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
int tree[4*N];
void buildtree(int arr[],int start,int end,int node){
    if(start==end){
        tree[node]=arr[start];
        return ;
    }
    else{
        int mid=(start+end)/2;
        buildtree(arr,start,mid,2*node);
        buildtree(arr,mid+1,end,2*node+1);
        tree[node]=min(tree[2*node],tree[2*node+1]);
    }
}
void update(int arr[],int idx,int start,int end,int node,int nval){
   if(start==end){
       arr[idx]=nval;
       tree[node]=nval;
       return;
   }
   else{
       int mid=(start+end)/2;
       if(idx<=mid){
           update(arr,idx,start,mid,2*node,nval);
       }
       else{
           update(arr,idx,mid+1,end,2*node+1,nval);
       }
       tree[node]=min(tree[2*node],tree[2*node+1]);
   }
   
}
int get_first(int v, int lv, int rv, int l, int r, int x) {
    if(lv > r || rv < l) return -1;
    if(l <= lv && rv <= r) {
        if(tree[v] >= x) return -1;
        while(lv != rv) {
            int mid = lv + (rv-lv)/2;
            if(tree[2*v] < x) {
                v = 2*v;
                rv = mid;
            }else {
                v = 2*v+1;
                lv = mid+1;
            }
        }
        return lv;
    }

    int mid = lv + (rv-lv)/2;
    int rs = get_first(2*v, lv, mid, l, r, x);
    if(rs != -1) return rs;
    return get_first(2*v+1, mid+1, rv, l ,r, x);
}    
int solve(){
 int n;cin>>n;           
 int a[n];rep3(n)cin>>a[i];
 int b[n];rep3(n)b[i]=a[n-i-1];
 buildtree(b,0,n-1,1);
 rep3(n){
     int x=a[i];
     int ans=get_first(1,0,n-1,0,n-i-2,x);
     if(ans==-1)cout<<ans<<" ";
     else cout<<(n-ans-1)-i-1<<" ";
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