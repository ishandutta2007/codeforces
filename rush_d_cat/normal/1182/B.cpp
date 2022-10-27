#include <iostream>
#include <cstring>
#include <map>
using namespace std;
typedef long long LL;

const int N=500+10;
int n,m,tot;
char s[N][N];
void chk(int r,int c){
    int now=1;
    int x,y; 
    x=r-1,y=c; while(x>=1&&s[x][y]=='*') now++,x--;
    x=r+1,y=c; while(x<=n&&s[x][y]=='*') now++,x++;
    x=r,y=c-1; while(y>=1&&s[x][y]=='*') now++,y--;
    x=r,y=c+1; while(y<=m&&s[x][y]=='*') now++,y++;
    if(now==tot){
        printf("YES\n"); exit(0);
    }
}
int main() {
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) scanf("%s",s[i]+1);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(s[i][j]=='*') tot++;
        }
    }
    for(int i=2;i<n;i++){
        for(int j=2;j<m;j++){
            if(s[i][j]=='*'&&s[i+1][j]=='*'&&s[i-1][j]=='*'&&s[i][j-1]=='*'&&s[i][j+1]=='*') {
                chk(i,j);
            }
        }
    }
    printf("NO\n");
}