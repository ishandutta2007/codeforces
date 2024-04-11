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
int a[111][111];
int b[111][111];
int c[111][111];

void solve() {
    int n,m,ko;
    cin>>n>>m>>ko;
    li ans = 0;
    for(int i=0;i<n;++i){
        string s;
        cin>>s;
        for(int j=0;j<m;++j){
            cin>>a[i][j]>>b[i][j]>>c[i][j];
        }
    }
    
    for(int i=0;i<n;++i){
        for(int j=0;j<n;++j){
            if(i==j)
                continue;
            vector<pi> ok;
            for(int k=0;k<m;++k){
                if(b[j][k]>a[i][k]){
                    ok.pb(mp(b[j][k] - a[i][k],c[i][k]));
                }
            }
            sort(ok.begin(),ok.end());
            reverse(ok.begin(),ok.end());
            int ost = ko;
            li curans = 0;
            for(int t=0;t<(int)ok.size() && ost;++t){
                if(ok[t].second>ost)
                    ok[t].second = ost;
                
                curans += ok[t].first * ok[t].second;
                ost -= ok[t].second;
            }
            
            ans = max(ans, curans);
        }
    }
    cout<<ans;
}