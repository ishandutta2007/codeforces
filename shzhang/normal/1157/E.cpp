#include <cstdio>

using namespace std;

int n;
int a[200005];
int remaining[200005];
int replacement[200005];
bool has[200005];

int c[200005];

int find(int a)
{
    if (replacement[a] == a) return a;
    return replacement[a] = find(replacement[a]);
}

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", a + i);
    for (int i = 1; i <= n; i++) {
        int val;
        scanf("%d", &val);
        remaining[val]++;
        replacement[val] = val;
        has[val] = true;
    }
    if (!has[n-1]) replacement[n-1] = 0;

    for (int i = n - 2; i >= 0; i--) if (!has[i]) replacement[i] = i + 1;
    for (int i = 1; i <= n; i++) {
        int wanted = (n - a[i]) % n;
        int findwanted = find(wanted);
        c[i] = (a[i] + findwanted) % n;
        remaining[findwanted]--;
        if (remaining[findwanted] == 0) replacement[findwanted] = find((findwanted + 1) % n);
    }

    for (int i = 1; i <= n; i++) printf("%d ", c[i]);

    return 0;
}