#include <cstdio>
using namespace std;

int t, n;

int main(){
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        if(n == 3){
            puts("-1");
            continue;
        }
        if(n == 2)
            printf("2 1 ");
        else if(n == 5)
            printf("5 4 1 2 3 ");
        else if(n & 1){
            for (int i = n - 1; i >= 4; i -= 2)
                printf("%d %d ", i, i + 1);
            printf("3 2 1 ");
        }
        else
            for (int i = n; i >= 1; i--)
                printf("%d ", i);
        putchar('\n');
    }
    return 0;
}