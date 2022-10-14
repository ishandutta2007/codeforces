#include<bits/stdc++.h>
#define lop(i,n,a) for(int i=0;i<n;i+=a)
#define rep(i,n,a) for(int i=a;i<n;i++)
#define inarr(arr,n) lop(i,n,1)cin>>arr[i]
#define ll long long int
#define pb push_back
#define all(v) v.begin(),v.end()
#define endl "\n"
#define eb emplace_back
#define fr first
#define sc second
#define pii pair<int,int>
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define ret return 0
#define pi 3.1415926536
#define hell 1000000007
using namespace std;
// syntax for min priority_queue of pairs
// priority_queue<pair<ll,ll>,vector<pair<ll,int>>,greater<pair<ll,int>>> q;
int solve(){
  int n;cin>>n;
  int arr[n]={0};
  int sum1,sum2,sum3;
  cout<<"? 1 2"<<endl;
  cout<<flush;
  cin>>sum1;
  cout<<"? 2 3"<<endl;
  cout<<flush;
  cin>>sum2;
  cout<<"? 1 3"<<endl;
  cout<<flush;
  cin>>sum3;
  arr[0]=(sum1-sum2+sum3)/2;
  arr[1]=sum1-arr[0];
  arr[2]=sum3-arr[0];
  for(int i=3;i<n;i++){
      int sum;
      cout<<"? 1 "<<i+1<<endl;
      cout<<flush;
      cin>>sum;
      arr[i]=sum-arr[0];
  }
  cout<<"! ";
  for(int i=0;i<n;i++)cout<<arr[i]<<" ";cout<<endl;
  cout<<flush;
  ret;
}
int main(){
    IOS;
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int t=1;//cin>>t;
    while(t--){
        solve();
    }
    ret;
}