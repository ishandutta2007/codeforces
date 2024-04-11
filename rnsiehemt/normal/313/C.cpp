#include <cstdio>
#include <algorithm>

typedef long long ll;

int N;
ll a[2000005];
ll s[2000005];
ll ans;

int main()
{
    scanf("%d", &N);
    for (int i = 0; i < N; i++) scanf("%I64d", &a[i]);

    std::sort(a, a+N);
    std::reverse(a, a+N);
    s[0] = a[0]; for (int i = 1; i < N; i++) s[i] = s[i-1] + a[i];
    while (N) {
        ans += s[N-1];
        N /= 4;
    }

    printf("%I64d\n", ans);
}