#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int N;
LL A, B;
int X[101010], Y[101010];

int main(){
    scanf("%d", &N);
    for (int i=1; i<=N; i++) scanf("%d", &X[i]);
    for (int i=1; i<=N; i++) scanf("%d", &Y[i]);

    sort(X+1, X+N+1, greater<int>());
    sort(Y+1, Y+N+1, greater<int>());
    for (int a=1, b=1; a <= N || b <= N; ){
        if (a > N) b++;
        else if (b > N) A += X[a++];
        else {
            if (X[a] > Y[b]) A += X[a++];
            else b++;
        }

        if (b > N) a++;
        else if (a > N) B += Y[b++];
        else {
            if (X[a] < Y[b]) B += Y[b++];
            else a++;
        }
    }
    printf("%I64d\n", A-B);
    return 0;
}