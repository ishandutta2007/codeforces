#include<stdio.h>
#define N 100010

int n, a[N], sum1, sum2, p1, p2;

int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; i ++) scanf("%d", &a[i]);
    sum1 = sum2 = p1 = p2 = 0;
    while((p1 + p2) < n){
        if(sum1 > sum2) sum2 += a[n - (++ p2)];
        else sum1 += a[p1++];
    }
    printf("%d %d\n", p1, p2);
}