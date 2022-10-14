//https://codeforces.com/contest/1108/problem/C
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
int cnt(string &s1,string &s2){
    int c=0;
    for(int i=0;s1[i]!='\0';i++){
        c+=(s1[i]!=s2[i]);
    }
    return c;
}
int solve(){
  int n;cin>>n;
  string s;cin>>s;          
  vector<string> v;
  int x=n%3;
  string ans="BGR";
  int y=n/3;
  for(int i=0;i<6;i++){
    string t="";
    rep3(y)t+=ans;
    t+=ans.substr(0,x);
    v.pb(t); 
    next_permutation(all(ans));
  }
  int mi=n;
  int j=0;
  for(int i=0;i<6;i++){
    int x=cnt(s,v[i]);
    if(x<=mi){
        mi=x;
        j=i;
    }
  }
  cout<<mi<<endl;
  cout<<v[j]<<endl;
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