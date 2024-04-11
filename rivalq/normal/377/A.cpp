//https://codeforces.com/problemset/problem/377/A
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
int func(int i,int j,int m){
    return (i-1)*m+j;
}
int solve(){
 int n,m,k;cin>>n>>m>>k;
 char a[n+1][m+1];
 for(int i=0;i<=n;i++)a[i][0]='#';
 for(int i=0;i<=m;i++)a[0][i]='#';
 for(int i=1;i<=n;i++){
     for(int j=1;j<=m;j++){
         cin>>a[i][j];
     }
 }
 vector<int>g[n*m+1];
 int s=0;
 int r=0;
 for(int i=1;i<=n;i++){
     for(int j=1;j<=m;j++){
         if(a[i][j]=='#')continue;
          a[i][j]='X';s++;
          r=func(i,j,m);
         for(int k=0;k<=3;k++){
             int x=i+dirs[k][0];
             int y=j+dirs[k][1];
             if(x>n||y>m||x<1||y<1)continue;
             if(a[x][y]!='#')g[func(i,j,m)].pb(func(x,y,m));
         }
     }
 }
 queue<int> q;
 int vi[n*m+1]={0};
 int j=1;
 q.push(r);
 a[r/m+(r%m!=0)][(r-1)%m+1]='.';
 vi[r]=1;
 while(!q.empty()){
     if(j==(s-k))goto X;
     int p=q.front();
     q.pop();
     for(auto i:g[p]){
         if(vi[i]==0){
             q.push(i);
             j++;
             vi[i]=1;
             a[i/m+(i%m!=0)][(i-1)%m+1]='.';
             if(j==(s-k))goto X;
         }
     }
     
 }
 X:
 for(int i=1;i<=n;i++){
     for(int j=1;j<=m;j++)cout<<a[i][j];
     cout<<endl;
 }
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