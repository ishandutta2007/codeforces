#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;
typedef long long LL;
typedef pair<int, int> pii;

int N;
int P[101010], num=1;

int main(){
    scanf("%d", &N);
    for (int i=2; i<=N; i++){
        if (P[i]) {
            printf("%d ", P[i]);
            continue;
        }
        for (int j=2*i; j<=N; j+=i) P[j] = num;
        printf("%d ", num);
        num++;
    }
    return 0;
}