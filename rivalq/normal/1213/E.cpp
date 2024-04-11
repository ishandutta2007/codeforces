//https://codeforces.com/contest/1213/problem/E
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
string arr[81];
int solve(){
 int n;cin>>n;   
 string s,t;  cin>>s>>t;  
 cout<<"YES"<<endl;      
 if(s[0]==s[1] || t[0]==t[1]){
     if(t[0]!=t[1]){
         reverse(all(t));
         string ans=t;
         ans+=('a'+'b'+'c'-t[0]-t[1]);
         rep3(n)cout<<ans;
          cout<<endl;
     }
     else if(s[0]!=s[1]){
         reverse(all(s));
         string ans=s;
         ans+=('a'+'b'+'c'-s[0]-s[1]);
         rep3(n)cout<<ans;
          cout<<endl;
     }
     else{
         rep3(n)cout<<"abc";
          cout<<endl;
     }
     ret;
 }  
 if(s==t){
     reverse(all(s));
     string ans=s;
     ans+=(97+98+99-s[0]-s[1]);
     rep3(n)cout<<ans;cout<<endl;
     ret;
 }          
 if(s[0]==t[0] && s[1]!=t[1]){
     char c1=s[1];
     char c2=t[1];
     rep3(n)cout<<c1;
     rep3(n)cout<<c2;
     rep3(n)cout<<s[0];
      cout<<endl;
     ret;
 }
 if(s[1]==t[1] && s[0]!=t[0]){
     char c1=s[0];
     char c2=t[0];
     rep3(n)cout<<s[1];
     rep3(n)cout<<c2;
     rep3(n)cout<<c1;
      cout<<endl;
     ret;
 }
 if(s[1]==t[0] && t[1]==s[0]){
     char c1=t[0],c2=t[1];
     char c3='a'+'b'+'c'-c1-c2;
     rep3(n)cout<<c1;
     rep3(n)cout<<c3;
     rep3(n)cout<<c2;
      cout<<endl;
     ret;
 }
 else {
     if(s[1]!=t[0] && s[0]==t[1]){
         string temp=s;
         s=t;
         t=temp;
     }
     rep3(n)cout<<t[1];
     rep3(n)cout<<s[1];
     rep3(n)cout<<s[0];
      cout<<endl;
     ret;
 }
 cout<<endl;
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