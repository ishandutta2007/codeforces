#include <cstdio>

typedef long long ll;

int T;
ll N, k, d, e;
ll a, b, c;

bool check() {
    return (0 <= a && 0 <= b && 0 <= c && a+b+c == k &&
        a <= N/3 && b <= N/3 && c <= N/3);
}

int main()
{
    scanf("%d", &T);
    for (int t = 0; t < T; t++) {
        scanf("%I64d%I64d%I64d%I64d", &N, &k, &d, &e);
        
        if (N % 3) { printf("no\n"); continue; }
        a = (k-d-d-e)/3; b = a+d; c = a+d+e;
        if (check()) { printf("yes\n"); continue; }
        a = (k-d-d+e)/3; b = a+d; c = a+d-e;
        if (check()) { printf("yes\n"); continue; }
        a = (k+d+d-e)/3; b = a-d; c = a-d+e;
        if (check()) { printf("yes\n"); continue; }
        a = (k+d+d+e)/3; b = a-d; c = a-d-e;
        if (check()) { printf("yes\n"); continue; }
        printf("no\n");
    }
}