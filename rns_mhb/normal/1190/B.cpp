#include<bits/stdc++.h>
using namespace std;

#define N 100010

int a[N], b[N];

int main() {
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; i ++) scanf("%d", &a[i]);
    sort(a + 1, a + n + 1);
    int cnt = 0;
    for(int i = 1; i < n; i ++) if(a[i] == a[i+1]) cnt ++;
    if(cnt > 1) {
        puts("cslnb");
        return 0;
    }
    if(cnt == 1) {
        a[0] = -1;
        for(int i = 1; i <= n; i ++) {
            if(a[i] == a[i+1]) {
                if(a[i] == a[i-1] + 1) {
                    puts("cslnb");
                    return 0;
                }
                break;
            }
        }
    }
    long long tot = 0;
    for(int i = 1; i <= n; i ++) tot += a[i] - i + 1;
    if(tot & 1) puts("sjfnb");
    else puts("cslnb");
}