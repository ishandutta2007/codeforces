#include<stdio.h>

int n, x, y;

int pow(int u, int v){
    int tmp = 1;
    for(int j = 0 ; j < v; j ++) tmp *= u;
    return tmp;
}

int main(){
    scanf("%d %d %d", &x, &y, &n);
    if(x == 0 and y == 0){ puts("1"); return 0; }
    if(x == 0 and y){ puts("No solution"); return 0; }
    int z = y / x;
    if(y != x * z){ puts("No solution"); return 0; }
    x = z;
    if((!n%2) and z < 0){ puts("No solution"); return 0; }
    z = z > 0 ? z : -z ;
    for(int i = 0; i <= z; i ++){
        if(z == pow(i, n)){ printf("%d\n", x > 0 ? i : -i); return 0;}
        else if( z < pow(i, n)){ puts("No solution"); return 0; }
    }
}