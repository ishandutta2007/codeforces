#include<bits/stdc++.h>
using namespace std;

int len, pos;

void insert(int x) {
    len ++;
    if(x <= pos) pos ++;
}

void erase(int x) {
    if(x >= pos) len = x;
    else len -= x, pos -= x;
}

int main() {
    int m, t;
    scanf("%d%d%d%d", &len, &pos, &m, &t);
    while(t --) {
        int type, x;
        scanf("%d%d", &type, &x);
        if(type == 1) insert(x);
        else erase(x);
        printf("%d %d\n", len, pos);
    }
}