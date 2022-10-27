#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
const int N = 1000 + 10;
char s[N][N]; int n,m;
bool vis[N][N];
void upd(int x,int y) {
    bool ok=1;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(i==1&&j==1)continue;
            if(s[x+i][y+j]!='#') ok=0;
        }
    }
    if(ok) {
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                if(i==1&&j==1)continue;
                vis[x+i][y+j]=1;
            }
        }        
    }
}
int main() {
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) {
        scanf("%s",s[i]+1);
    }
    for(int i=1;i<=n-2;i++){
        for(int j=1;j<=m-2;j++) upd(i,j);
    }
    bool ok=1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(s[i][j]=='#'&&vis[i][j]==0) ok=0;
            if(s[i][j]=='.'&&vis[i][j]==1) ok=0;
        }
    }
    printf("%s\n", ok?"YES":"NO");
}