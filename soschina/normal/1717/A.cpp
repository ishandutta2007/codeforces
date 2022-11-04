#include <cstdio>
using namespace std;

int t, n;

int main(){
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        printf("%d\n", n / 2 * 2 + n / 3 * 2 + n);
    }
    return 0;
}