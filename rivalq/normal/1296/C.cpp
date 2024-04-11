//https://codeforces.com/contest/1296/problem/C
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
bool ch(string s,int k){
    int c1=0,c2=0;
    for(int i=0;i<k;i++){
        if(s[i]=='L')c1++;
        else if(s[i]=='R')c1--;
        else if(s[i]=='U')c2++;
        else c2--;
    }
    if(c1==0&&c2==0){
        return 1;
    }
    for(int i=k;s[i]!='\0';i++){
        if(s[i]=='L')c1++;
        else if(s[i]=='R')c1--;
        else if(s[i]=='U')c2++;
        else c2--;
        if(s[i-k]=='L')c1--;
        else if(s[i-k]=='R')c1++;
        else if(s[i-k]=='U')c2--;
        else c2++;
        if(c1==c2 && c1==0)return 1;
    }
    return 0;
}
int solve(){
 int n;cin>>n;
 string s;cin>>s;
 pii p[n+1];
 int c1=0,c2=0;
 p[0].fr=0;
 p[1].sc=0;
 for(int i=0;i<n;i++){
        if(s[i]=='L')c1++;
        else if(s[i]=='R')c1--;
        else if(s[i]=='U')c2++;
        else c2--;
        p[i+1].fr=c1;
        p[i+1].sc=c2;
 }
 map<pii,int>mp;
 int mi=hell;
 int l=0,r=0;
 for(int i=0;i<=n;i++){
     if(pres(mp,p[i])){
       if(mi>(i-mp[p[i]])){
           l=mp[p[i]];
           r=i;
           mi=r-l;
       }
       mp[p[i]]=i;
     }
     else{
         mp[p[i]]=i;
     }
 }
 if(mi==hell){
     cout<<-1<<endl;
 }
 else{
     cout<<l+1<<" "<<r<<endl;
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