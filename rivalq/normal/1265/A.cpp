//https://codeforces.com/contest/1265/problem/A
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
  string s;
  cin>>s;
  int n=s.length();

  for(int i=0;i<n;i++){
      if(s[i]=='?'){
          int ba=0,bb=0,bc=0;
          if(i>0){
              if(s[i-1]=='a') ba=1;
              else if(s[i-1]=='b')bb=1;
              else if(s[i-1]=='c')bc=1;
          }
          if(i<n-1){
              if(s[i+1]=='a')ba=1;
              else if(s[i+1]=='b')bb=1;
              else if(s[i+1]=='c')bc=1;
          }
          if(ba==0)s[i]='a';
          else if(bb==0)s[i]='b';
          else if(bc==0)s[i]='c';
      }
  }
  for(int i=0;i<n-1;i++){
      if(s[i+1]==s[i]){cout<<-1<<endl;ret;}
  }
  cout<<s<<endl;
}
int main(){
    IOS;
    //freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
    int t=1;cin>>t;
    while(t--){
        solve();
    }
    ret;
}