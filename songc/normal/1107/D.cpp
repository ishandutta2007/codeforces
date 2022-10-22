#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int N, ans;
int A[5500][5500];

int main(){
    char ch;
    int bit, k;
    scanf("%d", &N);
    for (int i=1; i<=N; i++){
        for (int j=0; j<N/4; j++){
            scanf(" %c", &ch);
            if ('0' <= ch && ch <= '9') bit = ch - '0';
            else bit = 10 + ch - 'A';
            for (int k=1; k<=4; k++) if (bit & (1<<(4-k))) A[i][4*j+k] = 1;
        }
    }

    ans = N;
    for (int i=1; i<=N; i++){
        k=1;
        for (int j=2; j<=N; j++){
            if (A[i][j] == A[i][j-1]) {
                k++;
                continue;
            }
            ans = __gcd(ans, k);
            k = 1;
        }
        ans = __gcd(ans, k);
    }

    for (int i=1; i<=N; i++){
        k=1;
        for (int j=2; j<=N; j++){
            if (A[j][i] == A[j-1][i]) {
                k++;
                continue;
            }
            ans = __gcd(ans, k);
            k = 1;
        }
        ans = __gcd(ans, k);
    }
    printf("%d\n", ans);
    return 0;
}