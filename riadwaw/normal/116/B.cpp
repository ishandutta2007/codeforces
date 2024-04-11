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

using namespace std;
void solve();

#define mp make_pair
#define pb push_back

typedef long long li;
typedef vector<int> vi;
typedef pair<int, int> pi;

int main() {
#ifdef DEBUG
    freopen("input", "r", stdin);
    //freopen("output","w",stdout);
#else
#endif
    //cin.sync_with_stdio(false);
    //cout.sync_with_stdio(false);
    solve();
    return 0;
}
char s[100][100];
void solve(){
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;++i)
        cin>>(s[i+1]+1);
    int c=0;
    for(int i=1;i<=n;++i)
        for(int j=1;j<=m;++j){
            if(s[i][j]=='W' && (s[i][j-1]=='P' || s[i+1][j]=='P' || s[i-1][j]=='P' || s[i][j+1]=='P' ))
                ++c;
        }
    cout<<c;
}