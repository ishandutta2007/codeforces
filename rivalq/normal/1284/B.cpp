//https://codeforces.com/contest/1284/problem/B
#include<bits/stdc++.h>
#define lop(i,n,a) for(int i=0;i<n;i+=a)
#define rep(i,n,a) for(int i=a;i<n;i++)
#define inarr(arr,n) lop(i,n,1)cin>>arr[i]
#define ll long long int
#define pb push_back
#define all(v) v.begin(),v.end()
#define endl "\n"
#define eb emplace_back
#define fr first
#define sc second
#define pii pair<int,int>
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define ret return 0
#define pi 3.1415926536
#define hell 1000000007
using namespace std;
vector<pair<int,vector<int>>> v,v2;
// syntax for min priority_queue of pairs
// priority_queue<pair<ll,ll>,vector<pair<ll,int>>,greater<pair<ll,int>>> q;
int bsh(int j,int n){
   int l=0,u=n-1;
   int mid=(l+u)/2;
   int ans=n;
   while(l<=u){
     mid=(l+u)/2;
     if(j<v2[mid].fr){
         ans=mid;
         u=mid-1;  
     }
     else{
         l=mid+1;
     } 
   }
   return (n-ans);
}
int solve(){
  int n;cin>>n;
  v.resize(n);
  int asc[n]={0};
  int mi[n];
  lop(i,n,1)mi[i]=hell;
  int cnt=0;
  lop(i,n,1){
      int s;cin>>s;
      int ma=0;
      int k=hell;
      int f=0;
      lop(j,s,1){
          int t;cin>>t;
          if(t>k)f=1;
          else{
              k=t;
          }
          ma=max(ma,t);
          mi[i]=min(mi[i],t);
          v[i].sc.pb(t);
      }
      v[i].fr=ma;
      if(f)asc[i]=1,cnt++;
      else{
          v2.pb({ma,v[i].sc});
      }
  }
  sort(all(v2));
  
  ll ans=0;
  for(int i=0;i<n;i++){
      if(asc[i])ans+=n;
      else{
          int k=v[i].sc.size();
          int j=mi[i];
          ans+=cnt;
          ans+=bsh(j,n-cnt);
          //cout<<ans<<endl;
      }
  }
  cout<<ans<<endl;
  ret;
}
int main(){
    IOS;
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int t=1;//cin>>t;
    while(t--){
        solve();
    }
    ret;
}