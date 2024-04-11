//https://codeforces.com/contest/14/problem/B
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
  int n,x;cin>>n>>x;
  int arr[n][2];
  int ma=0;
  lop(i,n,1){
      int a,b;
      cin>>a>>b;
      ma=max(ma,max(a,b));
      arr[i][0]=min(a,b);
      arr[i][1]=max(a,b);
  }
  int v[ma+1]={0};
  for(int i=0;i<=ma;i++){
      int f=1;
      for(int j=0;j<n;j++){
          if(!(i>=arr[j][0] && i<=arr[j][1])){f=0;break;} 
      }
      if(f)v[i]=1;
  }int mi=mod;
  for(int i=0;i<=ma;i++){
      if(v[i]){
        mi=min(mi,abs(x-i));
      }
  }
  if(mi==mod)cout<<-1<<endl;
  else cout<<mi<<endl;

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