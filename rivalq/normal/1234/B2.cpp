//https://codeforces.com/contest/1234/problem/B2
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
// syntax for min priority_queue of pairs
// priority_queue<pair<ll,ll>,vector<pair<ll,int>>,greater<pair<ll,int>>> q;
int solve(){
  int n,k;cin>>n>>k;
  int arr[n];inarr(arr,n);
  queue<int> q;
  map<int,int> mp;
  lop(i,n,1)mp[arr[i]]=0;
  int i=0;
  int j=0;
  while(i<n){
      if(j<k){
        if(mp[arr[i]]==0)q.push(arr[i]),j++,mp[arr[i]]=1;
      }

      else{
          if(mp[arr[i]]==0){
          mp[q.front()]=0;    
          q.pop();
          q.push(arr[i]);
          mp[arr[i]]=1;
         } 
        }
      i++;
  }
  stack<int> s;
  while(!q.empty()){
      s.push(q.front());
      q.pop();
  }
  cout<<s.size()<<endl;
  while(!s.empty()){
      cout<<s.top()<<" ";
      s.pop();
  }
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