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
#define pis            pair<int,string>
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
bool isubstr(string s1,string s2){
    if(s2.size()<s1.size())return false;
    int n1 = s1.length(); 
    int n2 = s2.length();
    for (int i = 0;i<=n2-n1;i++) { 
        int j=0; 
        for (j;j<n1;j++){
         if(s2[i+j]!=s1[j])break; 
        }
        if (j==n1) 
            return true; 
    } 
  
    return false; 
}
int solve(){
 int n;cin>>n;
 string arr[n];
 inarr(arr,n);
 vector<pis> v;
 rep3(n)v.eb(arr[i].length(),arr[i]);
 sort(all(v));
 for(int i=0;i<n-1;i++){
     if(!isubstr(v[i].sc,v[i+1].sc)){
         cout<<"NO"<<endl;
         ret;
     }
 }
 cout<<"YES"<<endl;
 rep3(n)cout<<v[i].sc<<endl;
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