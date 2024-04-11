#include <cstdio>
using namespace std;
const int N = 21;

int t, n, a[N];

int main(){
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        int p = 1;
        for (int i = 1; i <= n; i++){
            scanf("%d", &a[i]);
            if(a[i] > a[p])
                p = i;
        }
        printf("%d\n", p);
    }
    return 0;
}