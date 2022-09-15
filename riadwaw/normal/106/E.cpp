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
int n;
int xx[111],yy[111],zz[111];
inline ld sqr(ld a){
    return a*a;
}
ld ax,ay,az;

inline ld t(ld  x, ld y){
    ld lz=-10000,rz=10000;
    for(int i=0;i<40;++i){
        ld lcz=lz+15*(rz-lz)/32;
        ld rcz=lz+17*(rz-lz)/32;
        
        ld alcz=0,arcz=0;
        for(int i=0;i<n;++i){
            alcz=max(sqrt(sqr(xx[i]-x)+sqr(yy[i]-y)+sqr(zz[i]-lcz)),alcz);
            arcz=max(sqrt(sqr(xx[i]-x)+sqr(yy[i]-y)+sqr(zz[i]-rcz)),arcz);
        }
        
        if(alcz>arcz){
            lz=lcz;
        }
        else 
            rz=rcz;
    }
    az=(lz+rz)/2;
    
    ld aaz=0;
    for(int i=0;i<n;++i){
        aaz=max(sqrt(sqr(xx[i]-x)+sqr(yy[i]-y)+sqr(zz[i]-az)),aaz);
    }
    
    return aaz;
}

inline ld t(ld x){
    ld l=-10000,r=10000;
    for(int i=0;i<40;++i){
        ld lc=l+15*(r-l)/32;
        ld rc=l+17*(r-l)/32;
        if(t(x,lc)>t(x,rc)){
            l=lc;
        }
        else 
            r=rc;
    }
    ay=(l+r)/2;
    return t(x,(l+r)/2);
}

inline ld t(){
    ld l=-10000,r=10000;
    for(int i=0;i<40;++i){
        ld lc=l+15*(r-l)/32;
        ld rc=l+17*(r-l)/32;
        if(t(lc)>t(rc)){
            l=lc;
        }
        else 
            r=rc;
    }
    ax=(l+r)/2;
    return t((l+r)/2);
}
void solve(){
    
    scanf(INT,&n);
    for(int i=0;i<n;++i){
        scanf(INT INT INT,xx+i,yy+i,zz+i);
    }
    t();
    
    printf("%.10lf %.10lf %.10lf",ax,ay,az);
    
}