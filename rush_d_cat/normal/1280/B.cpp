#include <iostream>
#include <cstring>
using namespace std;
typedef long long LL;
const int N=102;
int t,n,m;
char s[N][N];
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++)scanf("%s",s[i]+1);
        
        {
            bool fg=0;
            for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)if(s[i][j]=='A')fg=1;
            if(!fg){
                printf("MORTAL\n");continue;
            }
        }   

        {
            bool fg=0;
            for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)if(s[i][j]=='P')fg=1;
            if(!fg){
                printf("0\n");continue;
            }
        }      

        {
            bool f;
            f=1; for(int i=1;i<=n;i++)if(s[i][1]=='P')f=0;
            if(f) { printf("1\n");continue; }

            f=1; for(int i=1;i<=n;i++)if(s[i][m]=='P')f=0;
            if(f) { printf("1\n");continue; }

            f=1; for(int i=1;i<=m;i++)if(s[1][i]=='P')f=0;
            if(f) { printf("1\n");continue; }

            f=1; for(int i=1;i<=m;i++)if(s[n][i]=='P')f=0;
            if(f) { printf("1\n");continue; }
        }

        {
            if(s[1][1]=='A'||s[1][m]=='A'||s[n][1]=='A'||s[n][m]=='A'){
                printf("2\n"); continue;
            }
            bool done=0;
            for(int i=1;i<=n;i++){
                bool tmp=1;
                for(int j=1;j<=m;j++)if(s[i][j]=='P')tmp=0;
                done|=tmp;
            }
            for(int j=1;j<=m;j++){
                bool tmp=1;
                for(int i=1;i<=n;i++)if(s[i][j]=='P')tmp=0;
                done|=tmp;
            }
            if(done){
                printf("2\n");continue;
            }
        }

        {
            bool f;
            f=0; for(int i=1;i<=n;i++)if(s[i][1]=='A')f=1;
            if(f) { printf("3\n");continue; }

            f=0; for(int i=1;i<=n;i++)if(s[i][m]=='A')f=1;
            if(f) { printf("3\n");continue; }

            f=0; for(int i=1;i<=m;i++)if(s[1][i]=='A')f=1;
            if(f) { printf("3\n");continue; }

            f=0; for(int i=1;i<=m;i++)if(s[n][i]=='A')f=1;
            if(f) { printf("3\n");continue; }
        }

        printf("4\n");

    }
}