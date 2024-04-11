#include<stdio.h>
#include<algorithm>
using namespace std;
#define N 130
int a[N], n;
int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; i ++) scanf("%d", a+i);
    sort(a, a+n);
    for(int i = 1; i < n; i ++){
        if(a[i]> a[0]) { printf("%d\n", a[i]); return 0; }
    }
    puts("NO");
}