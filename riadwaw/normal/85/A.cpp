#include <stdio.h>
#include <iostream>
#include <set>
#include <map>
#include <string>
#include <string.h>
#include <queue>
#include <algorithm>
#include <math.h>
#include <sstream>
#include <complex>
using namespace std;

void solve();
#define mp make_pair
#define pb push_back
int main(){
#ifdef DEBUG
    freopen("input", "r", stdin);
    //freopen("output","w",stdout);
#endif
    solve();
    return 0;
}
typedef long long int li;
#define int li
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef double ld;

void solve(){
    int n;
    cin>>n;
    for(int i=0;i<n/2;++i){
        if(i%2)
            cout<<"aa";
        else
            cout<<"cc";
    }
    if(n%2){
        cout<<"x";
    }
    cout<<'\n';
    for(int i=0;i<n/2;++i){
        if(i%2)
            cout<<"bb";
        else
            cout<<"dd";
    }
    if(n%2){
        cout<<"x";
    }
    --n;
    
    
    
    cout<<endl;
    cout<<"y";
    for(int i=0;i<n/2;++i){
        if(i%2)
            cout<<"qq";
        else
            cout<<"ww";
    }
    if(n%2){
        cout<<"p";
    }
    cout<<endl;
    
    cout<<"y";
    
    for(int i=0;i<n/2;++i){
        if(i%2)
            cout<<"zz";
        else
            cout<<"tt";
    }
    if(n%2){
        cout<<"p";
    }
}