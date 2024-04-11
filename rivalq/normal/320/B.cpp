//https://codeforces.com/contest//problem/
#include<bits/stdc++.h>
#define lop(i,n,a) for(int i=0;i<n;i+=a)
#define pii pair<int,int>
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
  int n;
  cin>>n;
  int arr[n+1][n+1];
  lop(i,n+1,1){
      lop(j,n+1,1) arr[i][j]=0;
  }
  vector<pii> v;
  lop(i,n,1){
      int q,x,y;
      cin>>q>>x>>y;
      if(q==1){
          int sn=v.size();
          for(int i=0;i<sn;i++){
               int l=v[i].first,r=v[i].second;
               if((x>l && x<r) || (y>l && y<r)) arr[sn+1][i+1]=1;
               if((l>x && l<y) || (y>r && x<r)) arr[i+1][sn+1]=1;
          }
           v.push_back({x,y});
      }
      if(q==2){
        
        for(int i=1;i<=n;i++){  
          for(int j=1;j<=n;j++){
              for(int k=1;k<=n;k++){
                  if(arr[j][i] && arr[i][k]) arr[j][k]=1;
              }
          }
        }  
          if(arr[x][y]) cout<<"YES"<<endl;
          else cout<<"NO"<<endl;
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