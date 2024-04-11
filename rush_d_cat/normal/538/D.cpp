#include <iostream>
#include <cstring>
#include <vector>
const int N = 52;
using namespace std;
int n; char s[N][N],t[N][N];int res[120][120];
vector< pair<int,int> > vec;
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%s",s[i]+1);
    for(int dx=-n+1;dx<n;dx++){
        for(int dy=-n+1;dy<n;dy++){
            bool ok=1,in=0;
            for(int i=1;i<=n;i++){
                for(int j=1;j<=n;j++){
                    if(s[i][j] == 'o') {
                        int ni = i+dx; 
                        int nj = j+dy;
                        if (ni>=1 && ni<=n && nj>=1 && nj<=n) {
                            in=1;
                            if(s[ni][nj] != 'x' && s[ni][nj] != 'o')
                                ok = 0;
                        }
                    }
                }
            }
            if(ok && in)  {
                vec.push_back(make_pair(dx,dy));
                //printf("%d %d\n", dx,dy);
            }
        }
    }
    for(int i=1;i<=n;i++)for(int j=1;j<=n;j++){
        t[i][j]='.';
        if(s[i][j]=='o') t[i][j]='o';
    }
    //for(int i=1;i<=n;i++) printf("%s\n", t[i]+1);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(s[i][j] == 'o') {
                for(auto p: vec) {
                    int dx=p.first, dy=p.second;
                    
                    int ni = i+dx; 
                    int nj = j+dy;
                    if (ni>=1 && ni<=n && nj>=1 && nj<=n) {
                        if(t[ni][nj] == '.') t[ni][nj] = 'x';
                    }
                }       
            }   
        }
    }
    //for(int i=1;i<=n;i++) printf("%s\n", t[i]+1);
    bool ok=1;
    for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)if(s[i][j]!=t[i][j])ok=0;
    if(!ok) return !printf("NO\n");
    for(auto p: vec) {
        res[n+p.first][n+p.second] = 1;
    }

    printf("YES\n");
    for(int i=1;i<=2*n-1;i++){
        for(int j=1;j<=2*n-1;j++) {
            if(i==n&&j==n) printf("o");
            else if(res[i][j]) printf("x");
            else printf(".");
        }
        printf("\n");
    }
}