#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> pii;

int N, K;
int ans;

int main(){
    int a;
    scanf("%d %d", &K, &N);
    for (int i=1; i<N; i++){
        scanf("%d", &a);
        ans = (ans + a*K) % 2;
    }
    scanf("%d", &a);
    ans = (ans + a) % 2;
    printf(ans ? "odd" : "even");
    return 0;
}