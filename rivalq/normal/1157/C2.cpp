//https://codeforces.com/problemset/problem/1157/C2
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
 int n;cin>>n;           
 int a[n];rep3(n)cin>>a[i];
 if(n==1){
     cout<<a[0]<<endl;
     cout<<'L'<<endl;
     ret;
 }
 vector<int>s;
 s.pb(a[0]);
 int i=1;
 while(i<n && s.back()<a[i]){
     s.pb(a[i]);
     i++;
 }
 vector<int>v;
 v.pb(a[n-1]);
 i=n-2;
 while(i>=0 && a[i]>v.back()){
     v.pb(a[i]);
     i--;
 }
 i=0;int j=0;
 int n1=sz(s);
 int n2=sz(v);
 string ans="";
 int cnt=0;
 while(i<n1 && j<n2 && cnt<n){
     if(s[i]==v[j])break;
     else if(s[i]<v[j]){
         cnt++;i++;
         ans+='L';
     }
     else{
         cnt++;j++;
         ans+='R';
     }
 }
 int cnt1=1,cnt2=1;
 if(i==n1)cnt1--;
 if(j==n2)cnt2--;
 while(i<n1-1 && s[i]<s[i+1])cnt1++,i++;
 while(j<n2-1 && v[j]<v[j+1])cnt2++,j++;
 if(cnt<n){
     if(cnt1>cnt2){
         rep3(cnt1)ans+='L';
     }
     else rep3(cnt2)ans+='R';
 }
 cout<<cnt+max(cnt1,cnt2)<<endl;
 cout<<ans<<endl;
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