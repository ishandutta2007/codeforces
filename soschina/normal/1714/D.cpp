#include <cstdio>
#include <cstring>
using namespace std;
const int N = 102, M = 12;

int q, n, m, f[N], len[M], from[N], use[N];
char s[N], t[M][M];

int main(){
    scanf("%d", &q);
    while(q--){
        scanf("%s%d", s + 1, &m);
        n = strlen(s + 1);
        for (int i = 1; i <= m; i++){
            scanf("%s", t[i] + 1);
            len[i] = strlen(t[i] + 1);
        }
        f[0] = 0;
        for (int i = 1; i <= n; i++){
            f[i] = 0x3f3f3f3f;
            for (int j = 1; j <= m; j++){
                if(len[j] <= i){
                    bool flag = true;
                    for (int k = 0; k < len[j]; k++)
                        if(s[i - k] != t[j][len[j] - k])
                            flag = false;
                    if(flag){
                        for (int k = 1; k <= len[j]; k++)
                            if(f[i - k] + 1 < f[i]){
                                f[i] = f[i - k] + 1;
                                from[i] = i - k;
                                use[i] = j;
                            }
                    }
                }
            }
        }
        if(f[n] == 0x3f3f3f3f)
            puts("-1");
        else{
            printf("%d\n", f[n]);
            for (int p = n; p; p = from[p])
                printf("%d %d\n", use[p], p - len[use[p]] + 1);
        }
    }
    return 0;
}