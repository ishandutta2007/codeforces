#include <cstdio>
using namespace std;

int t, n;

int main(){
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        if(n & 1)
            puts("-1");
        else
            printf("%d %d %d\n", 0, n >> 1, n >> 1);
        }
    return 0;
}