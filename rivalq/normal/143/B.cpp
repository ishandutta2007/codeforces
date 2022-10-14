//https://codeforces.com/contest/143/problem/B
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
  string s,d,in;
  cin>>s;int f=0;
  if(s[0]=='-'){s=s.substr(1,s.length()-1);f=1;}
  int n=s.length();
  if(count(all(s),'.')==0){
         d=".00";
         in=s;
  }
  else{
      int k=s.find(".");
      d=s.substr(k,n-k+1);
      if(d.length()<3)d+="0";
      if(d.length()>3)d=d.substr(0,3);
      in=s.substr(0,k);
  }
  n=in.length();
  reverse(all(in));
  for(int i=2;i<n-1;i+=4){
        in.insert(i+1,",");n++;
  }
  reverse(all(in));
  in+=d;
  in="$"+in;
  if(f){in="("+in+")";}cout<<in<<endl;
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