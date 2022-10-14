//https://codeforces.com/contest/374/problem/B
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
  ll c=1;
  for(int i=0;i<n;){
       if(s[i]+s[i+1]-'0'-'0'==9){
           int j=i;
           char t=s[j];
           while(s[j]==t){
               j++;
               t=s[i+(j-i)%2];
           }
           if((j-i)%2)
           c=c*(1+(j-i)/2);
           i=j;
       }
       else i++;       
  }
  cout<<c<<endl;
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