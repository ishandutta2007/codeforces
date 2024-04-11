#include <bits/stdc++.h>
#define INF 1234567890
using namespace std;
typedef long long LL;
typedef pair<int, int> pii;

int N, M, Q;
int A[303030], B[303030];
int D[4040404], P[4040404];

void update(int id, int s, int e, int t, int v){
    if (e < t || t < s) return;
    if (s == e){
        if (v > 0) D[id]++;
        else P[id]++;
        if (D[id] > P[id]) D[id] -= P[id], P[id] = 0;
        else P[id] -= D[id], D[id] = 0;
        return;
    }
    int mid = (s+e)/2;
    update(id*2, s, mid, t, v);
    update(id*2+1, mid+1, e, t, v);
    D[id] = D[id*2+1], P[id] = P[id*2];
    if (D[id*2] < P[id*2+1]) P[id] += P[id*2+1] - D[id*2];
    else D[id] += D[id*2] - P[id*2+1];
}

int query(int id, int s, int e, int k){
    if (D[id] <= k) return -1;
    if (s == e) return s;
    int mid = (s+e)/2;
    int ret = query(id*2+1, mid+1, e, k);
    if (ret != -1) return ret;
    return query(id*2, s, mid, k + P[id*2+1] - D[id*2+1]);
}

int main(){
    int a, b, c;
    scanf("%d %d", &N, &M);
    for (int i=1; i<=N; i++){
        scanf("%d", &A[i]);
        update(1, 1, 1000000, A[i], 1);
    }
    for (int i=1; i<=M; i++){
        scanf("%d", &B[i]);
        update(1, 1, 1000000, B[i], -1);
    }

    scanf("%d", &Q);
    while (Q--){
        scanf("%d %d %d", &a, &b, &c);
        if (a == 1){
            update(1, 1, 1000000, A[b], -1);
            A[b] = c;
            update(1, 1, 1000000, A[b], 1);
            printf("%d\n", query(1, 1, 1000000, 0));
        }
        else{
            update(1, 1, 1000000, B[b], 1);
            B[b] = c;
            update(1, 1, 1000000, B[b], -1);
            printf("%d\n", query(1, 1, 1000000, 0));
        }
    }
    return 0;
}