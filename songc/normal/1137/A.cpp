#include <bits/stdc++.h>
using namespace std;

int N, M;
int A[1010][1010];
vector<int> R[1010], C[1010];
int ans[1010][1010];

int main(){
    scanf("%d %d", &N, &M);
    for (int i=1; i<=N; i++) for (int j=1; j<=M; j++) {
        scanf("%d", &A[i][j]);
        R[i].push_back(A[i][j]);
        C[j].push_back(A[i][j]);
    }
    for (int i=1; i<=N; i++){
        sort(R[i].begin(), R[i].end());
        R[i].erase(unique(R[i].begin(), R[i].end()), R[i].end());
    }
    for (int i=1; i<=M; i++){
        sort(C[i].begin(), C[i].end());
        C[i].erase(unique(C[i].begin(), C[i].end()), C[i].end());
    }
    for (int i=1; i<=N; i++) for (int j=1; j<=M; j++){
        int x = lower_bound(R[i].begin(), R[i].end(), A[i][j])-R[i].begin()+1;
        int y = lower_bound(C[j].begin(), C[j].end(), A[i][j])-C[j].begin()+1;
        ans[i][j] = max(R[i].size() + max(0, y-x), C[j].size() + max(0, x-y));
    }
    for (int i=1; i<=N; i++){
        for (int j=1; j<=M; j++) printf("%d ", ans[i][j]);
        printf("\n");
    }
    return 0;
}