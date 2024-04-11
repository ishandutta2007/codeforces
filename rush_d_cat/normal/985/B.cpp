#include <iostream>
using namespace std;
int n,m,c[2002];
char s[2002][2002];
int main() {
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) scanf("%s",s[i]+1);
    for(int i=1;i<=n;i++)for(int j=1;j<=m;j++) if(s[i][j]=='1') c[j]++;

    for(int i=1;i<=n;i++) {
        bool ac = 1;
        for(int j=1;j<=m;j++) {
            if(s[i][j]=='1') c[j]--;
            if(c[j]==0) ac=0;
        }
        for(int j=1;j<=m;j++) {
            if(s[i][j]=='1') c[j]++;
        }
        if (ac) return !printf("YES\n");
    } 
    printf("NO\n");

}