#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> pii;

int N, K;
int A[110];

bool chk(int k){
    int ret = 0;
    for (int i=1; i<=100; i++) ret += A[i] / k;
    return ret >= K;
}

int main(){
    int a;
    scanf("%d %d", &K, &N);
    for (int i=1; i<=N; i++){
        scanf("%d", &a);
        A[a]++;
    }
    for (int i=100; i>0; i--){
        if (chk(i)) {
            printf("%d\n", i);
            return 0;
        }
    }
    puts("0");
    return 0;
}