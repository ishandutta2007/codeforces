#include<stdio.h>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
#define N 5020

struct env{
    int x;
    int y;
    int num;
};

env A[N];
int a[N], b[N], Max, NUM, n, w, h, pos, X, Y;

bool cmp(env S, env T){
    return (S.x != T.x) ? S.x < T.x : S.y < T.y ;
}



int main(){
    scanf("%d %d %d", &n, &w, &h);
    pos = 1;
    for(int i = 0; i < n; i ++){
        scanf("%d %d", &X, &Y);
        if(X > w && Y > h){
            A[pos].x = X;
            A[pos].y = Y;
            A[pos].num = i + 1;
            pos ++;
        }
    }
    if(pos == 0){
        puts("0");
    }
    else{
        sort(A + 1, A + pos, cmp);
        Max = NUM = 0;
        for(int i = 1; i < pos; i ++){
            a[i] = 1;
            b[i] = 0;
            for(int j = 0; j < i; j ++){
                if(A[i].x > A[j].x && A[i].y > A[j].y) {
                    if(a[i] < (a[j] + 1) ) {a[i] = a[j] + 1; b[i] = j; }
                }
            }
            if(Max < a[i]){
                Max = a[i];
                NUM = i;
            }
        }
        printf("%d\n", Max);
        int sto[10000], nsto = 0;
        while(NUM){
			sto[nsto++] = A[NUM].num;
			NUM = b[NUM];
        }
        for(int i = nsto - 1; i >= 0; i--) printf("%d ", sto[i]);
        puts("");
    }
}