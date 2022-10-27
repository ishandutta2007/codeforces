#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
typedef long long LL;
const int N = 200000 + 10;
int m,n;
int vis[52][10002];
int main() {
    scanf("%d%d",&m,&n);
    for(int i=1;i<=m;i++){
        int x; scanf("%d",&x);
        while(x--){
            int y; scanf("%d",&y);
            vis[i][y]=1;
        }
    }
    //printf("ok\n");
    int res=1;
    for(int i=1;i<=m;i++){
        for(int j=i+1;j<=m;j++){
            bool ok=0;
            for(int k=1;k<=n;k++){
                if(vis[i][k]&&vis[j][k]) ok=1;
            }
            if(ok==0)res=0;
        }
    }
    printf("%s\n", res?"possible":"impossible");
}
/*
1 2
2 3
*/