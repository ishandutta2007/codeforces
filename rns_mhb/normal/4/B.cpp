#include <stdio.h>
#define N 40
int s, d, maxi[N], mini[N], maxs, mins, ss;

int main() {
    scanf("%d%d", &d, &s);
    for(int i = 1; i <= d; i ++) {
        scanf("%d%d", &mini[i], &maxi[i]);
        maxs += maxi[i];
        mins += mini[i];
    }
    if(s < mins || s > maxs) puts("NO");
    else {
        puts("YES");
        int i = 0;
        while(ss < s - mins && i < d) {
            ++ i;
            ss += maxi[i] - mini[i];
        }
        if(i == 0) {
            for(int j = 1; j < d; j ++) printf("%d ", mini[j]);
            printf("%d", mini[d]);
        }
        else {
            int j;
            for(j = 1; j < i; j ++) printf("%d ", maxi[j]);
            printf("%d ", maxi[i] - ss + s - mins);
            if(i < d) {
                for(j = i + 1; j < d; j ++) printf("%d ", mini[j]);
                printf("%d", mini[d]);
            }
        }
    }
    return 0;
}