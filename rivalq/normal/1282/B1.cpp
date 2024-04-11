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
  int n,p,k;cin>>n>>p>>k;
  ll arr[n];inarr(arr,n);
  sort(arr,arr+n);
  ll marr[n];
  lop(i,k,1){
  	marr[i]=arr[i];
  }
  rep(i,n,k){
  	marr[i]=marr[i-k]+arr[i];
  }
  int j=0,f=0;
  for(int i=0;i<n;i++){
  	if(marr[i]<=p)j=i,f=1;
  }
  if(f)j++;
  cout<<j<<endl;
  ret;
}
int main(){
    IOS;
    //freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
    int t=1;cin>>t;
    while(t--){
        solve();
    }
    ret;
}