#include <bits/stdc++.h>
using namespace std;

const int N = (1 << 22) + 500, INF = (1 << 22) - 1;

int n;
int num[N];
int F[N];

int main(){
    scanf("%d", &n);
    for(int i = 0; i < N; i++) F[i] = -1;
    for(int i = 0; i < n; i++) scanf("%d", &num[i]), F[num[i]] = num[i];
    for(int i = 21; i >= 0; i--){
        for(int j = N-1; j >= 0; j--){
            if(j & (1 << i)) F[j] = max(F[j], F[j-(1<<i)]);
        }
    }
    for(int i = 0; i < n; i++){
        printf("%d ", F[INF - num[i]]);
    }
}