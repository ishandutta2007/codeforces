//https://codeforces.com/contest/1333/problem/0
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
#define elasped_time 1.0 * clock() / CLOCKS_PER_SEC
const int inf1=1e9;
const ll inf2=1e18;
const int N=100000;
using namespace std;
int dirs[4][2] ={{1,0},{-1,0},{0,1},{0,-1}};
int solve(){
  int n,m;cin>>n>>m;          
  char a[n][m];
   for(int i=0;i<n;i++){
          char c1=(i%2==0)?'B':'W';
          int z='B'+'W'-c1;
          char c2=z;
          for(int j=0;j<m;j++){
              if(j%2==0)a[i][j]=c1;
              else a[i][j]=c2;
          }
   }          
   if(n%2==0 || m%2==0){
       if(n%2==0)a[n-1][0]='B';
       else a[n-1][m-1]='B';
   }
   for(int i=0;i<n;i++){
       for(int j=0;j<m;j++)cout<<a[i][j];cout<<endl;
   }
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