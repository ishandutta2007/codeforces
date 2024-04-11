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
typedef vector<int> vi;
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
li ans(li n){
    if(n < 10)
        return n;
    
    
    vector<int> d;
    li k= n;
    while(k){
        d.pb(k%10);
        k/=10;
    }
    
    li t = (n - 9)/10;
    
    li anss = t + 9;
    
    li last = t * 10 + 9;
    for(li i = last + 1;i<=n;++i){
        if(i%10==d.back())
            ++anss;
    }
    
    return anss;
    
}
void solve(){
    li l,r;
    cin>>l>>r;
    cout<<ans(r)-ans(l-1)<<endl;
}