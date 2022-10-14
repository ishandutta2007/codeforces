//https://codeforces.com/contest/349/problem/B
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
  int v,f=0;cin>>v;
  int arr[10]={mod};
  lop(i,9,1)cin>>arr[i+1];
  int mi=arr[1];int t=1;
  lop(i,9,1){
      if(mi>=arr[i+1]){mi=arr[i+1];t=i+1;}
  }
  int len=v/mi;
  if(len){
  v=v%mi;
  int nu[10]={0};
  nu[t]+=len;
  int i=9;
  while(v<arr[i]-mi && i>t && arr[i]!=mi)i--;
 while(v>=arr[i]-mi && i>t && arr[i]!=mi){
      v=v-arr[i]+mi;
      nu[t]--;nu[i]++;
      while(v<arr[i]-mi && i>t && arr[i]!=mi)i--;
  }
  for(int i=9;i>=1;i--){
      lop(j,nu[i],1)cout<<i;
    }
  }
  else cout<<-1;
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