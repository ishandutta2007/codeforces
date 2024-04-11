#include <bits/stdc++.h>

using namespace std;

int T,N,M;
int a[110][110];

int solve(vector<int> &v, int d) {
    sort(v.begin(), v.end());
    int N = v.size();
    int max_delta = 0, S = 0;
    if (d == 1) {
        S = v[0];
        max_delta = -2 * v[0];
    }
    for (int i=d;i<N;i+=2) {
        S += v[i];
        if (i == N - 1) continue;
        S += v[i + 1];
        max_delta = max(max_delta, -2 * S);
    }
    //printf("%d %d\n",d,max_delta);
    return S + max_delta;
}

int main() {
    scanf("%d",&T);
    while(T--) {
        scanf("%d%d",&N,&M);
        vector<int>v1,v2;
        for (int i=1;i<=N;i++) {
            for (int j=1;j<=M;j++) {
                scanf("%d",&a[i][j]);
                if ((i + j) % 2 == 1) {
                    v1.push_back(a[i][j]);
                } else {
                    v2.push_back(a[i][j]);
                }
            }
        }
        printf("%d\n", max(solve(v1, 0) + solve(v2, 0), solve(v1, 1) + solve(v2, 1)));
    }
}