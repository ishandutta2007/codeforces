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
double dp[222][222][422];
void solve(){
    int n,l,t;
    cin>>n>>l>>t;
    int p[202],x[202];
    for(int i=0;i<n;++i){
        cin>>p[i];
    }
    for(int i=0;i<n;++i){
        cin>>x[i];
    }
    
    dp[0][0][200] = 1;
    for(int i=0;i<n;++i)
        for(int j=0;j<n;++j){
            for(int k=0;k<422;++k){
                dp[i+1][j+1][min(421, k+x[i])] += dp[i][j][k] * p[i] / 100;
                dp[i+1][j][k] += dp[i][j][k] * (100-p[i])/100;
            }
        }
    double ans = 0;
    for(int j=l;j<=n;++j){
        for(int k=200-t; k<422; ++k){
            ans+=dp[n][j][k];
        }
    }
    printf("%.10lf", ans);
}