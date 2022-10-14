//https://codeforces.com/problemset/problem/550/C
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
bool isSubsequence(string s1,string s2){
     if(s1.length()>s2.length())return false;
     int i=0,j=0,n1=s1.length(),n2=s2.length();
     while(i<n1 && j<n2){
         if(s1[i]==s2[j]){
             i++;
             j++;
         }
         else{
             j++;
         }
     }
     return i==n1;
}
int solve(){
  string s;cin>>s;
  set<int> se;
  int n=s.length();
  for(int i=0;i<1000;i+=8)se.insert({i});
  for(auto i:se){
    string t=to_string(i);
    if(isSubsequence(t,s)){
        cout<<"YES"<<endl;
        cout<<t<<endl;
        ret;
    }
  }
  cout<<"NO\n";
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