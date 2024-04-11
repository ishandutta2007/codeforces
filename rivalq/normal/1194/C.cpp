//https://codeforces.com/contest/1194/problem/C
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
/********To check is s1 is subsequence of s2***********/
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
  string s,t,p;
  cin>>s>>t>>p;
  if(!isSubsequence(s,t)){
      cout<<"NO"<<endl;ret;
  }
  int arr1[26]={0},arr2[26]={0};
  for(int i=0;s[i]!='\0';i++)arr1[s[i]-97]++;
  for(int i=0;p[i]!='\0';i++)arr1[p[i]-97]++;
  for(int i=0;t[i]!='\0';i++)arr2[t[i]-97]++;
  int f=1;
  for(int i=0;i<26;i++){
      if(arr2[i]>arr1[i]){
          f=0;
          break;
      }
  }
  if(f)cout<<"YES"<<endl;
  else cout<<"NO"<<endl;
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