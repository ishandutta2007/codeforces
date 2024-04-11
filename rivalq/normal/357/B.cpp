//https://codeforces.com/contest/357/problem/B
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
  int n,m;
  cin>>n>>m;
  int arr[n+1]={0};
  int da[m][3];
  lop(i,m,1) cin>>da[i][0]>>da[i][1]>>da[i][2];
  //1->white 3->blue 2->red
  lop(i,m,1){
      int fi=da[i][0],se=da[i][1],th=da[i][2];
      int tarr[3]={0};
      if(arr[fi])tarr[arr[fi]-1]=1;
      if(arr[se]) tarr[arr[se]-1]=1;
      if(arr[th]) tarr[arr[th]-1]=1;
      if(arr[fi]==0){
          if(tarr[0]==0) {arr[fi]=1;tarr[0]=1;}
          else  if(tarr[1]==0) {arr[fi]=2;tarr[1]=1;}
          else if(tarr[2]==0) {arr[fi]=3;tarr[2]=1;}
      }
      if(arr[se]==0){
          if(tarr[0]==0) {arr[se]=1;tarr[0]=1;}
          else  if(tarr[1]==0) {arr[se]=2;tarr[1]=1;}
          else if(tarr[2]==0) {arr[se]=3;tarr[2]=1;}
      }
      if(arr[th]==0){
          if(tarr[0]==0) {arr[th]=1;tarr[0]=1;}
          else  if(tarr[1]==0) {arr[th]=2;tarr[1]=1;}
          else if(tarr[2]==0) {arr[th]=3;tarr[2]=1;}
      }

  }
  rep(i,n+1,1){
      cout<<arr[i]<<" ";
  }
  cout<<endl;
}
int main(){
    IOS;
    ll t=1;//cin>>t;
    while(t--){
        solve();
    }
    ret;
}