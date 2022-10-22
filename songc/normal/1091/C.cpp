#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int N;
priority_queue<int> PQ;

int main(){
    scanf("%d", &N);
    for (int i=1; i*i<=N; i++){
        if (N % i != 0) continue;
        PQ.push(i);
        if (i != N/i) PQ.push(N/i);
    }

    while (!PQ.empty()){
        int i = PQ.top();
        LL x = N/i;
        printf("%lld ", x + (x*(x-1)/2*i));
        PQ.pop();
    }
    return 0;
}