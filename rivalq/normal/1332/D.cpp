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
int dp[5][5]={0};
int ch(int arr[][4]){
    dp[0][1]=arr[0][0];
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            dp[i+1][j+1]=max(dp[i][j+1]&arr[i][j],dp[i+1][j]&arr[i][j]);
        }
    }
    return dp[4][3];
}
int solve(){
 int k;cin>>k; 
 int attack=1<<17;
 int attack2=1<<17|k;          
 int arr[4][4]={{attack2,k,k,0},
                {attack,0,k,0},
                {attack,0,k,0},
                {attack,attack,attack2,k}}; 
 cout<<4<<" "<<4<<endl;               
 rep3(4){
     rep(j,0,4)cout<<arr[i][j]<<" ";cout<<endl;
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
    int t=1;//cin>>t;
    while(t--){
        solve();
    }
    ret;
}