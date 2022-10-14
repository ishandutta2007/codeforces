//https://codeforces.com/contest/52/problem/C
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
ll tree[1000000];
ll lazy[1000000];
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
        tree[node]=min(tree[2*node],tree[2*node+1]);
    }
}
void update(int node, int start, int end, int l, int r, ll val){
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
    tree[node]=min(tree[node*2],tree[node*2+1]); 
   
}
ll query(int node, int start, int end, int l, int r){
   if(start > end or start > r or end < l)return inf2;  
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
    ll p1 = query(node*2, start, mid, l, r);       
    ll p2 = query(node*2 + 1, mid + 1, end, l, r); 
    return min(p1,p2);
}
int solve(){
  int n;cin>>n;
  ll arr[n];rep3(n)cin>>arr[i];          
  int q;cin>>q;
  buildtree(arr,0,n-1,1);
  cin.ignore(numeric_limits<streamsize>::max(),'\n');     
  
  rep3(q){
    string s;
    getline(cin,s);
    ll num=0;
    int ne=0;
    vector<ll>v;
    for(auto j:s){
        if(j=='-'){
            ne=1;
            continue;
        }
        if(j==' '){
            if(ne)num*=-1;
            v.pb(num);
            num=0;ne=0;
        }
        else{
            num=num*10+j-48;
        }
    }
    if(ne)num=num*-1;
    v.pb(num);
    //for(auto i:v)cout<<i<<" ";cout<<endl;
    if(v.size()==2){
        if(v[1]<v[0]){
            ll p1=query(1,0,n-1,v[0],n-1);
            ll p2=query(1,0,n-1,0,v[1]);
            cout<<min(p1,p2)<<endl;
        }
        else{
            cout<<query(1,0,n-1,v[0],v[1])<<endl;
        }
    }
    else{
        if(v[1]<v[0]){
            update(1,0,n-1,v[0],n-1,v[2]);
            update(1,0,n-1,0,v[1],v[2]);
        }
        else{
            update(1,0,n-1,v[0],v[1],v[2]);
        }
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