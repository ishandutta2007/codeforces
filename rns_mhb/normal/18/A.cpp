#include <bits/stdc++.h>
using namespace std;

int x[5], y[5];

bool vis(int a, int b, int c, int d, int e, int f){
    int x = (a - c) * (a - c) + (b - d) * (b - d);
    int y = (a - e) * (a - e) + (b - f) * (b - f);
    int z = (c - e) * (c - e) + (d - f) * (d - f);
    if(!x || !y || !z) return 0;
    int m = min(min(x, y), z);
    if(m == x){
        if(x == abs(y - z)) return 1;
        else return 0;
    }
    if(m == y){
        if(y == abs(x - z)) return 1;
        else return 0;
    }
    if(m == z){
        if(z == abs(x - y)) return 1;
        else return 0;
    }
}

int main(){
    scanf("%d %d %d %d %d %d", &x[1], &y[1], &x[2], &y[2], &x[3], &y[3]);
    if(vis(x[1], y[1], x[2], y[2], x[3], y[3])) printf("RIGHT");
    else{
        bool tag = 0;
        if(vis(x[1] - 1, y[1], x[2], y[2], x[3], y[3])) tag = 1;
        if(vis(x[1] + 1, y[1], x[2], y[2], x[3], y[3])) tag = 1;
        if(vis(x[1], y[1] + 1, x[2], y[2], x[3], y[3])) tag = 1;
        if(vis(x[1], y[1] - 1, x[2], y[2], x[3], y[3])) tag = 1;
        if(vis(x[1], y[1], x[2] - 1, y[2], x[3], y[3])) tag = 1;
        if(vis(x[1], y[1], x[2] + 1, y[2], x[3], y[3])) tag = 1;
        if(vis(x[1], y[1], x[2], y[2] - 1, x[3], y[3])) tag = 1;
        if(vis(x[1], y[1], x[2], y[2] + 1, x[3], y[3])) tag = 1;
        if(vis(x[1], y[1], x[2], y[2], x[3] - 1, y[3])) tag = 1;
        if(vis(x[1], y[1], x[2], y[2], x[3] + 1, y[3])) tag = 1;
        if(vis(x[1], y[1], x[2], y[2], x[3], y[3] - 1)) tag = 1;
        if(vis(x[1], y[1], x[2], y[2], x[3], y[3] + 1)) tag = 1;
        if(tag) printf("ALMOST");
        else printf("NEITHER");
    }
}