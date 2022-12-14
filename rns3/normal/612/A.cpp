#include <cstdio>

char s[110];

int n, p, q;

int main(){
    scanf("%d%d%d", &n, &p, &q);
    scanf("%s", s);
    for(int i = 0; i * p <= n; i ++) {
        if((n - p * i) % q == 0) {
            int k = (n - p * i) / q, r = 0;
            printf("%d\n", i + k);
            for(int j = 0; j < i; j ++) {
                for(int t = 0; t < p; t ++) printf("%c", s[r ++]);
                puts("");
            }
            for(int j = 0; j < k; j ++) {
                for(int t = 0; t < q; t ++) printf("%c", s[r ++]);
                puts("");
            }
            return 0;
        }
    }
    puts("-1");
    return 0;
}