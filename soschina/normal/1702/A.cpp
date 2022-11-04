#include <cstdio>
using namespace std;

int t, m;

int main(){
    scanf("%d", &t);
    while(t--){
        scanf("%d", &m);
        long long i;
        for (i = 1; i <= m; i *= 10)
            ;
        i /= 10;
        printf("%lld\n", m - i);
    }
    return 0;
}