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
    li n,k,p;
    cin>>n>>k>>p;
    li nz=n-k;
    for(int i=0;i<p;++i){
        li q;
        cin>>q;
        bool f=false;
        if(k==0){
        }
        else if(nz==0){
            f=true;
        }
        else if(k>=nz){
            //(.X)+X+
            if((q % 2 == 0) || q>=2*nz)
                f=true;
        }
        else if(n % 2 ==0){
            //.(.X)+
            if(n % 2 == q % 2)
                if( (n-q)/2 < k )
                    f=true;
        }
        else{
            //.+(.X)+(.XX)
            if(n==q)
                f=true;
            if((n-1) % 2 == q % 2)
                if( (n-1-q)/2 < (k-1) )
                    f=true;
        }
        if(f)
            cout<<"X";
        else
            cout<<".";
    }
        
    
}