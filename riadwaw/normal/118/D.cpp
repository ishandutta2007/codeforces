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
#include <stack>
using namespace std;
void solve();
typedef pair<int,int> pi;
typedef long long li;
typedef vector<int> vi;
#define mp make_pair
#define pb push_back
int main(){
#ifdef _DEBUG
    freopen("input.txt","r",stdin);
#else
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
#endif
    //cin.sync_with_stdio(false);
    //cout.sync_with_stdio(false);
    solve();
    return 0;
}
long long dp[110][110][2][15];
void solve(){
    
    memset(dp,0,sizeof(dp));
    dp[1][0][0][1]=1;
    dp[0][1][1][1]=1;
    int k[2],n[2];
    cin>>n[0]>>n[1]>>k[0]>>k[1];
    for(int s=2;s<=n[0]+n[1];++s){
        for(int i=0;i<=n[0];++i){
            int fir=i;
            int sec=s-i;
            if(sec>n[1])
                continue;
            //cout<<fir<<' '<<sec<<endl;
            if(fir){
                for(int l=1;l<=k[0];++l){   

                    dp[fir][sec][0][l]+=dp[fir-1][sec][0][l-1];
                    dp[fir][sec][0][l]%=100000000;
                }

                for(int l=1;l<15;++l){
                    dp[fir][sec][0][1]+=dp[fir-1][sec][1][l];
                    dp[fir][sec][0][1]%=100000000;
                }
            }
            
            if(sec){
                for(int l=1;l<=k[1];++l){
                    dp[fir][sec][1][l]+=dp[fir][sec-1][1][l-1];
                    dp[fir][sec][1][l]%=100000000;
                }
                for(int l=1;l<15;++l){
                    dp[fir][sec][1][1]+=dp[fir][sec-1][0][l];
                    dp[fir][sec][1][1]%=100000000;
                }
            }
        }
    }

    long long ans=0;
    for(int i=0;i<2;++i){
        for(int j=0;j<15;++j){
            ans+=dp[n[0]][n[1]][i][j];
            ans%=100000000;
        }
    }
    cout<<ans;

}