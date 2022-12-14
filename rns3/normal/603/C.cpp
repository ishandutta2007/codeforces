#include<stdio.h>
#define N 101000
int a[N], f[N];

int k;

int calc(int x){
    if(x<=100) return f[x];
    if(x%2)return 0;
    int kk;
    if(k)kk = calc(x/2);
    else kk = 0;
    for(int i=1;  i<3; i++){
        if(i!=kk) return i;
    }
}

int main(){
    //freopen("1.in", "r", stdin);
    int n;
    scanf("%d%d", &n, &k);
    for(int i=0; i<n; i++)scanf("%d", &a[i]);
    k%=2;
    int ans = 0;
    f[0] = 0;
    f[1] = 1;
    for(int i=2; i<=100; i++){
        if(i%2){
            if(f[i-1])f[i] = 0;
            else f[i] = 1;
        }else {
            int x = f[i-1];
            int y;
            if(k)y = f[i/2];
            else y = 0;
            for(int j=0; j<3; j++){
                if(j!=x && j!=y){
                    f[i] = j;
                    break;
                }
            }
        }
    }
    for(int i=0; i<n; i++){
        ans^=calc(a[i]);
    }
    if(ans)puts("Kevin");
    else puts("Nicky");
    return 0;
}