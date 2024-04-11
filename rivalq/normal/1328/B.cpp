//https://codeforces.com/contest/1328/problem/B
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
const int N=100000;
using namespace std;
int dirs[4][2] ={{1,0},{-1,0},{0,1},{0,-1}};

int solve(){
  ll n,k;cin>>n>>k;
  string s=""; 
  rep3(n)s+="a"; 
  if((n-1)*(n-2)/2==k){
      s[1]=s[2]='b';
      cout<<s<<endl;ret;
  }        
  if((n-1)*(n-2)/2>=k){
    ll x=1;
    ll val=0;
    int cnt=1;
    while(val+x<k){
        val+=x;
        x++;
        cnt++;
    }
    int idx1=n-1-cnt;
    ll  d=k-val;
    int idx2=n-1-d+1;
    //cout<<idx1<<" "<<idx2<<endl;
    s[idx1]='b';
    s[idx2]='b';
  }        
  else{
      s[0]='b';
      int idx=n-(k-(n-1)*(n-2)/2);
      s[idx]='b';  
  }
  cout<<s<<endl;
 ret;
}
int main(){
    IOS;
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #ifdef cat
    cat();
    #endif
    int t=1;cin>>t;
    while(t--){
        solve();
    }
    ret;
}