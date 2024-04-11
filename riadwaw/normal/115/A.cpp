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
int level[2222];
vi g[2222];
int dfs(int v){
    int mx=0;
    for(int i=0;i<int(g[v].size());++i){
        mx=max(mx,dfs(g[v][i]));
    }
    return mx+1;
}
void solve() {
    
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin>>level[i];
        if(level[i]==-1) level[i]=0;
        g[level[i]].pb(i);
    }
    cout<<dfs(0)-1;
}