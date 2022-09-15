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
    int n;
    pi a[101010];
    cin>>n;
    for(int i=0;i<n;++i){
        scanf(INT,&a[i].first);
        a[i].second=i;
    }
    sort(a,a+n);
    int ans[101010];
    int mx=-1;
    for(int i=0;i<n;){
        int j=0;
        int oldmax=mx;
        for(j=i;j<n && a[j].first==a[i].first;++j){
            ans[a[j].second]=oldmax;
            mx=max(mx,a[j].second);
            //cout<<i<<' '<<a[i].first<<' '<<a[i].second<<' '<<oldmax<<' '<<mx<<endl;
        }
        i=j;
    }
    
    for(int i=0;i<n;++i){
        if(ans[i]<=i)
            ans[i]=-1;
        else
            ans[i]-=i+1;
        printf(INT" ",ans[i]);
    }
    
}