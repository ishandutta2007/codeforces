//https://codeforces.com/contest/260/problem/A
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
#define pii pair<int,int>
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define ret return 0
#define pi 3.1415926536
#define mod 1000000007
using namespace std;
int solve(){
  int a,b,n;
  cin>>a>>b>>n;
  if(a%b==0 && b>10 )
  {   cout<<a;
      lop(i,n,1)cout<<0;
  }
  else {
      a=10*a;
      int q=0;
      for(int i=0;i<10;i++){
          if((a+i)%b==0){
              a+=i;
              q=1;
              break;
          }
      }
      if(q && n==1)cout<<a<<endl;
      else if(q==0) cout<<-1<<endl;
      else{
         
          n--;
          cout<<a;
          for(int i=0;i<n;i++)cout<<0;
          cout<<endl;
          
      }
  }
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