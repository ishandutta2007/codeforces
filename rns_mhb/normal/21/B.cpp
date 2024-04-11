#include<bits/stdc++.h>
using namespace std;

int main() {
    int a[2], b[2], c[2];
    for(int i = 0; i < 2; i ++) scanf("%d%d%d", &a[i], &b[i], &c[i]);
    for(int i = 0; i < 2; i ++)
        if(a[i] == 0 && b[i] == 0 && c[i] != 0) {
            puts("0");
            return 0;
        }
    if(a[0] * b[1] == a[1] * b[0]) {
        if(a[0] * c[1] == a[1] * c[0] && b[0] * c[1] == b[1] * c[0]) puts("-1");
        else puts("0");
    }
    else puts("1");
    return 0;
}