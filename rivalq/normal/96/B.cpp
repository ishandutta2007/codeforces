//https://codeforces.com/contest/96/problem/    B
#include<bits/stdc++.h>
#include<stdlib.h>
#define lop(i,n,a) for(int i=0;i<n;i+=a)
#define rep(i,n,a) for(int i=a;i<n;i++)
#define ll long long int
#define pb push_back
#define all(v) v.begin(),v.end()
#define endl "\n"
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define ret return 0
#define pi 3.1415926536
#define mod 1000000007
using namespace std;
ll gen(int i) { 
    string s=""; 
    while (i>=1) {
      if(i&1){s=s+"4";i=(i-1)/2;} 
      else{s=s+"7";i=(i-2)/2;}       
    } 
    ll t=0;
    for(int i=0;i<s.length();i++){
        t=t+(s[i]-'0')*pow(10,i);
    }
    return t; 
} 
int ch(ll x){
    int fs=0,ss=0;
    while(x!=0){
        int t=x%10;
        if(t==4)fs++;
        else ss++;
        x/=10;
    }
    return fs==ss;
}
int solve(){
  int n;cin>>n;
  for(int i=1;;i++){
      ll t=gen(i);
      if(t>=n && ch(t)){cout<<t<<endl;ret;}
  }
}
int main(){
    IOS;
    //freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
    ll t=1;//cin>>t;
    while(t--){
        solve();
    }
    ret;
}