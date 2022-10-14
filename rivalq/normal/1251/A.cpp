//https://codeforces.com/contest/1251/problem/A
#include<bits/stdc++.h>
#define rep1(i,n,a) for(int i=0;i<n;i+=a)
#define rep2(i,n,a) for(int i=a;i<n;i++)
#define rep3(n)     for(int i=0;i<n;i++)
#define inarr(arr,n) lop(i,n,1)cin>>arr[i]
#define ll long long int
#define pb push_back
#define all(v) v.begin(),v.end()
#define trav(a,x) for(auto x:a)
#define endl "\n"
#define eb emplace_back
#define fr first
#define sc second
#define gcd(a,b) __gcd(a,b)
#define pres(a,x) a.find(x)!=a.end()
#define sz(a) (int)a.size()
#define pii pair<int,int>
#define psi pair<string,int>
#define pss pair<string,string>
#define pll pair<ll,ll>
#define vec vector<int>
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define ret return 0
#define pi 3.1415926536
#define hell 1000000007
#define narak 998254
const int inf1=1e9;
const ll inf2=1e18;
using namespace std;
int dirs[4][2] ={{1,0},{-1,0},{0,1},{0,-1}};
// syntax for min priority_queue of pairs
// priority_queue<pair<ll,ll>,vector<pair<ll,int>>,greater<pair<ll,int>>> q;
int solve(){
  string s;
  cin>>s;
  int arr[26]={0};
  int n=s.length();
  int i=0;
  while(i<n){
      int j=i,cnt=0;
      while(j<n &&s[j]==s[i])j++,cnt++;
      if(cnt&1)arr[s[i]-97]=1;
      i=j;
  }
  for(int i=0;i<26;i++){
      if(arr[i]){
          char c=i+97;
          cout<<c;
      }
  }
  cout<<endl;
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