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
    vector<int> v[26];
    //memset(have,0,sizeof(have));
    char need[1101010],have[10101];
    scanf("%s\n%s",have,need);
    for(int i=0;have[i];++i){
        v[have[i]-'a'].push_back(i);
    }
    int k=0,mesto=100000;
    for(int i=0;need[i];++i){
        int c=need[i]-'a';
        if(v[c].empty()){
            cout<<-1;
            return;
        }
        else{
            vector<int>::iterator it=upper_bound(v[c].begin(),v[c].end(),mesto);
            if(it==v[c].end()){
                ++k;
                mesto=v[c][0];
            }
            else{
                mesto=*it;
            }
        }
    }
    cout<<k;
    
}