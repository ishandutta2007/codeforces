#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long LL;
const int N = 200000+10;
char s[N];
int vis[5][5];
void xiao(){
    int r[5]={0},c[5]={0};
    for(int i=1;i<=4;i++){
        for(int j=1;j<=4;j++) 
            r[i] += vis[i][j], c[j] += vis[i][j];
    }
    for(int i=1;i<=4;i++){
        for(int j=1;j<=4;j++){
            if(r[i]==4||c[j]==4) vis[i][j]=0;
        }
    }
}
int main(){
    scanf("%s",s);
    for(int i=0;s[i];i++){
        if(s[i]=='0') {
            bool fg=0;
            for(int x=3;x<=4;x++){
                for(int y=1;y<=4;y++){
                    if(vis[x][y]==0 && vis[x+1][y]==0) {
                        vis[x][y]=1, vis[x+1][y]=1;
                        fg=1; xiao();
                        printf("%d %d\n", x, y); 
                        break;
                    }
                }
                if(fg) break;
            }
        } else {
            bool fg=0;
            for(int x=1;x<=2;x++){
                for(int y=1;y<=3;y++){
                    if(vis[x][y]==0 && vis[x][y+1]==0){
                        vis[x][y]=1, vis[x][y+1]=1;
                        fg=1; xiao();
                        printf("%d %d\n", x, y); 
                        break;
                    }
                }
                if(fg) break;
            }
        }
    }
}