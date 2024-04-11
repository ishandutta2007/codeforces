#include <cstdio>
using namespace std;

int t, n;

int main(){
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        puts("1 ");
        for (int i = 2; i <= n; i++){
            printf("1 ");
            for (int j = 2; j < i; j++)
                printf("0 ");
            printf("1 ");
            putchar('\n');
        }
    }
    return 0;
}