#include <iostream>
#include <cstring>
using namespace std;
const int N=202;
int n;
char s[N][N];
int p[2];
int ans[N];
int vis[N];

void solve(){
    for(int i=1;i<=2*n-2;i++) vis[i]=ans[i]=0;
    for(int i=1;i<=2*n-2;i++){
        //printf("i=%d\n", i);
        int len=strlen(s[i]+1);
        if(vis[len]==0){
            vis[len]=i;
            bool ok=1;
            for(int j=1;s[i][j];j++){
                if(s[i][j] != s[p[0]][j]) ok=0;
            }    
            if(ok==1) {
                ans[i]=1; continue;
            }
            //printf("GG\n");
            ok=1; 
            for(int j=1;j<=len;j++){
                //printf("$ %c %c\n", s[i][j],s[p[1]][n-1-len+j]);
                if(s[i][j] != s[p[1]][n-1-len+j]) ok=0;
            }
            if(ok==1) {
                ans[i]=2; continue;
            }
            //printf("GG\n");
            return;
        } else {
            if(ans[vis[len]] == 2) {
                bool ok=1;
                for(int j=1;s[i][j];j++){
                    if(s[i][j] != s[p[0]][j]) ok=0;
                }    
                if(ok) ans[i]=1; else return;
            }

            if(ans[vis[len]] == 1) {
                bool ok=1; 
                for(int j=1;j<=len;j++){
                    if(s[i][j] != s[p[1]][n-1-len+j]) ok=0;
                }
                if(ok) ans[i]=2; else return;
            }
        }
    }
    for(int i=1;i<=2*n-2;i++){
        if(ans[i]==1) printf("P"); else printf("S");
    }
    exit(0);
}

int main(){
    scanf("%d",&n);
    for(int i=1;i<=2*n-2;i++){
        scanf("%s",s[i]+1);
    }

    int c=0;
    for(int i=1;i<=2*n-2;i++){
        if(strlen(s[i]+1) == n-1) {
            p[c++]=i;
        }
    }
    //printf("# %d %d\n", p[0],p[1]);
    solve(); swap(p[0],p[1]); solve();
}