#include <bits/stdc++.h>
using namespace std;

const int N = (int)1e5 + 500, INF = (int)1e9;

int n;
int num[N], idx[N];
int res[N];

int main() {
    scanf("%d", &n);
    for(int i = 1; i <= n; i++){
        scanf("%d", &num[i]);
        idx[num[i]] = i;
    }
    fill(res, res+N, 0);
    for(int i = n; i >= 1; i--){
        int st = idx[i] % i;
        if(st == 0) st += i;
        for(int j = st; j <= n; j+= i){
            if(num[j] > i && !res[j]) res[idx[i]] = 1;
        }
    }
    for(int i = 1; i <= n; i++){
        printf(res[i] == 1 ? "A" : "B");
    }
}