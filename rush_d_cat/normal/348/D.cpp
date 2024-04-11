#include <iostream>
#include <cstring>
using namespace std;
typedef long long LL;
const LL MOD=1e9+7;
const int N=3002;
int n,m,ways[N][N];
char s[N][N];

void cac(int x,int y){
    memset(ways,0,sizeof(ways));
    ways[x][y]=1;
    for(int i=x;i<=n;i++){
        for(int j=y;j<=m;j++){
            if(s[i][j]=='.'){
                if(s[i+1][j]=='.') (ways[i+1][j]+=ways[i][j])%=MOD;
                if(s[i][j+1]=='.') (ways[i][j+1]+=ways[i][j])%=MOD;
            }
        }
    }
}
int main() {
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)scanf("%s",s[i]+1);
    if(s[2][1]=='#'||s[1][2]=='#'||s[n-1][m]=='#'||s[n][m-1]=='#')return !printf("0\n");
    cac(1,2); LL a11=ways[n-1][m], a12=ways[n][m-1];
    cac(2,1); LL b11=ways[n-1][m], b12=ways[n][m-1];
    LL det=a11*b12-a12*b11;
    det=(det%MOD+MOD)%MOD;
    //printf("%lld %lld %lld %lld\n", a11,a12,b11,b12);
    cout<<det<<endl;
}