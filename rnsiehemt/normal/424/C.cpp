#include <cstdio>

int N;
int ans;
int d[1000005];

int main()
{
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        int p; scanf("%d", &p);
        ans ^= p;
    }
    //printf("%d\n", ans);
    for (int i = 2; i <= N; i++) {
        int a = ((N+1) / i) % 2;
        int b = (N+1) % i;
        //printf("%d %d %d\n", i, a, b);
        if (a == 0) {
            d[0]++;
            d[b]--;
        }
        else if (a == 1) {
            d[b]++;
            d[i]--;
        }
    }
    
    int z = 0;
    for (int i = 0; i < 1000001; i++) {
        z += d[i];
        if (z%2) ans ^= i;
    }

    printf("%d\n", ans);
}