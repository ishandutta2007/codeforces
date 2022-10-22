#include <bits/stdc++.h>
using namespace std;

int N, H;
int A[202020], B[202020];
int ans;
int Asum, Bsum;

int main(){
    int s, e, t;
    scanf("%d %d", &N, &H);
    scanf("%d %d", &s, &e);
    A[0] = e - s, t = e;
    for (int i=1; i<N; i++){
        scanf("%d %d", &s, &e);
        B[i] = s - t;
        A[i] = e - s;
        t = e;
    }

    int lo = 0;
    Asum = A[0], Bsum = 0;

    for (int i=1; i<=N; i++){
        while (Bsum + B[i] >= H && lo < i){
            ans = max(ans, Asum);
            Asum -= A[lo++];
            Bsum -= B[lo];
        }
        Asum += A[i];
        Bsum += B[i];
    }
    ans = max(ans, Asum);

    printf("%d", ans + H);
    return 0;
}