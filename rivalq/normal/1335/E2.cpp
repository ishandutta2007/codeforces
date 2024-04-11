//https://codeforces.com/contest/1335/problem/E2
#pragma GCC optimize "trapv" 
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
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
#define elasped_time 1.0 * clock() / CLOCKS_PER_SEC
const int inf1=1e9;
const ll inf2=1e18;
const int N=200010;
using namespace std;
using namespace __gnu_pbds;
#define ordered_set tree<pii, null_type,less<pii>, rb_tree_tag,tree_order_statistics_node_update>
int dirs[4][2] ={{1,0},{-1,0},{0,1},{0,-1}};
int bl[N];
int A[N];
int ans;
struct query{
    int l,r,cnt;
    bool operator<(const query &rhs){
        return (bl[l]==bl[rhs.l])?r<rhs.r:bl[l]<bl[rhs.l];
    }
};
int vis[N];
int f[N],ff[N];
vector<query> q;
struct mo{
    int res=0;
    int cl,cr;
    inline void check(int i,int A[]){
      if(vis[i]){
          ff[f[A[i]]]--;
          f[A[i]]--;
          ff[f[A[i]]]++;
          while(ff[res]==0)res--;
      }
      else{
          ff[f[A[i]]]--;
          f[A[i]]++;
          ff[f[A[i]]]++;
          res=max(res,f[A[i]]);
      }
      vis[i]=1-vis[i];
    }
    void compute(int m,int A[]){
        cl=q[0].l,cr=q[0].l-1;
        for(int i=0;i<m;i++){
            while(cl<q[i].l)check(cl++,A);
            while(cl>q[i].l)check(--cl,A);
            while(cr<q[i].r)check(++cr,A);
            while(cr>q[i].r)check(cr--,A);
            //cout<<cl<<" "<<cr<<" "<<res<<endl;
            ans=max(ans,res+q[i].cnt);
        }
        cout<<ans<<endl;
    }
    
}freq;
int solve(){
 int n;cin>>n;           
 map<int,vector<int>>mp;  
 rep3(n)cin>>A[i+1];
 ans=0;
 q.clear();
 for(int i=1;i<=n;i++)mp[A[i]].pb(i);
 for(auto i:mp){
     ans=max(ans,sz(i.y)); 
     int j=0;
     int cnt=1;
     if(sz(i.y)<=1)continue;
     while(1){
         int l=i.y[j]+1;
         int r=i.y[sz(i.y)-j-1]-1;
         //cout<<l<<" "<<r<<" "<<i.x<<endl;
         if(l>r)break;
         q.pb({l,r,2*cnt});
         cnt++;
         j++;
     }
 }
 if(sz(q)==0){
     cout<<ans<<endl;ret;
 }
 int m=q.size();
 int block=n/sqrt(m);
 for(int i=0;i<=n;i++)bl[i]=i/block;
 sort(all(q));
 for(int i=0;i<=max(n,200);i++)vis[i]=0,f[i]=0,ff[i]=0;
 freq.res=0;
 freq.compute(m,A); 
 ret;
}
int main(){
    IOS;
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #ifdef cat
    cat();
    #endif
    int t=1;cin>>t;
    while(t--){
        solve();
    }
    //cout<<elasped_time<<endl;       

    ret;
}