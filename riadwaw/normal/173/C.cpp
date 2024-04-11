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
int a[501][501];
int sum[501][501];
int answer[255][501][501];

void solve(){
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            cin>>a[i][j];
            answer[0][i][j] = a[i][j];
        }
    }
    for(int i=1;i<=n;++i){
        for(int j=1;j<=m;++j){
            sum[i][j] = sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1] + a[i-1][j-1];
        }
    }
    
    int mx = -1000000000;
    
    for(int k=3;k<=n && k<=m;k+=2){
        for(int i=0;i+k<=n;++i){
            for(int j=0;j+k<=m;++j){
                int ans = 0;
                if(k==3){
                    ans = sum[i+k][j+k] - sum[i][j+k] - sum[i+k][j] + sum[i][j] - a[i+1][j] - a[i+1][j+1];
                }
                else{
                    ans = sum[i+k][j+k] - sum[i][j+k] - sum[i+k][j] + sum[i][j];
                    ans -= sum[i+k-1][j+k-1] - sum[i+1][j+k-1] - sum[i+k-1][j+1] + sum[i+1][j+1];
                    ans -= a[i+1][j];
                    ans += a[i+2][j+1];
                    ans += answer[(k-4)/2][i+2][j+2];
                }
                //cout<<i<<' '<<j<<' '<<k<<' '<<ans<<endl;
                mx=max(mx,ans);
                answer[k/2][i][j] = ans;
            }
        }
    }
    cout<<mx;
}