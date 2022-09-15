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
li ans;
void solve(){
    string s,t;
    cin>>s>>t;
    s+='#';
    li cur[5555];
    for(int i=0;i<5555;++i){
        cur[i]=1;
    }
    for(int k=0;k<t.size();++k){
        for(int i=s.size()-1;i>=0;--i){
            if(t[k]==s[i]){
                ans+=cur[i];
                ans%= 1000000007;
                cur[i+1]+=cur[i];
                cur[i+1] %=1000000007;
            }
        }
    }
    cout<<ans;
}