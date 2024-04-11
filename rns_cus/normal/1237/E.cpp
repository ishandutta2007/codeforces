#include <bits/stdc++.h>
using namespace std;

#define N 1000100

bool vis[N];

int main() {
    vis[1] = vis[2] = vis[4] = vis[5] = 1;
    int k = 5;
    while (1) {
        k <<= 1;
        if (k < N) vis[k] = vis[k-1] = 1;
        k <<= 1;
        if (k < N) vis[k] = vis[k+1] = 1;
        k ++;
        if (k >= N) break;
    }
    int n;
    scanf("%d", &n);
    if (vis[n]) puts("1");
    else puts("0");


    return 0;
}