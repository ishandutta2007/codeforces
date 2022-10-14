//https://codeforces.com/contest/1291/problem/A
#include<bits/stdc++.h>
#define rep1(i,n,a)    for(int i=0;i<n;i+=a)
#define rep2(i,n,a)    for(int i=a;i<n;i++)
#define rep3(n)        for(int i=0;i<n;i++)
#define inarr(arr,n)   rep1(i,n,1)cin>>arr[i]
#define ll             long long int
#define pb             push_back
#define all(v)         v.begin(),v.end()
#define trav(a,x)      for(auto x:a)
#define endl           "\n"
#define eb             emplace_back
#define fr             first
#define sc             second
#define gcd(a,b)       __gcd(a,b)
#define pres(a,x)      a.find(x)!=a.end()
#define sz(a)         (int)a.size()
#define pii            pair<int,int>
#define psi            pair<string,int>
#define pss            pair<string,string>
#define pll            pair<ll,ll>
#define vec            vector<int>
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
// syntax for min priority_queue of pairs
// priority_queue<pair<ll,ll>,vector<pair<ll,int>>,greater<pair<ll,int>>> q;
int solve(){
 int n;cin>>n;
 string s;cin>>s;
 int o=0,e=0;
 int cnt=0;
 string ss="";
 for(int i=0;i<n;i++){
     cnt+=(s[i]-48);
     o=o+(s[i]-48)%2;
     e=e+((s[i]-48)%2==0);
     if(s[i]!=48)ss+=s[i];
 }
 s=ss;
 n=ss.length();
 if((s.back()-48)%2==0){
     if(cnt%2){
         if(o>1){
             while(s.size()!=0){
                 if((s.back()-48)%2==0)s.pop_back();
                 else break;
             }
             int n=s.length();
             string t="";
             int f=0;
             for(int i=0;i<n-1;i++){
                if(f==0 && (s[i]-48)%2){
                    f=1;
                    continue;
                }
                else{
                    t+=s[i];
                }
             }
             t+=s[n-1];
             cout<<t<<endl;  
         }
         else{
             cout<<-1<<endl;
         }
     }
     if(cnt%2==0){
         if(o>0){
             while(s.size()!=0){
                 if((s.back()-48)%2==0)s.pop_back();
                 else break;
             }
             cout<<s<<endl;
         }
         else{
             cout<<-1<<endl;
         }
     }
 }
 else{
     if(cnt%2==0){
         cout<<s<<endl;
     }
     else{
         if(o>1){
           string t="";
             int f=0;
             for(int i=0;i<n-1;i++){
                if(f==0 && (s[i]-48)%2){
                    f=1;
                    continue;
                }
                else{
                    t+=s[i];
                }
             }
             t+=s[n-1];
             cout<<t<<endl; 
         }
         else{
             cout<<-1<<endl;
         }
     }
 }   
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