//https://codeforces.com/contest/66/problem/B
#include<bits/stdc++.h>
#define lop(i,n,a) for(int i=0;i<n;i+=a)
#define rep(i,n,a) for(int i=a;i<n;i++)
#define ll long long int
#define pb push_back
#define all(v) v.begin(),v.end()
#define endl "\n"
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define ret return 0
#define pi 3.1415926536
#define mod 1000000007
using namespace std;
int solve(){
  int n,ma=0;
  cin>>n;
  vector<int> v(n);lop(i,n,1) cin>>v[i];
  if(n==1||n==2){cout<<n<<endl;ret;}

  lop(i,n,1){
        int h=v[i], b=1,j=i+1;
        while(j<n &&h>=v[j]){h=v[j];j++;b++;}
        h=v[i];j=i-1;
        while(j>=0&&h>=v[j]){h=v[j];j--;b++;}
        ma=max(b,ma);
      
  }
  cout<<ma<<endl;
}
int main(){
    IOS;
    ll t=1;//cin>>t;
    while(t--){
        solve();
    }
    ret;
}