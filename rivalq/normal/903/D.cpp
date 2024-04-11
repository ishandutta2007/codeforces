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
#define ordered_set tree<pair<ll,ll>, null_type,less<pair<ll,ll>>, rb_tree_tag,tree_order_statistics_node_update>
int dirs[4][2] ={{1,0},{-1,0},{0,1},{0,-1}};
int solve(){
  int n;cin>>n;          
  long double a[n];rep3(n)cin>>a[i];
  ordered_set s1,s2;
  for(int i=0;i<n;i++)s2.insert({a[i],i});
  long double  ans=0;
  for(int i=0;i<n;i++){
     int p1=s1.order_of_key({a[i]+2,-1})-s1.order_of_key({a[i]-1,-1});
     p1=sz(s1)-p1;
     int p2=s2.order_of_key({a[i]+2,-1})-s2.order_of_key({a[i]-1,-1});
     p2=sz(s2)-p2;
     unsigned ll p=abs(p1-p2);
     p=p*a[i];
     if(p1>p2)ans+=p;
     else ans-=p;
     s2.erase({a[i],i});
     s1.insert({a[i],i});
  }
  if(ans<0){
      cout<<"-"<<(unsigned ll)abs(ans)<<endl;
  }         
  else{
      cout<<(unsigned long long)ans<<endl;
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