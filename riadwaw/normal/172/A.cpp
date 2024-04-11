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
    int n;
    string s;
    string mx="";
    string mn="\127";
    cin>>n;
    for(int i=0;i<n;++i){
        cin>>s;
        mx=max(mx,s);
        mn=min(mn,s);
    }
    int ans=0;
    for(int i=0;i<(int)s.size();++i){
        if(mx[i]==mn[i])
            ++ans;
        else
            break;
    }
    cout<<ans;
    
}