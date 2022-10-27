#include <iostream>
using namespace std;
const int N = 2000 + 10;
int n,m;
char s[N][N];
int main() {
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) {
        scanf("%s",s[i]+1);
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(s[i][j]=='B') {
                int u=0,d=0,l=0,r=0;
                for(int k=n;k>=1;k--) {
                    if(s[k][j]=='B') u=k;
                }
                for(int k=1;k<=n;k++) {
                    if(s[k][j]=='B') d=k;
                }
                for(int k=m;k>=1;k--) {
                    if(s[i][k]=='B') l=k;
                }
                for(int k=1;k<=m;k++) {
                    if(s[i][k]=='B') r=k;
                }
                if(u==0||d==0||l==0||r==0) continue;
                if(l+r==2*j && u+d==2*i) {
                    printf("%d %d\n", i, j); return 0;
                }
            }
        }
    }
}