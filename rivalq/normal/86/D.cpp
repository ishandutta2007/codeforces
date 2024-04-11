//https://codeforces.com/problemset/problem/86/D
#include<bits/stdc++.h>
#define rep(i,a,n)     for(int i=a;i<n;i++)
#define rep3(n)        for(int i=0;i<n;i++)
#define inarr(arr,n)   rep(i,a,n)cin>>arr[i]
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
const int N=200010;
using namespace std;
int dirs[4][2] ={{1,0},{-1,0},{0,1},{0,-1}};
long long A[N];
int BL[N];
struct query{
    int l,r,id;
    bool operator<(const query &rhs){
       return (BL[l]==BL[rhs.l])?r<rhs.r:BL[l]<BL[rhs.l];
    }
}q[N];

int vis[N];
int f[5*N+1];
long long res=0;
int cl,cr;
long long ans[N];
inline void check(int i){
if(vis[i]){
    res-=A[i]*(2*f[A[i]]-1);
    f[A[i]]--;
}
else{
    f[A[i]]++;
    res+=A[i]*(2*f[A[i]]-1);  
}
vis[i]=1-vis[i];
}
void compute(int m){
    cl=q[0].l,cr=q[0].l-1;
    for(int i=0;i<m;i++){
        while(cl<q[i].l)check(cl++);
        while(cl>q[i].l)check(--cl);
        while(cr<q[i].r)check(++cr);
        while(cr>q[i].r)check(cr--);
        ans[q[i].id]=res;
    }
    for(int i=0;i<m;i++)cout<<ans[i]<<endl;
}

int solve(){
 int n,m;cin>>n>>m;           
 rep3(n)cin>>A[i+1];
 rep3(m){
     int l,r;cin>>l>>r;
     q[i].l=l;
     q[i].r=r;
     q[i].id=i;
 } 
 int block=sqrt(n);
 for(int i=0;i<=n;i++)BL[i]=i/block;          
 sort(q,q+m);
 compute(m);
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