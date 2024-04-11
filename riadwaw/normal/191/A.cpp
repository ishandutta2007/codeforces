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
    //freopen("output","w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    int t = 1;
    //cin>>t;
    while (t--)
        solve();
    return 0;
}
void solve(){
    string s[500000];
    int n;
    int v[26][26];
    memset(v, -1,sizeof(v));
    for(int i=0;i<26;++i){
        v[i][i] = 0;
        
    }
    cin>>n;
    for(int i=0;i<n;++i){
        cin>>s[i];
        for(int from=0;from<26;++from){
            if(v[from][s[i][0] - 'a']!=-1)
                v[from][s[i].back() - 'a'] = max((int)v[from][s[i].back() - 'a'], (int)(v[from][s[i][0] - 'a'] + s[i].length()));
        }
    }
    int ans=0;
    for(int i=0;i<26;++i){
        ans= max(ans, v[i][i]);
    }
    cout<<ans;
}