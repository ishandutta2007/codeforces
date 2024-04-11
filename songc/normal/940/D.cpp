#include <bits/stdc++.h>
#define LM 1000000000
using namespace std;

int N, l = -LM, r = LM;
int a[101010];
int b[101010];

int m(int k){
    int ret = LM;
    for (int i=0; i<5; i++) ret = min(a[k-i], ret);
    return ret;
}

int M(int k){
    int ret = -LM;
    for (int i=0; i<5; i++) ret = max(a[k-i], ret);
    return ret;
}

int main() {
    scanf("%d", &N);
    for (int i=1; i<=N; i++) scanf("%d", &a[i]);
    for (int i=1; i<=N; i++) scanf("%1d", &b[i]);

    for (int i=5; i<=N; i++){
        if (b[i-1] == 0 && b[i] == 1){
            l = max(M(i)+1, l);
            i += 3;
        }
        else if (b[i-1] == 1 && b[i] == 0){
            r = min(m(i)-1, r);
            i += 3;
        }
    }
    printf("%d %d", l, r);
    return 0;
}