#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> pii;

int N, ans;
char A[550][550];

int main(){
    scanf("%d", &N);
    for (int i=1; i<=N; i++){
        for (int j=1; j<=N; j++){
            scanf(" %c", &A[i][j]);
        }
    }

    for (int i=1; i<=N; i++) for (int j=1; j<=N; j++){
        if (A[i][j] == 'X' && A[i+1][j+1] == 'X' && A[i+1][j-1] == 'X' && A[i-1][j+1] == 'X' && A[i-1][j-1] == 'X') ans++;
    }
    printf("%d\n", ans);
    return 0;
}