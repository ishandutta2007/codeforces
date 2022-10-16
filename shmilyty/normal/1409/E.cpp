#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
#include <climits>
#include <algorithm>
#include <map>
inline int read() { char c = getchar(); int sign = 1; int x = 0; while(c > '9' || c < '0') { if(c=='-')sign = -1; c = getchar(); } while(c <= '9' && c >= '0') { x *= 10; x += c - '0'; c = getchar(); } return x * sign; }
using namespace std;
const int _ = 2e5 + 100;
int n, k;
int A[_];
int B[_];
int W[_];
int InL[_];
int InR[_];
map<int, int > M;
void doit(){
    n = read(), k = read();
    for(int i = 1; i <= n; i++) B[i] = read();
    for(int i = 1; i <= n; i++) read();
    for(int i = 1; i <= n; i++) ++M[B[i]];
    memcpy(A, B, sizeof(A));
    sort(A + 1, A + 1 + n);
    n = unique(A + 1, A + 1 + n) - A - 1;
    for(int i = 1; i <= n; i++) W[i] = M[A[i]];
    int L = 1;
    int sum = 0;
    for(int R = 1; R <= n; R++){
        sum += W[R];
        while(A[R] - A[L] > k) sum -= W[L], L++;
        InL[R] = sum;
    }
    int R = n;
    sum = 0;
    for(int L = n; L >= 1; L--){
        sum += W[L];
        while(A[R] - A[L] > k) sum -= W[R], R--;
        InR[L] = sum;
    }
    for(int i = 1; i <= n; i++) InL[i] = max(InL[i - 1], InL[i]);
    for(int i = n; i >= 1; i--) InR[i] = max(InR[i + 1], InR[i]);
    int ans = 0;
    for(int i = 0; i <= n; i++){
        ans = max(ans, InL[i] + InR[i + 1]);
    }
    if(A[n] - A[1] <= k + k) {
        ans = 0;
        for(int i = 1; i <= n; i++) ans += W[i];
    }
    printf("%d\n", ans);
    for(int i = 0; i <= n + 2; i++) A[i] = B[i] = W[i] = InL[i] = InR[i] = 0;
    M.clear();
}

int main(){
    int T = read();
    while(T--) doit();
    return 0;
}