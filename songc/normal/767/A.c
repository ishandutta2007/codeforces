#include <stdio.h>

int n, s;
int chk[101010];


int main(){
    int a;
    scanf("%d", &n);
    s=n;
    for (int i=0; i<n; i++) {
        scanf("%d", &a);
        if (a==s) {
            printf("%d ", a);
            for ( s--; s>0; s--) {
                if (chk[s]) {
                    printf("%d ", s);
                    chk[s] = 0;
                }
                else break;
            }
        }
        else chk[a]=1;
        printf("\n");
    }
    return 0;
}