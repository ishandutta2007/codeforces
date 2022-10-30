#include <bits/stdc++.h>

typedef long long ll;

int N; ll M;
int a[55];
ll k[55];

int main()
{
    k[1] = 1ll;
    for (int i = 2; i < 51; i++) k[i] = k[i-1] * ll(i);
    scanf("%d%lld", &N, &M);
    int s = 0, e = N-1;
    for (int i = 0; i < N; i++) {
        if (M > (1ll<<ll(N-i-2))) {
            M -= (1ll<<ll(N-i-2));
            a[e--] = i+1;
        }
        else a[s++] = i+1;
    }
    for (int i = 0; i < N; i++) printf("%d%c", a[i], " \n"[i == N-1]);
}