#include <iostream>
#include <cstdio>
#include <set>
#include <list>
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
    //freopen("output","w", stdout);
#endif
    //ios_base::sync_with_stdio(false);
    int t = 1;
    //cin>>t;
    while (t--)
        solve();
    return 0;
}
int n,u,r;
int t[33][33];
int b[33];
int p[33];
int k[33];
int obrp[33];
li ans = -1000000000000000000;
void go(int ost, bool alxor){
    int* a = t[ost];
    if(ost%2==0){
        li s = 0;
        for(int i=0;i<n;++i){
            s+=k[i] * (li)a[i];
        }
        ans = max(ans, s);
    }
    if(!ost)
        return;
    if(alxor){
        for(int i=0;i<n;++i){
            t[ost-1][i] = a[i] ^ b[i];
        }
        go(ost - 1, false);
    }
    
    for(int i=0;i<n;++i){
        t[ost-1][i] = a[p[i]] + r;
    }
    
    go(ost - 1, true);
    
}
void solve(){
    cin>>n>>u>>r;
    
    for(int i=0;i<n;++i){
        cin>>t[u][i];
    }
    for(int i=0;i<n;++i){
        cin>>b[i];
    }
    for(int i=0;i<n;++i){
        cin>>k[i];
    }
    for(int i=0;i<n;++i){
        cin>>p[i];
        --p[i];
        obrp[p[i]] = i;
    }
    
    go(u, true);
    cout<<ans;
}