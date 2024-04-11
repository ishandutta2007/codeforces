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

fknmain main() {
#ifdef DEBUG
    freopen("input", "r", stdin);
    freopen("output","w",stdout);
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
li len(int a, int b){
    if(b<a)
        return 0;
    return b-a+1;
}
void solve() {
    int a,b,c,d,k;
    cin>>a>>b>>c>>d>>k;
    vi v[10];
    vi num;
    v[0].pb(0);
    num.pb(0);
    for(int i=0;i<9;++i){
        for(int j=0;j<int(v[i].size());++j){
            v[i+1].pb(v[i][j]*10+4);
            v[i+1].pb(v[i][j]*10+7);
            num.pb(v[i][j]*10+4);
            num.pb(v[i][j]*10+7);
        }
    }
    num.pb(1000000010);
    li good=0;
    for(int i=1;(k+i)<int(num.size());++i){ //[i..k-1+i] [i-1],[k+i] out
        int lf=num[i-1]+1,lt=num[i],rf=num[k-1+i],rt=num[k+i]-1;
        //cout<<lf<<' '<<lt<<' '<<rf<<' '<<rt<<endl;
        //[a b] is l [c d] is r
        int llf=max(lf,a), llt=min(lt,b),rrf=max(rf,c),rrt=min(rt,d);
        good+=len(llf,llt)*len(rrf,rrt);
        
        llf=max(lf,c),llt=min(lt,d),rrf=max(rf,a),rrt=min(rt,b);
        good+=len(llf,llt)*len(rrf,rrt);
        
    }
        if(k==1){
            for(int i=0;i<int(num.size());++i){
                if(num[i]>=a && num[i]<=b && num[i]>=c && num[i]<=d)
                    --good;
            }
        }
    
    li all=len(a,b)*len(c,d);
    
    printf("%.10lf",good/(ld)all);
}