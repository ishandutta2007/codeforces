#include <bits/stdc++.h>
using namespace std;

int A, B, C;
int X, Y, Z;

int main(){
    scanf("%d %d %d", &X, &Y, &Z);
    scanf("%d %d %d", &A, &B, &C);
    if (X > A){
        puts("NO");
        return 0;
    }
    A -= X;
    if (Y > A+B){
        puts("NO");
        return 0;
    }
    A -= Y;
    if (Z > A+B+C){
        puts("NO");
        return 0;
    }
    puts("YES");
    return 0;
}