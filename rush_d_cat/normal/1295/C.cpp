#include <iostream>
#include <cstring>
using namespace std;
const int N=100000+10;

int T;
char s[N],t[N];
int nex[N][27];
int main() {
    scanf("%d",&T);
    while(T--){
        scanf("%s%s",s+1,t+1);
        int n=strlen(s+1), m=strlen(t+1);
        memset(nex,0,sizeof(nex));

        for(int i=0;i<26;i++)nex[n+1][i]=n+1;
        for(int i=n;i>=1;i--){
            for(int j=0;j<26;j++)nex[i][j]=nex[i+1][j];
            nex[i][s[i]-'a']=i;
        }
        bool wandanle=0; int ans=0;
        for(int i=1,j=1;t[i];i=j){
            ++ans;
            int now=1;
            while(j<=m) {
                now=nex[now][t[j]-'a']; 
                if(now==n+1) break;
                j++; ++now;
            }
            //printf("[%d,%d)\n", i,j);
            if(i==j) {
                wandanle=1; break;
            }
        }
        if(wandanle) printf("-1\n"); else printf("%d\n", ans);
    }
}
/*
1
ty
yyt
*/