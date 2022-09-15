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
#define int li
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
    int n,m,k,a[10101];
    cin>>n>>m>>k;
    for(int i=0;i<n;++i){
        scanf(INT,a+i);
    }
    if(n%2==0){
        cout<<0;
        return;
    }
    int ans=k*(m/(n/2+1));
    for(int i=0;i<n;i+=2){
        ans=min(ans,a[i]);
    }
    cout<<ans;
    
}