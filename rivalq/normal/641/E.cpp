//https://codeforces.com/problemset/problem/641/E
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
const int N=100000;
using namespace std;
using namespace __gnu_pbds;
#define ordered_set tree<pii, null_type,less<pii>, rb_tree_tag,tree_order_statistics_node_update>
int dirs[4][2] ={{1,0},{-1,0},{0,1},{0,-1}};
int solve(){
 int n;cin>>n;           
 map<int,int>mp;
 map<int,int>time;
 vector<pair<int,pii>>q;
 int cnt=0;
 rep3(n){
   int a,t,x;cin>>a>>t>>x;
   if(a==3)time[t]=x,q.pb({3,{t,cnt++}});
   else{
       q.pb({a,{t,x}});
   }
 }
 vector<int>ans(cnt);
 int i=0;
 while(i<n && q[i].x==3)ans[q[i].y.y]=0,i++;
 while(i<n){
     int k=i;
     while(k<n && q[k].x!=3)k++;
     while(k<n && q[k].x==3)k++;
     sort(q.begin()+i,q.begin()+k,[&](pair<int,pii> p1,pair<int,pii>p2){return p1.y.x<p2.y.x;});
     while(i<k){
       if(q[i].x==1)mp[q[i].y.y]++;
       else if(q[i].x==2)mp[q[i].y.y]--;
       else {
          ans[q[i].y.y]=mp[time[q[i].y.x]];
       }
       i++;
     }
 }
 for(auto i:ans)cout<<i<<endl;
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