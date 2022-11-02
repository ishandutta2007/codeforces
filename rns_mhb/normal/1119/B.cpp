#include<bits/stdc++.h>
using namespace std;

#define N 300010

int n, a[N], b[N], h;

int main() {
    scanf("%d%d", &n, &h);
    for(int i = 1; i <= n; i ++) scanf("%d", &a[i]);
    for(int i = n; i; i --) {
        for(int j = 1; j <= n; j ++) b[j] = a[j];
        sort(b + 1, b + i + 1);
        bool flag = 0;
        int cur = 0;
        for(int j = i; j > 0; j -= 2) {
            cur += b[j];
            if(cur > h) {
                flag = 1;
                break;
            }
        }
        if(!flag) {
            printf("%d\n", i);
            return 0;
        }
    }
}