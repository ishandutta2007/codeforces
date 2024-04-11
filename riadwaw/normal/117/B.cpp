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
    //freopen("output", "w", stdout);
#define LL "%lld"
#else
#define LL "%I64d"
#endif
#ifndef int
#define INT "%d"
#else
#define INT LL
#endif
    //cin.sync_with_stdio(false);
    //cout.sync_with_stdio(false);
    solve();
    return 0;
}
bool can[10101010];
void solve() {
    int a,b,mod;
    cin>>a>>b>>mod;
    
    li cur=0;
    for(int i=0;i<=a;++i){
        if(can[cur])
            break;
        can[cur]=true;
        if(cur!=0 && cur+b<mod){
            printf("1 %09d",i);
            return;
        }
        cur+=1000000000;
        cur%=mod;
    }
    printf("2");

}