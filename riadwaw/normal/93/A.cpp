//#define _GLIBCXX_DEBUG
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
 */
//#define int li
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef double ld;
 
fknmain main(){
#ifdef DEBUG
    freopen("input", "r", stdin);
    //freopen("output","w",stdout);
    #define INT "%lld"
#else
    #define INT "%I64d"
#endif
#ifndef int
    #undef INT
    #define INT "%d"
#endif
    solve();
    return 0;
}
void solve(){
    int n,m,a,b;
    cin>>n>>m>>a>>b;
    --a,--b;
    if(a/m==b/m){
        cout<<1;
        return;
    }
    else if(a%m==0){
        if(b==n-1 || (b+1)%m==0){
            cout<<1;
            return;
        }
        else{
            cout<<2;
            return;
        }
    }
    if((b+1)%m==0){
        cout<<2;
        return;
    }
    if(b==n-1){
        cout<<2;
        return;
    }
    if(a%m == (b+1)%m){
        cout<<2;
        return;
    }
    if((b/m-a/m)==1){
        cout<<2;
        return;
    }
    cout<<3;
}