#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const int dx[]={-1, -1, 0, 1, 1, 1, 0, -1};
const int dy[]={0, 1, 1, 1, 0, -1, -1, -1};

int N, M;
char A[1010][1010];
char B[1010][1010];

int main(){
    scanf("%d %d", &N, &M);
    memset(A, '.', sizeof A);
    memset(B, '.', sizeof B);
    for (int i=1; i<=N; i++) for (int j=1; j<=M; j++) scanf(" %c", &A[i][j]);
    for (int i=1; i<=N; i++) for (int j=1; j<=M; j++){
        bool tf = true;
        for (int k=0; k<8; k++) if (A[i+dx[k]][j+dy[k]] != '#') tf = false;
        if (tf) for (int k=0; k<8; k++) B[i+dx[k]][j+dy[k]] = '#';
    }
    for (int i=1; i<=N; i++) for (int j=1; j<=M; j++) {
        if (A[i][j] != B[i][j]) {
            puts("NO");
            return 0;
        }
    }
    puts("YES");
    return 0;
}