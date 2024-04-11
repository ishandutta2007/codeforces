//https://codeforces.com/contest/380/problem/C
#include<iostream>
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
const int maxn=4000000;
pair<pii,int> tree[maxn];
void buildtree(string &arr,int start,int end,int node){
    if(start==end){
        if(arr[start]==')')tree[node].x.y=1;
        else tree[node].x.x=1;
        return ;
    }
    else{
        int mid=(start+end)/2;
        buildtree(arr,start,mid,2*node);
        buildtree(arr,mid+1,end,2*node+1);
        int l1=tree[2*node+1].x.x;
        int l2=tree[2*node].x.x;
        int r1=tree[node*2+1].x.y;
        int r2=tree[node*2].x.y;
        tree[node].y+=(min(l2,r1))+tree[2*node].y+tree[2*node+1].y;
        tree[node].x.x+=(l1+l2-min(l2,r1));
        tree[node].x.y+=(r1+r2-min(l2,r1));
    }
}
pair<pii,int> getans(int l,int r,int start,int end,int node){
   if(r<start || end<l){
       pair<pii,int> p;p.x.x=p.x.y=p.y=0;
       return p;
   }
   else if(r>=end && start>=l){
       return tree[node];
   }
   else{
     int mid=(start+end)/2;  
     pair<pii,int> p1=getans(l,r,start,mid,2*node);
     pair<pii,int> p2=getans(l,r,mid+1,end,2*node+1);
     pair<pii,int>p3;
        int l1=p2.x.x;
        int l2=p1.x.x;
        int r1=p2.x.y;
        int r2=p1.x.y;
        p3.y+=(min(l2,r1))+p1.y+p2.y;
        p3.x.x+=(l1+l2-min(l2,r1));
        p3.x.y+=(r1+r2-min(l2,r1));
        return p3;
   }


}
int solve(){
 string s;cin>>s;           
 int n=s.length();
 buildtree(s,0,n-1,1);
 int m;cin>>m;
 rep3(m){
     int l,r;cin>>l>>r;
     cout<<2*getans(l-1,r-1,0,n-1,1).y<<endl;
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