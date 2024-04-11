//https://codeforces.com/contest/1334/problem/F
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
const int N=500000;
using namespace std;
using namespace __gnu_pbds;
#define ordered_set tree<pii, null_type,less<pii>, rb_tree_tag,tree_order_statistics_node_update>
int dirs[4][2] ={{1,0},{-1,0},{0,1},{0,-1}};
ll bit[N+10];
ll dp[N+10];
bool isSubsequence(int s1[],int s2[],int n,int m){
     int i=1;
     int j=1;
     while(i<=n && j<=m){
         if(s1[i]==s2[j])j++;
         i++;
     }
     return j==(m+1);
}
ll get(ll BIT[],int i){
    ll sum=0;
    while(i){
        sum+=BIT[i];
        i-=i&(-i);
    }
    return sum;
}
void upbit(ll BIT[],int i,int n,ll val){
    while(i<=n){
        BIT[i]+=val;
        i+=i&(-i);
    }
}
int solve(){
  int n;cin>>n;          
  int a[n+1];rep3(n)cin>>a[i+1];
  ll  p[n+1];rep3(n)cin>>p[i+1];
  int m;cin>>m;
  int b[m+1];rep3(m)cin>>b[i+1];
  if(isSubsequence(a,b,n,m)==0){
      cout<<"NO"<<endl;ret;
  } 
  if(n==1){
      cout<<"YES"<<endl;
      cout<<0<<endl;ret;
  }         
  set<pii>s;
  for(int i=1;i<=n;i++)s.insert({a[i],i});
  map<int,vector<int>>mp;
  for(int i=1;i<=n;i++)mp[a[i]].pb(i);
  for(int i=1;i<=n;i++)dp[i]=-inf2;
  for(auto i:mp[b[1]])dp[i]=p[i];
  while(!s.empty() && s.begin()->x<=b[1]){
      if(p[s.begin()->y]>0){
          upbit(bit,s.begin()->y,n,p[s.begin()->y]);
      }
      s.erase(s.begin());
  }
  for(int i=2;i<=m;i++){
     int b1=b[i-1];
     int b2=b[i];
     vector<int>v;
     for(auto i:mp[b1])v.pb(i);
     for(auto i:mp[b2])v.pb(i);
     sort(all(v));
     int last=0;
     ll best_so_far=-inf2;
     for(auto i:v){
         best_so_far+=get(bit,i)-get(bit,last);
         if(a[i]==b1)best_so_far=max(best_so_far,dp[i]);
         else dp[i]=p[i]+best_so_far;
         last=i;
     }
     while(!s.empty() && s.begin()->x<=b2){
         if(p[s.begin()->y]>0){
             upbit(bit,s.begin()->y,n,p[s.begin()->y]);
         }
         s.erase(s.begin());
     }  
  }
  ll ans=-inf2;
  ll sum=0;
  for(int i=1;i<=n;i++){
      sum+=p[i];
      if(a[i]==b[m]){
          ans=max(ans,dp[i]+get(bit,n)-get(bit,i));
      }
  }
  cout<<"YES"<<endl;
  cout<<sum-ans<<endl;
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