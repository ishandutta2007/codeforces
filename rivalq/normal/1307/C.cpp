//https://codeforces.com/problemset/problem/1307/C
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
  string s;cin>>s;    
  int n=s.length();    
  ll ma=0;  
  for(char a='a';a<='z';a++){
    for(char b='a';b<='z';b++){
        int arr[26]={0};
        rep3(n)arr[s[i]-97]++;
        ll ans=0;
        for(int i=0;i<n;i++){
           arr[s[i]-97]--; 
           if(s[i]==a){
               ans+=arr[b-97];
           }
        }
        ma=max(ans,ma); 
    }
  }
  int a=0;
  ll arr[26]={0};
  rep3(n)arr[s[i]-97]++;
  rep3(26)ma=max(arr[i],ma);
  cout<<ma<<endl;
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