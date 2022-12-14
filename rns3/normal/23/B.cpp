#include <stdio.h>
#define max(a, b) ((a) > (b) ? (a) : (b))

int T, n;

int main(){
    for(scanf("%d", &T); T--;){
        scanf("%d", &n);
        printf("%d\n", max(0, n-2));
    }
}