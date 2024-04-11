//https://codeforces.com/contest/1312/problem/E
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
#define mem1(a)        memset(a,-1,sizeof(a));
const int inf1=1e9;
const ll inf2=1e18;
const int N=100000;
using namespace std;
int dirs[4][2] ={{1,0},{-1,0},{0,1},{0,-1}};
int dp2[501],dp1[501][501];
int arr[1000];
int n;
// function to check if i...j can be replaced by 1 element 
int cbrute1(int i,int j){
    if(i==j)return arr[i];
    if(dp1[i][j]!=-1)return dp1[i][j];
    for(int k=i;k<j;k++){
        int x1=cbrute1(i,k);
        int x2=cbrute1(k+1,j);
        if(x1==x2 && x1!=0){
            dp1[i][j]=x1+1;
            return dp1[i][j];
        }
    }
    return dp1[i][j]=0;                        // 0 --> means failure;
}
// function calc minimum length array starting 0...i-1;
int cbrute(int i=n){
    if(i==0 || i==1) return i;
    if(dp2[i]!=-1)return dp2[i];
    dp2[i]=i;
    for(int j=0;j<i;j++){
        if(cbrute1(j,i-1)!=0){
            dp2[i]=min(dp2[i],1+cbrute(j));
        }
    }
    return dp2[i];
}
int solve(){
 mem1(dp1);
 mem1(dp2);  
 cin>>n;
 rep3(n)cin>>arr[i]; 
 cout<<cbrute()<<endl;       
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