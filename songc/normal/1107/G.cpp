#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<LL, LL> pll;

int N;
LL ans;
LL A, D[303030], C[303030], S[303030];
int T[1202020];

void makeTree(int id, int s, int e){
    if (s == e){
        T[id] = s;
        return;
    }
    int mid = (s+e)/2;
    makeTree(id*2, s, mid);
    makeTree(id*2+1, mid+1, e);
    if (D[T[id*2] + 1] - D[T[id*2]] < D[T[id*2+1] + 1] - D[T[id*2+1]]) T[id] = T[id*2+1];
    else T[id] = T[id*2];
}

int RMQ(int id, int s, int e, int ts, int te){
    if (ts <= s && e <= te) return T[id];
    if (e < ts || te < s) return N+1;
    int mid = (s+e)/2;
    int lret = RMQ(id*2, s, mid, ts, te);
    int rret = RMQ(id*2+1, mid+1, e, ts, te);
    if (D[lret + 1] - D[lret] < D[rret + 1] - D[rret]) return rret;
    else return lret;
}

pll f(int l, int r){
    if (l == r){
        ans = max(ans, S[l] - S[l-1]);
        return pll(max(0ll, S[l]-S[l-1]), max(0ll, S[l]-S[l-1]));
    }
    int m = RMQ(1, 1, N-1, l, r-1);
    pll lret = f(l, m);
    pll rret = f(m+1, r);
    ans = max(ans, lret.second + rret.first - (D[m+1]-D[m])*(D[m+1]-D[m]));
    return pll(max(lret.first, S[m]-S[l-1]+rret.first), max(rret.second, S[r]-S[m]+lret.second));
}

int main(){
    scanf("%d %lld", &N, &A);
    for (int i=1; i<=N; i++) {
        scanf("%lld %lld", &D[i], &S[i]);
        S[i] = S[i-1] + A - S[i];
    }
    if (N == 1){
        printf("%lld\n", max(S[1], 0ll));
        return 0;
    }
    makeTree(1, 1, N-1);
    f(1, N);
    printf("%lld\n", ans);
    return 0;
}