#include <iostream>
using namespace std;
const int N = 1000 + 10;
typedef long long LL;
LL n,m,q;
LL a[N][N],s[N][N];
char str[N];
int getType(int x) {
    // 1 is B
    //printf("x=%d\n", x);
    if (x == 0) return 0;
    int v=0,c=0;
    while(v<x) v=v<<1|1, c++;
    return (c&1) ^ getType(v-x);
}
int getType(int x, int y) {
    return getType(x) ^ getType(y);
}
LL cac(LL br,LL bc) {
    if(br<0 || bc<0) return 0;
    if((br+1)%2 == 0 || (bc+1)%2 == 0) return 1LL * (br+1) * (bc+1) / 2 * n*m;
    return 1LL * ((br+1) * (bc+1) - 1) / 2 * n * m + (getType(br,bc)==0?s[n-1][m-1]:(n*m)-s[n-1][m-1]);
}
LL f(int r,int c){
    if(r<0 || c<0) return 0;
    //printf("r=%d, c=%d\n", r,c);
    int br = r/n, bc = c/m;
    int x = r%n, y = c%m;
    //printf("br=%d, bc=%d\n", br,bc);
    LL ans = cac(br-1, bc-1);
    //cout << ans << endl;

    //printf("# (%d, %d) %d\n", br,bc,getType(br,bc));
    if(getType(br,bc) == 0) ans += s[x][y]; 
    else ans += (x+1)*(y+1)-s[x][y];

    //cout << ans << endl;
    if(br%2 == 0) ans += 1LL * br/2 * (y+1) * n;
    else ans += 1LL * (br-1)/2 * (y+1) * n + (getType(br-1,bc)==0?s[n-1][y]:n*(y+1)-s[n-1][y]);

    if(bc%2 == 0) ans += 1LL * bc/2 * (x+1) * m;
    else ans += 1LL * (bc-1)/2 * (x+1) * m + (getType(br,bc-1)==0?s[x][m-1]:m*(x+1)-s[x][m-1]);
    return ans;
}  


int main() {
    //printf("%d %d\n", getType(1), getType(2));
    scanf("%lld%lld%lld",&n,&m,&q);
    for(int i=0;i<n;i++){
        scanf("%s",str);
        for(int j=0;j<m;j++){
            a[i][j] = str[j]-'0';
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            s[i][j]=(i?s[i-1][j]:0)+(j?s[i][j-1]:0)-((i&&j)?s[i-1][j-1]:0)+a[i][j];
        }
    }
    while(q--){
        
        int x1,y1,x2,y2; scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
        x1--,y1--,x2--,y2--;
        LL ans = f(x2,y2) - f(x1-1,y2) - f(x2,y1-1) + f(x1-1,y1-1);
        
        
        //int x,y; scanf("%d%d",&x,&y); x--,y--; LL ans=f(x,y);
        
        printf("%lld\n", ans);
    }
}