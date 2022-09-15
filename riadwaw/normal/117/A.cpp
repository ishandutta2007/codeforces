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
    cin.sync_with_stdio(false);
    cout.sync_with_stdio(false);
    solve();
    return 0;
}
void solve() {
    int n,m;
    cin>>n>>m;

    for(int i=0;i<n;++i){
        int s,f,t;
        cin>>s>>f>>t;
        if(s==f)
            cout<<t<<endl;
        else if(f>s){
            int mod=t%(2*m-2);
            int eh=f-s;
            if(mod>s-1){
                s+=2*m-2;
            }
            t+=s-1+eh-mod;
            cout<<t<<endl;
        }
        else{
            int mod=t%(2*m-2);
            int eh=s-f;

            if(mod>2*m-1-s){
                t+=2*m-2;
            }
            t+=2*m-1-s+eh-mod;
            cout<<t<<endl;
        }
    }
}