//https://codeforces.com/contest/133/problem/B
#include<bits/stdc++.h>
#define lop(i,n,a) for(int i=0;i<n;i+=a)
#define rep(i,n,a) for(int i=a;i<n;i++)
#define ll long long int
#define pb push_back
#define all(v) v.begin(),v.end()
#define endl '\n'
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define ret return 0
#define pi 3.1415926536
#define mod 1000003
using namespace std;
ll mpo(int k){
   if(k==0) return 1;
   if(k==1) return 16;
   else return (16*mpo(k-1))%mod;
}
int solve(){
  string s;
  cin>>s;reverse(all(s));
 map<char,int> mp;
 char arr[8]={ '>', '<','+', '-','.',',','[', ']'};
 for(int i=8;i<16;i++){
     mp.insert({arr[i-8],i});
 }
 ll va=0;
 for(int i=0;s[i]!='\0';i++){
     va=(va+mp[s[i]]*mpo(i))%mod;
 }
 cout<<va<<endl;

}
int main(){
    IOS;
    ll t=1;//cin>>t;
    while(t--){
        solve();
    }
    ret;
}