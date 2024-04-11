//https://codeforces.com/contest/1287/problem/B
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
int n,k;
bool ch(string s1,string s2,string s3){
    for(int i=0;i<k;i++){
        if(!(s1[i]==s2[i] && s2[i]==s3[i] ||(s1[i]!=s2[i] && s2[i]!=s3[i] && s3[i]!=s1[i])))return false;
    }
    return true;
}
int solve(){
  cin>>n>>k;
 
  vector<string> v;
  map<string,int> mp;
  lop(i,n,1){
      string s;cin>>s;
      v.pb(s);
      mp[s]=i;
  }

  ll ans=0;
  for(int i=0;i<n;i++){
      for(int j=i+1;j<n;j++){
           string vi;
           for(int l=0;l<k;l++)vi+=(v[i][l]==v[j][l])?v[i][l]:'S'+'T'+'E'-v[i][l]-v[j][l];
            if(mp.find(vi)!=mp.end())ans=ans+(mp[vi]>j);
        }
   }
      
  cout<<ans<<endl;
}

int main(){
    IOS;
    //freopen("output1.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    
    int t=1;//cin>>t;
    while(t--){
        solve();
    }
    ret;
}