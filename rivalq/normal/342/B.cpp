//https://codeforces.com/contest/342/problem/B
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
  int n,m,s,f;
  cin>>n>>m>>s>>f;
  int arr[m][3];
  lop(i,m,1)cin>>arr[i][0]>>arr[i][1]>>arr[i][2];
  if(s<f){
      int t=s;int i=1,mc=0;string se="";
      while(t!=f){
           if(i!=arr[mc][0]){se+="R";t++;}
           else{
               int li=arr[mc][1],ri=arr[mc][2];
               if((t<li || t>ri) &&(t+1<li || t+1>ri)) {se+="R";t++;}
               else {se+="X";}
               mc++;
           }      i++;

      }
      cout<<se<<endl;
  }
  else{
      int t=s;int i=1,mc=0;string se="";
      while(t!=f){
           if(i!=arr[mc][0]){se+="L";t--;}
           else{
               int li=arr[mc][1],ri=arr[mc][2];
               if((t<li || t>ri) &&(t-1<li || t-1>ri)) {se+="L";t--;}
               else {se+="X";}
               mc++;
           }      i++;

      }
      cout<<se<<endl;
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