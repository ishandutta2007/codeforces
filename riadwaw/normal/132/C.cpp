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
    cin.sync_with_stdio(false);
    //cout.sync_with_stdio(false);
    solve();
    return 0;
}
int dpl[111][111][2],dpr[111][111][2];
void solve(){
    string s;
    int n;
    cin>>s>>n;
    memset(dpr,-100,sizeof(dpr));
    memset(dpl,-100,sizeof(dpl));
    dpr[0][0][0]=0;
    dpr[0][0][1]=0;
    for(int i=1;i<=s.length();++i){
        for(int j=0;j<=n;++j){
            if(s[i-1]=='F'){
                dpr[i][j][0]=max(dpr[i-1][j][0]+1,dpr[i][j][0]);
                dpr[i][j][1]=max(dpr[i-1][j][1]-1,dpr[i][j][1]);
                if(j){
                    dpr[i][j][0]=max(dpr[i][j][0],dpr[i-1][j-1][1]);
                    dpr[i][j][1]=max(dpr[i][j][1],dpr[i-1][j-1][0]);
                }
            }
            else{
                if(j){
                    dpr[i][j][0]=max(dpr[i-1][j-1][0]+1,dpr[i][j][0]);
                    dpr[i][j][1]=max(dpr[i-1][j-1][1]-1,dpr[i][j][1]);
                }
                if(j>-1){
                    dpr[i][j][0]=max(dpr[i][j][0],dpr[i-1][j][1]);
                    dpr[i][j][1]=max(dpr[i][j][1],dpr[i-1][j][0]);
                }
            }
            if(j>=2){
                dpr[i][j][0]=max(dpr[i][j][0],dpr[i][j-2][0]);
                dpr[i][j][1]=max(dpr[i][j][1],dpr[i][j-2][1]);
            }

            //cout<<i<<j<<' '<<dpr[i][j][0]<<' '<<dpr[i][j][1]<<endl;
        }
    }
    cout<<max(dpr[s.length()][n][0],dpr[s.length()][n][1]);
}