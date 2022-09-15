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
int calc(const string& s){
    if(s[0] == '0' && s.length()!=1)
        return 1e6+6;
    if(s.length()> 7)
        return 1e6+6;
    int v=0;
    for(int i=0;i<(int)s.size();++i){
        v=v*10+s[i]-'0';
    }
    return v;
}
void solve(){
    string s;
    cin>>s;
    int mx=-1;
    for(int i=1;i<=7 && i<(int)s.size();++i){
        int f = calc(s.substr(0,i));
        if(f> 1e6)
            continue;
        for(int j=i+1;j<=i+7 && j<(int)s.size();++j){
            int g = calc(s.substr(i,j-i));
            int h = calc(s.substr(j));
            if(g > 1e6)
                continue;
            if(h> 1e6)
                continue;
            mx=max(mx, f+g+h);
        }
    }
    cout<<mx;
}