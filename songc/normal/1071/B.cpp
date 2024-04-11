#include <bits/stdc++.h>
#define pii pair<int, int>
using namespace std;
typedef long long LL;

int N, K;
int Acnt[2020][2020];
char A[2020][2020];
bool chk[2020][2020];

int main(){
    scanf("%d %d", &N, &K);
    for (int i=1; i<=N; i++) for (int j=1; j<=N; j++) scanf(" %c", &A[i][j]);
    for (int i=1; i<=N; i++) for (int j=1; j<=N; j++) {
        Acnt[i][j] = max(Acnt[i-1][j], Acnt[i][j-1]);
        if (A[i][j] == 'a') Acnt[i][j]++;
        if (i + j - 1 - Acnt[i][j] <= K) A[i][j] = 'a';
    }

    chk[1][1] = true;
    printf("%c", A[1][1]);
    for (int i=3; i<=2*N; i++){
        char Min = 'z' + 1;
        for (int j=1; j<i; j++){
            if (j>N || i-j>N) continue;
            if (!chk[j-1][i-j] && !chk[j][i-j-1]) continue;
            Min = min(Min, A[j][i-j]);
        }
        printf("%c", Min);
        for (int j=1; j<i; j++){
            if (j>N || i-j>N) continue;
            if (!chk[j-1][i-j] && !chk[j][i-j-1]) continue;
            if (Min == A[j][i-j]) chk[j][i-j] = true;
        }
    }
    return 0;
}