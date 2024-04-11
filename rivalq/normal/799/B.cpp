//https://codeforces.com/contest/799/problem/B
#include<bits/stdc++.h>
#define lop(i,n,a) for(int i=0;i<n;i+=a)
#define rep(i,n,a) for(int i=a;i<n;i++)
#define ll long long int
#define pb push_back
#define all(v) v.begin(),v.end()
#define endl "\n"
#define eb emplace_back
#define fr first
#define sc second
#define inarr(arr,n) lop(i,n,1)cin>>arr[i]
#define pii pair<int,int>
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define ret return 0
#define pi 3.1415926536
#define mod 1000000007
using namespace std;
int solve(){
  int n;cin>>n;
  ll pri[n];int c1[n],c2[n];
  inarr(pri,n);inarr(c1,n);inarr(c2,n);
  priority_queue<pair<ll,ll>,vector<pair<ll,int>>,greater<pair<ll,int>>>mp1[4];
  int sell[4]={0};
  sell[1]=0,sell[2]=0;
  lop(i,n,1){
      mp1[c1[i]].push({pri[i],c2[i]});
      if(c1[i]!=c2[i])
      mp1[c2[i]].push({pri[i],c1[i]});
      sell[c1[i]]++,sell[c2[i]]++;
  }
  map<ll,int> stock;
  for(int i=0;i<n;i++){
      stock.insert({pri[i],1});
  }
  int m;cin>>m;
  lop(i,m,1){
      int c;cin>>c;
      if(sell[c]){
          int f=0;
          while(f==0){
               if(stock[mp1[c].top().fr]!=0){
               cout<<mp1[c].top().fr<<" "; 
               stock[mp1[c].top().fr]=0; 
               f=1;
               sell[c]--;sell[mp1[c].top().sc]--;
               }
               else{
                   mp1[c].pop();
               }
          }
      }
      else cout<<-1<<" ";
  }
  cout<<endl;
}  


int main(){
    IOS;
    //freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
    ll t=1;//cin>>t;
    while(t--){
        solve();
    }
    ret;
}