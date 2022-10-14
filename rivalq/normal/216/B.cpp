//https://codeforces.com/contest/216/problem/B
#include<bits/stdc++.h>
#define lop(i,n,a) for(int i=0;i<n;i+=a)
#define rep(i,n,a) for(int i=a;i<n;i++)
#define ll long long int
#define pb push_back
#define pii pair<int,int>
#define all(v) v.begin(),v.end()
#define endl "\n"
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define ret return 0
#define pi 3.1415926536
#define mod 1000000007
using namespace std;
int solve(){
  int n,m;cin>>n>>m;
  vector<vector<int>> v(n+1);
  for(int i=0;i<m;i++){
      int a,b;cin>>a>>b;
      v[a].pb(b);v[b].pb(a);
  }
  
  int arr[n+1]={0};
  int c=0;
  for(int i=1;i<=n;i++){
      if(arr[i]==0){
          if(v[i].size()<2)continue;
          int x=v[i][0];
          int s=1;
          int j=i;
          while(1){
              if(x==i){arr[x]=1;c+=s%2;break;}
              if(v[x].size()<2)break;
              if(v[x][0]==j){
                  arr[x]=1;arr[j]=1;j=x;x=v[x][1];s++;
              }
              else{
              arr[x]=1;   arr[j]=1; s++;j=x;x=v[x][0];
              }
          }
          
      }
  }
  
  if((n-c)%2)c++;
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