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
    int n,w,m;
    cin>>n>>w>>m;
    map<int,int> x;
    ld fool=n*w*1.0/m;
    ld ost=w;
    int cur=1;
    for(int i=0;i<m;++i){
        ld need=fool;
        while(need>1e-10){
            if(ost<=need){
                //printf("%d %.10lf ",cur,ost);
                if(++x[cur]>2){
                    cout<<"NO";
                    return;
                }
                ++cur;
                need-=ost;
                if(need<1e-10){
                    need=0;
                }
                ost=w;
            }
            else{
                //printf("%d %.10lf\n",cur,need);
                if(++x[cur]>2){
                    cout<<"NO";
                    return;
                }
                ost-=need;
                if(ost<1e-10){
                    ost=w;
                    ++cur;
                }
                need=0;
            }
        }
    }
    ost=w;
    cur=1;
    
    
    
    
    cout<<"YES\n";
    for(int i=0;i<m;++i){
        ld need=fool;
        while(need>1e-10){
            if(ost+1e-10<need){
                printf("%d %.10lf ",cur,ost);
                ++cur;
                need-=ost;
                ost=w;
            }
            else{
                printf("%d %.10lf\n",cur,need);
                ost-=need;
                if(ost<1e-10){
                    ost=w;
                    ++cur;
                }
                need=0;
            }
        }
    }
}