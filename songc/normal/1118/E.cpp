#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int N, K;

int main(){
    scanf("%d %d", &N, &K);
    if (N > (LL)K*(K-1)){
        puts("NO");
        return 0;
    }
    puts("YES");
    for (int i=1; i<K && N; i++) for (int j=0; j<K && N; j++){
        printf("%d %d\n", j+1, (j+i)%K+1);
        N--;
    }
    return 0;
}