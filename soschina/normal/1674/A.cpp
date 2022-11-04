#include <cstdio>
using namespace std;

int t, x, y;

int main(){
    scanf("%d", &t);
    while(t--){
        scanf("%d%d", &x, &y);
        if(y % x){
            puts("0 0");
            continue;
        }
        printf("1 %d\n", y / x);
    }
    return 0;
}