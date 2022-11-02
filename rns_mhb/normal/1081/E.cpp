#include<bits/stdc++.h>
using namespace std;

#define N 200010

vector <int> d[N];
int n, a[N], x[N];

int main() {
    for(int i=1;i<1000;i++)for(int j=i+2;i*j<N;j+=2)d[i*j].push_back(i);
    scanf("%d", &n);
    for(int i = 2; i <= n; i += 2) scanf("%d", &x[i]);
    a[n+1] = N;
    for(int i = n; i; i -= 2) {
        if(d[x[i]].empty()) {puts("No"); return 0;}
        if(x[i] / d[x[i]].back() + d[x[i]].back() >= 2 * a[i+1]) {puts("No"); return 0;}
        int L = 0, R = d[x[i]].size() - 1;
        while(L < R) {
            int M = L + R >> 1;
            if(x[i] / d[x[i]][M] + d[x[i]][M] < 2 * a[i+1]) R = M;
            else L = M + 1;
        }
        a[i-1] = (x[i] / d[x[i]][R] - d[x[i]][R]) / 2;
        a[i] = (x[i] / d[x[i]][R] + d[x[i]][R]) / 2;
    }
    puts("Yes");
    for(int i = 1; i <= n; i ++) printf("%I64d ", 1ll*a[i]*a[i]-1ll*a[i-1]*a[i-1]);
    puts("");
}