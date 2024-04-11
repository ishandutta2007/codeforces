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

vi g[111];
bool used[111];

int k=0;
void dfs(int v){
    ++k;
    used[v]=true;
    for(int i=0;i<g[v].size();++i){
        if(!used[g[v][i]])
            dfs(g[v][i]);
    }
}


void solve(){
    int n,m;
    cin>>n>>m;
    if(m!=n){
        cout<<"NO";
        return;
    }
    for(int i=0;i<m;++i){
        int a,b;
        scanf(INT INT,&a,&b);
        g[a].pb(b);
        g[b].pb(a);
    }
    
    dfs(1);
    if(k==n)
        cout<<"FHTAGN!";
    else
        cout<<"NO";
}