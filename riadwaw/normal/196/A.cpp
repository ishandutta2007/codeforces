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
void solve(){
    string s;
    cin>>s;
    string ans;
    vector<int> v[256];
    int lastpos = -1;
    for(int i=0;i<int(s.length());++i){
        v[(int)s[i]].pb(i);
    }
    
    for(char c ='z';c>='a';--c){
        for(size_t i=0;i<v[(int)c].size();++i){
            if(v[(int)c][i]>lastpos){
                lastpos = v[(int)c][i];
                ans+=c;
            }
        }
    }
    cout<<ans;
}