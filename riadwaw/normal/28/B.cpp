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

set<int> vs,as;
vi g[111];
bool used[111];
int n,a[111],d[111];
void dfs(int v){
    as.insert(a[v]);
    vs.insert(v);
    for(int i=0;i<g[v].size();++i){
        if(!used[g[v][i]]){
            used[g[v][i]]=true;         
            dfs(g[v][i]);
        }
    }
}
void solve(){
    
    cin>>n;
    
    for(int i=0;i<n;++i){
        cin>>a[i];
        --a[i];
    }
    for(int i=0;i<n;++i){
        cin>>d[i];
    }
    
    for(int i=0;i<n;++i){
        if(i>=d[i])
            g[i].pb(i-d[i]),g[i-d[i]].pb(i);
        if(i+d[i]<n)
            g[i].pb(i+d[i]),g[i+d[i]].pb(i);
    }
    
    
    memset(used,0,sizeof(used));
    
    for(int i=0;i<n;++i){
        if(!used[i]){
            vs.clear();
            as.clear();
            dfs(i);
            bool f=true;
            while(!vs.empty()){
                if(*vs.begin()!=*as.begin()){
                    f=false;
                    break;
                }
                vs.erase(vs.begin());
                as.erase(as.begin());
            }
            if(!f){
                cout<<"NO";
                return;
            }
        }
    }
    cout<<"YES";
}