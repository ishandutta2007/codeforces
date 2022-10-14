//https://codeforces.com/contest/628/problem/D
#include<bits/stdc++.h>
#define rep(i,a,n)     for(int i=a;i<n;i++)
#define rep3(n)        for(int i=0;i<n;i++)
#define inarr(arr,n)   rep(i,a,n)cin>>arr[i]
#define ll             long long int
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
ll dp[2010][2][2010];
int d;
int n;
int m;
int digitdp(int i,int f,string b,int rem){ 
   if(i==n){
       if(rem==0)return 1;
       else return 0;
   }
   if(i%2){
    int rem2=(d+rem*10)%m;   
    if(f==0){
       if(dp[i+1][f][rem2]==-1)return dp[i][f][rem]=digitdp(i+1,f,b,(rem*10+d)%m);
       else return dp[i][f][rem]=dp[i+1][f][rem2];
    }
    else{
        if(d>b[i]-48)return dp[i][f][rem]=0;
        else {
            int ff=(d==(b[i]-48))?1:0;
            if(dp[i+1][ff][rem2]==-1)return dp[i][f][rem]=digitdp(i+1,ff,b,(rem*10+d)%m);
            else return dp[i][f][rem]=dp[i+1][ff][rem2];
        }
    }
   } 
   else{
     dp[i][f][rem]=0;  
     for(int j=0;j<=9;j++){
         if(f==1 && j>b[i]-48)break;
         if(j==d)continue;
         int ff=0;
         if(j==b[i]-48)ff=1&f;
         int rem2=(rem*10+j)%m;
         if(dp[i+1][ff][rem2]==-1)dp[i+1][ff][rem2]=digitdp(i+1,ff,b,rem2);
         dp[i][f][rem]=(dp[i][f][rem]+dp[i+1][ff][rem2])%hell;
         //cout<<dp[i][f][rem]<<" "<<j<<endl;
     }
     return dp[i][f][rem];
    }
    
}
bool ch(string a){
    int rem=0;
    for(int i=0;i<a.length();i++){
        if(i%2){
            if(a[i]-48!=d)return false;
        }
        else{
            if(a[i]-48==d)return false;
        }
        rem=(rem*10+a[i]-48)%m;
    }
    return rem==0;
}
int solve(){
 memset(dp,-1,sizeof(dp));
 cin>>m>>d;   
 string a,b;cin>>a>>b;  
 n=a.length();         
 ll a1=digitdp(0,1,b,0)+ch(a);
 //cout<<a1<<endl;
 memset(dp,-1,sizeof(dp));
 a1-=digitdp(0,1,a,0);
 cout<<(a1+hell)%hell<<endl;          
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