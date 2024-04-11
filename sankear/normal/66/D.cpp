#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <string>
#include <string.h>
#include <vector>
#include <set>
#include <map>
#include <complex>

using namespace std;

const int base = (int)1e4;

int cur[100], sw[100], lst[100];
int ans[100][100];

inline bool prime(int n){
    for(int i = 2; i * i <= n; i++){
        if(n % i == 0){
            return false;
        }
    }
    return true;
}

inline void inttolong(int *a, int b){
    if(b == 0){
        a[0] = 1;
        a[1] = 0;
        return;
    }
    a[0] = 0;
    while(b > 0){
        a[++a[0]] = b % base;
        b /= base;
    }
}

inline void write(int *a){
    printf("%d", a[a[0]]);
    for(int i = a[0] - 1; i > 0; i--){
        printf("%04d", a[i]);
    }
}

inline void qq(int *a, int *b){
    a[0] = b[0];
    for(int i = 1; i <= a[0]; i++){
        a[i] = b[i];
    }
}

inline void norm(int *a){
    while(a[0] > 1 && a[a[0]] == 0){
        a[0]--;
    }
}

inline void mult(int *a, int *b){
    sw[0] = a[0] + b[0];
    for(int i = 1; i <= sw[0]; i++){
        sw[i] = 0;
    }
    for(int i = 1; i <= a[0]; i++){
        for(int j = 1; j <= b[0]; j++){
            sw[i + j - 1] += a[i] * b[j];
            sw[i + j] += sw[i + j - 1] / base;
            sw[i + j - 1] %= base;
        }
    }
    norm(sw);
    qq(a, sw);
}

int main(){
    //freopen("border.in", "r", stdin);
    //freopen("border.out", "w", stdout);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n;
    scanf("%d", &n);
    if(n == 2){
        printf("-1\n");
        return 0;
    }
    int sz = 0;
    for(int i = 2; sz < n; i++){
        if(prime(i)){
            lst[sz++] = i;
        }
    }
    for(int i = 0; i < n; i++){
        inttolong(ans[i], 1);
        for(int j = 0; j < n; j++){
            if(i != j){
                inttolong(cur, lst[j]);
                mult(ans[i], cur);
            }
        }
    }
    for(int i = 0; i < n; i++){
        write(ans[i]);
        printf("\n");
    }
    return 0;
}