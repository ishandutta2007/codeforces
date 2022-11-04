#include <cstdio>
#include <iostream>
using namespace std;

int t, n, z;

int main(){
    scanf("%d", &t);
    while(t--){
        scanf("%d%d", &n, &z);
        int a, ans = 0;
        while(n--){
            scanf("%d", &a);
            ans = max(ans, a | z);
        }
        printf("%d\n", ans);
    }
    return 0;
}