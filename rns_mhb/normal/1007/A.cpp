#include<bits/stdc++.h>
using namespace std;

#define N 100010

int a[N], b[N];

int main() {
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; i ++) scanf("%d", a + i);
    sort(a + 1, a + n + 1);
    b[n] = 0;
    int add = 1;
    for(int i = n - 1; i; i --) {
        if(a[i] == a[i+1]) add ++, b[i] = b[i+1];
        else b[i] = b[i+1] + add, add = 1;
    }
    int run = 0;
    for(int i = n; i; i --) if(b[i] > run) run ++;
    printf("%d\n", run);
}