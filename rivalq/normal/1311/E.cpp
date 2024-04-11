//https://codeforces.com/contest/1311/problem/E
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
int dirs[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
int solve(){
 int n,d;cin>>n>>d;
 int u=n*(n-1)/2;
 int l=0;
 if(n==2){
     l=1;
 }
 else{
     int nod=n-1;
     int i=1;
     while(nod>0){
       int k=pow(2,i);
       if(nod>=k){
           l+=i*k;
           nod-=k;
       }
       else{
           l+=nod*i;
           nod=0;
       }
       i++;
     }
 }
 //cout<<l<<endl;
 if(d>u || d<l){
     cout<<"NO"<<endl;
     ret;
 }
 int arr[n-1];
 rep3(n){
     arr[i]=i+1;
 }
 int cd=u;
 priority_queue<pii> pq;
 int dp[n+1]={0};
 for(int i=1;i<=n;i++)dp[i]=i;
 rep3(n-1){
     pq.push({-(dp[i]),i+1});
 }
 int cv=pq.top().y;
 cout<<"YES"<<endl;
 for(int i=n-2;i>=0;i--){
    int da=arr[i]-dp[cv];
    if(cd-da>=d){
        arr[i]=cv;
        dp[i+2]=dp[cv]+1;
        pq.pop();
        pq.push({-dp[i+2],i+2});
        pq.push({-dp[i+2],i+2});
        cv=pq.top().y;
        cd-=da;
        if(cd==d)break;
    }
    else{
        da=cd-d;
        arr[i]=arr[i]-da;
        break;
    }
 }
 rep3(n-1)cout<<arr[i]<<" ";cout<<endl;
 ret;
}
int main(){
    IOS;
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #ifdef cat
    cat();
    #endif
    int t=1;cin>>t;
    while(t--){
        solve();
    }
    ret;
}