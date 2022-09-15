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
int param[111][5];
bool bad[111];
void solve(){
    int n;
    cin>>n;
    for(int i=0;i<n;++i){
        for(int j=0;j<4;++j){
            cin>>param[i][j];
        }
    }
    
    for(int i=0;i<n;++i){
        for(int j=0;j<n;++j){
            if(param[i][0]<param[j][0] && param[i][1]<param[j][1] && param[i][2]<param[j][2])
                bad[i]=true;
        }
    }
    
    int cost=0x7FFFFFFF;
    int ans=0;
    for(int i=0;i<n;++i){
        if(!bad[i]){
            if(param[i][3]<cost){
                ans=i;
                cost=param[i][3];
            }
        }
    }
        
        cout<<(ans+1);
}