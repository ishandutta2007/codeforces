//https://codeforces.com/contest/408/problem/B
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
  string s1,s2;cin>>s1>>s2;int n=s1.length(),m=s2.length();
  int fn[26]={0},fm[26]={0};
  lop(i,n,1){
      fn[s1[i]-97]++;
  }
  lop(i,m,1){
      fm[s2[i]-97]++;
  }
  int visit[26]={0};
  ll area=0;
  lop(i,m,1){
      if(visit[s2[i]-97]==0){
          visit[s2[i]-97]=1;
          int t=min(fn[s2[i]-97],fm[s2[i]-97]);
          if(t==0) {cout<<-1;return 0;}
          else area+=t;
      }
  }
cout<<area<<endl;

}
int main(){
    IOS;
    ll t=1;//cin>>t;
    while(t--){
        solve();
    }
    ret;
}