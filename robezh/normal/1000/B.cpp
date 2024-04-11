#include <bits/stdc++.h>
using namespace std;

const int N = (int)1e5 + 500;

int n, M;
int num[N], pa[N], pb[N];

int main(){
    scanf("%d%d", &n, &M);
    num[0] = 0;
    for(int i = 1; i <= n; i++) scanf("%d", &num[i]);
    num[n+1] = M;
    for(int i = 1; i <= n+1; i++){
        if(i % 2) pa[i] = pa[i-1] + (num[i] - num[i-1]), pb[i] = pb[i-1];
        else pb[i] = pb[i-1] + (num[i] - num[i-1]), pa[i] = pa[i-1];
    }
    int res = 0;
    for(int i = 0; i <= n; i++){
        if(num[i] + 1 == num[i+1]) continue;
        int now = pa[i] + (num[i+1] - num[i] - 1) + (pb[n+1] - pb[i+1]);
        res = max(now, res);
    }
    res = max(res, pa[n+1]);
    printf("%d", res);
}