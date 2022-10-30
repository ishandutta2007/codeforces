#include <bits/stdc++.h>

int N, K;
int a[7];
double ans;

void f(int k, double p) {
    if (k == K) {
        double c = 0.0;
        for (int i = 0; i < N; i++) for (int j = i+1; j < N; j++)
            if (a[j] < a[i]) c++;
        ans += p*c;
    }
    else {
        double aoeu= N*(N+1)/2;
        for (int i = 0; i < N; i++) for (int j = i; j < N; j++) {
            std::reverse(a+i, a+j+1);
            f(k+1, p/aoeu);
            std::reverse(a+i, a+j+1);
        }
    }
}

int main()
{
    scanf("%d%d", &N, &K);
    if (N > 6) return 0;
    for (int i = 0; i < N; i++) scanf("%d", &a[i]);

    f(0, 1.0);
    printf("%.10lf\n", ans);
}