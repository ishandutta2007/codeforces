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

void solve(){
    int n,m;
    double k;
    map<string,int> pers;
    cin>>n>>m>>k;
    for(int i=0;i<n;++i){
        string s;
        int v;
        cin>>s>>v;
        int newv=(k*v)+(1e-6);
        if(newv>=100)
            pers[s]=newv;
    }
    for(int i=0;i<m;++i){
        string s;
        cin>>s;
        pers[s]+=0;
    }
    cout<<pers.size()<<endl;
    for(map<string,int>::iterator it=pers.begin();it!=pers.end();++it){
        cout<<it->first<<' '<<it->second<<endl;
    }
}