#include <iostream>
#include <cstdio>
#include <set>
#include <vector>
#include <map>
#include <string>
#include <cstring>
#include <cmath>
#include <memory.h>
#include <algorithm>
#include <cstdlib>
#include <cassert>
#include <sstream>
using namespace std;
void solve();

#define pb push_back
#define mp make_pair

typedef long long li;
typedef vector<li> vi;
typedef pair<int, int> pi;

int main() {
#ifdef DEBUG
    freopen("input", "r", stdin);
    //freopen("output","w",stdout);
#endif
    ios_base::sync_with_stdio(false);
    int t = 1;
    //cin>>t;
    while (t--)
        solve();
    return 0;
}
void solve(){
    long long a = 0,b =0 ;
    int n;
    string s,t;
    cin>>n>>s>>t;
    int st =(s.size()*t.size());
    for(int i=0;i<st;++i){
        char u = s[i%s.size()];
        char v = t[i%t.size()];
        if(u=='R' && v=='S')
            ++a;
        if(u=='S' && v=='P')
            ++a;
        if(u=='P' && v=='R')
            ++a;
        
        if(v=='R' && u=='S')
            ++b;
        if(v=='S' && u=='P')
            ++b;
        if(v=='P' && u=='R')
            ++b;
    }
    a*=n/st;
    b*=n/st;
    
    for(int i=n/st*st;i<n;++i){
        char u = s[i%s.size()];
        char v = t[i%t.size()];
        
        if(u=='R' && v=='S')
            ++a;
        if(u=='S' && v=='P')
            ++a;
        if(u=='P' && v=='R')
            ++a;
        
        if(v=='R' && u=='S')
            ++b;
        if(v=='S' && u=='P')
            ++b;
        if(v=='P' && u=='R')
            ++b;
    }
    cout<<b<<' '<<a<<endl;
}