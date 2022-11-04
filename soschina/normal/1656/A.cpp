#include <cstdio>
#include <iostream>
using namespace std;
const int N = 1e5 + 1;

int t, n, a[N], maxp, minp;

int main(){
    scanf("%d", &t);
    while(t--){
        maxp = minp = 1;
        scanf("%d", &n);
        for(int i = 1; i <= n; i++){
            scanf("%d", &a[i]);
            if(a[i] >= a[maxp]) maxp = i;
            if(a[i] < a[minp]) minp = i;
        }
        printf("%d %d\n", minp, maxp);
    }
    return 0;
}