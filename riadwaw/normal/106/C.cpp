#include <stdio.h>
#include <iostream>
#include <set>
#include <map>
#include <string>
#include <queue>
#include <math.h>
#include <sstream>
#include <complex>
#include <string.h>
#include <algorithm>
using namespace std;
 
void solve(); 
#define mp make_pair
#define pb push_back
typedef int fknmain;
typedef long long int li;
/**
 CAUTION Is int really int?
 * 
 Real solution after main function
 */
//#define int li
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef double ld;
 
fknmain main(){
#ifdef DEBUG
    freopen("input", "r", stdin);
    //freopen("output","w",stdout);
    #define LL "%lld"
#else
    #define LL "%I64d"
#endif
#ifndef int
    #define INT "%d"
#else
    #define INT LL
#endif
    solve();
    return 0;
}
void solve(){
    int n,m,a[11],b[11],c[11],d[11];
    vi al;
    cin>>n>>m>>c[0]>>d[0];
    for(int i=1;i<=m;++i){
        cin>>a[i]>>b[i]>>c[i]>>d[i];
        a[i]/=b[i];
        for(int j=0;j<a[i];++j)
            al.pb(i);
    }
    
    int dp[1111];
    memset(dp,-1,sizeof(dp));
    
    dp[0]=0;
    
    for(int i=0;i<int(al.size());++i){
        for(int j=n;j>=c[al[i]];--j){
            if(dp[j-c[al[i]]]!=-1)
                dp[j]=max(dp[j-c[al[i]]]+d[al[i]],dp[j]);
        }
    }
    
    int ans=dp[0]+d[0]*(n/c[0]);
    for(int i=1;i<=n;++i){
        if(dp[i]!=-1){
            ans=max(ans,((n-i)/c[0])*d[0]+dp[i]);
        }
    }
    cout<<ans;
    
}