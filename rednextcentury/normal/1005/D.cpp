#include <bits/stdc++.h>
#define MOD 1000000007
#define ll long long
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define REP(a,b) for (int i = a ; i < b ; i++)
using namespace std ;
int dp[200010][3] ;
int n;
string s;
int solve ( int i , int res ){
    if(i>=n) 
        return 0;
    if (dp[i][res]!=-1)
        return dp[i][res] ;
    int res1 = 0 ,res2=0 ,res3 =0;
    if ((res+s[i]-'0')%3==0){
        res1 = 1 + solve(i+1,0) ;
    }
    res3 = solve(i+1,(res+s[i]-'0')%3) ;
    res2 = solve (i+1,0) ;
    return dp[i][res%3] = max (res1,max (res3,res2)) ;
}
int main ()
{
    ios::sync_with_stdio(false) ;
     memset (dp,-1,sizeof dp) ;
     cin >> s ;
     n = s.length() ;
     cout << solve (0,0) ;
       return 0;
}