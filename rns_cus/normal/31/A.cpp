#include<stdio.h>
#define N 111
int a[N];
int n;
int ss(){
    for(int i = 0; i < n; i ++) {
        for(int j = 0; j < n; j ++) if(j != i){
            for(int k = 0; k < n; k ++) if(k != i && k != j){
                if(a[i] == a[j] + a[k]) {printf("%d %d %d\n", i+1, j+1, k+1); return 0;}
            }
        }
    }
    printf("-1\n");
    return 0;
}
int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; i ++) scanf("%d", &a[i]);
    ss();
}