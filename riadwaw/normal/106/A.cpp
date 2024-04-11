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
char s(char x){
    if(x=='T')
        return '9'+1;
    if(x=='J')
        return '9'+2;
    if(x=='Q')
        return '9'+3;
    if(x=='K')
        return '9'+4;
    if(x=='A')
        return '9'+5;
    return x;
}
void solve(){
    char koz, a,b,c,d;
    cin>>koz>>a>>b>>c>>d;
    if(b==koz && d!=koz){
        cout<<"YES";
        return;
    }
    if(b!=d){
        cout<<"NO";
        return;
    }
    if(s(a)>s(c)){
        cout<<"YES";
        return;
    }
    cout<<"NO";
}