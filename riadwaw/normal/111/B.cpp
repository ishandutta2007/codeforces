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
    solve();
    return 0;
}
map<int,set<int> > m;
int cnt;
void add(int del,int num,int y){
    if(m[del].lower_bound(num-y)==m[del].end())
        ++cnt;
    m[del].insert(num);
}
void solve(){
    int n;
    cin>>n;
    for(int i=0;i<n;++i){
        int x,y;
        scanf(" %d %d ",&x,&y);
        cnt=0;
        for(int j=1;j*j<=x;++j){
            
            if(x%j==0){
                add(j,i,y);
                if(j*j!=x)
                    add(x/j,i,y);
            }
        }
        printf("%d\n",cnt);
    }
}