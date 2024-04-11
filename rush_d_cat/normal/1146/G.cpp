#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
const int N=52;
int n,h,m;
struct Item {
    int l,r,x,c;
    void read(){
        scanf("%d%d%d%d",&l,&r,&x,&c);
    }
} it[N];
int dp[N][N][N],fine[N][N][N][N];
int cac(int l,int r,int h) {
    if(dp[l][r][h]!=-1) return dp[l][r][h];
    if(l>r) return dp[l][r][h]=0;
    dp[l][r][h]=0;
    for(int f=l;f<=r;f++)
    for(int i=0;i<=h;i++) {
        dp[l][r][h] = max(cac(l,f-1,i)+cac(f+1,r,i)+i*i-fine[l][r][f][i], dp[l][r][h]);
    }
    return dp[l][r][h];
} 
int main() {
    memset(dp,-1,sizeof(dp));
    scanf("%d%d%d",&n,&h,&m);
    for(int i=1;i<=m;i++) it[i].read();

    for(int l=1;l<=n;l++)
    for(int r=1;r<=n;r++){
        for(int f=1;f<=r;f++){
            for(int j=1;j<=m;j++){
                for(int i=0;i<=h;i++){
                    if(it[j].l<=f && f<=it[j].r && it[j].r<=r && it[j].l>=l && it[j].x<i) fine[l][r][f][i] += it[j].c; 
                }
            }
        }
    }


    //cout << "#" << fine[3][3][3][0] << endl;
    cout<<cac(1,n,h)<<endl;
}