//https://codeforces.com/contest/228/problem/B
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
int ch(int x,int y,int nb,int mb){
      if(x>=1 && x<=nb && y>=1 && y<=mb) return 1;
      return 0;
}
int solve(){
  int na,ma;
  cin>>na>>ma;
  int arr1[na+1][ma+1]={0};
  rep(i,na+1,1){
      rep(j,ma+1,1){
          char t;
          cin>>t;
          arr1[i][j]=t-'0';
      }
  }

  int nb,mb;
  cin>>nb>>mb;
  int arr2[nb+1][mb+1]={0};
  rep(i,nb+1,1){
      rep(j,mb+1,1){
          char t;cin>>t;
          arr2[i][j]=t-'0';
      }
  }
  int oa=0;int xm=0,ym=0;
  for(int x=-na;x<=nb;x++){
      for(int y=-ma;y<=mb;y++){
          int ta=0;
          for(int i=1;i<=na;i++){
              for(int j=1;j<=ma;j++){
                 if(ch(i+x,j+y,nb,mb)){
                     ta+=arr1[i][j]*arr2[i+x][y+j];
                 }
              }
          }
          if(oa<ta) {
              oa=ta;
              xm=x;ym=y;
          }
      }
  }
  
      
  
 cout<<xm<<" "<<ym<<endl;
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