//https://codeforces.com/contest/873/problem/D
#pragma GCC optimize "trapv" 
#include<bits/stdc++.h>
#define rep(i,a,n)     for(int i=a;i<n;i++)
#define rep3(n)        for(int i=0;i<n;i++)
#define inarr(arr,n)   rep(i,a,n)cin>>arr[i]
#define ll             long long int
#define pb             push_back
#define all(v)         v.begin(),v.end()
#define endl           "\n"
#define eb             emplace_back
#define x              first
#define y              second
#define gcd(a,b)       __gcd(a,b)
#define mem1(a)        memset(a,-1,sizeof(a))
#define pres(a,x)      a.find(x)!=a.end()
#define sz(a)          (int)a.size()
#define pii            pair<int,int>
#define IOS            ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define ret            return 0
#define pi             3.1415926536
#define hell           1000000007
#define narak          998244353
const int inf1=1e9;
const ll inf2=1e18;
const int N=200000;
using namespace std;
int dirs[4][2] ={{1,0},{-1,0},{0,1},{0,-1}};
int k;
int a[N+10];
void zaker(int start,int end){
    if(start==end-1){
        return;
    }
    if(k==0){
        sort(a+start,a+end);
        return ;
    }
    int mid=(start+end)/2;
    k=k-2;
    zaker(start,mid);
    zaker(mid,end);
}
int solve(){
  int n;cin>>n>>k; 
  if(k%2==0){
      cout<<-1<<endl;ret;
  }        
  for(int i=0;i<n;i++){
      a[i]=n-i;
  }
  if(k==1){
      rep3(n)cout<<i+1<<" ";cout<<endl;
  }          
  else{
      k--;
      zaker(0,n);if(k>0){
          cout<<-1<<endl;ret;
      }
      rep3(n)cout<<a[i]<<" ";cout<<endl;
  } 
 ret;
}
int main(){
    IOS;
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #ifdef cat
    cat();
    #endif
    int t=1;//cin>>t;
    while(t--){
        solve();
    }
    ret;
}