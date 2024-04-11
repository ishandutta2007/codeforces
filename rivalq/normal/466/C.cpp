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
  ll n;cin>>n;
  ll arr[n];
  inarr(arr,n);
  ll presum[n];
  presum[0]=arr[0];
  rep(i,n,1){
  	presum[i]=presum[i-1]+arr[i];
  }
  if(presum[n-1]%3){
  	cout<<0<<endl;
  	ret;
  }
  ll k =presum[n-1]/3;
  vector<int> c1,c2;
  lop(i,n-1,1){
  	if(i<n-2 && presum[i]==k)c1.pb(i);
  	if(i>0 && presum[i]==2*k)c2.pb(i);
  }
  ll sum=0;
  int i=0,j=0;
  n=c1.size();
  int m=c2.size();
  while(i<n && j<m){
  	  while(j<m && c1[i]>=c2[j])j++;
      sum+=m-j;
      i++;
  }
  //cout<<c1<<" "<<c2<<endl;
  cout<<sum<<endl;
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