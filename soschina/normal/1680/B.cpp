#include <cstdio>
using namespace std;
const int N = 10;

int t, n, m, x, y;
char s[N][N];

int main(){
    scanf("%d", &t);
    while(t--){
        x = 0, y = 0;
        scanf("%d%d", &n, &m);
        for (int i = 1; i <= n; i++)
            scanf("%s", s[i] + 1);
        bool flag = true;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
                if(s[i][j] == 'R'){
                    if(!x){
                        x = i, y = j;
                    }else if(j < y)
                        flag = false;
                }
        puts(flag ? "YES" : "NO");
    }
    return 0;
}