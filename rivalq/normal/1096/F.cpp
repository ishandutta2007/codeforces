//https://codeforces.com/contest/1096/problem/F
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
const int inf1=1e9;
const ll inf2=1e18;
const int N=300000;
using namespace std;
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 
int dirs[4][2] ={{1,0},{-1,0},{0,1},{0,-1}};
#define cat
ll fact[N+1],infact[N+1];
ll xymodp(ll x,ll y,ll p){
    ll a=1;
    x%=p;
    while(y){
        if(y&1)a=(a*x)%p;
        x=(x*x)%p;
        y/=2;
    }
    return a;
}
void init(){
    fact[0]=1;
    rep(i,1,N)fact[i]=(i*fact[i-1])%narak;
    rep(i,1,N)infact[i]=xymodp(fact[i],narak-2,narak);
    infact[0]=1;infact[1]=1;
}
ll count(vector<int>v,int m){
  ordered_set s1;
  ll ans=0;
  int cnt=0;
  for(auto i:v){
      ans+=(cnt-s1.order_of_key(i));
      cnt++;
      s1.insert(i);
  }
  return ans*fact[m]%narak;
}
int solve(){
  int n;cin>>n;          
  set<int>s;rep3(n)s.insert(i+1);
  vector<int>v;
  int arr[n];rep3(n){
      cin>>arr[i];
      if(arr[i]==-1)arr[i]=0;
      else s.erase(arr[i]),v.pb(arr[i]);
  }
  ll m=sz(s);
  if(m==0){
      ll val=count(v,m);
      cout<<val<<endl;
      ret;
  }
  ll cnt1=m*(m-1)%narak*fact[m]%narak*xymodp(4,narak-2,narak)%narak;
  cnt1=(cnt1+count(v,m))%narak;  
  ordered_set s1;
  map<int,pii>mp;
  int t=m;
  int val=*s.begin();
  s.erase(val);
  for(int i=0;i<n;i++){
      if(arr[i]==0){
          t--;
      }
      else{
          mp[arr[i]].x=t;
          mp[arr[i]].y=m-t;
      }
  }
  ll dp=0;
  ll cnt2=0;
  for(auto i:mp){
      if(val>i.x){
          dp=dp+i.y.y;
      }
      else{
          dp=dp+i.y.x;
      }
  }
  cnt2=(cnt2+dp)%narak;
  int last=val+1;
  for(auto i:s){
    for(int j=last;j<i;j++){
       if(mp.count(j)){
           dp=dp+mp[j].y-mp[j].x;
       }
    }
    cnt2=(cnt2+dp)%narak;
    last=i+1;
  }
  cnt2=cnt2*fact[m-1]%narak;
  cnt1=(cnt1+cnt2)%narak;
  cnt1=cnt1*infact[m]%narak;
  cout<<cnt1<<endl;
 ret;
}
int main(){
    IOS;
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #ifdef cat
    init();
    #endif
    int t=1;//cin>>t;
    while(t--){
        solve();
    }
    ret;
}