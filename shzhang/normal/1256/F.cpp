#include <cstdio>
#include <algorithm>

using namespace std;

int n;
int str[200005];
int sstr[200005];
int str2[200005];
int sstr2[200005];
char orig[200005];

void work(void)
{
    scanf("%d", &n);
    scanf("%s", orig + 1);
    for (int i = 1; i <= n; i++) sstr[i] = str[i] = orig[i] - 'a';
    sort(sstr + 1, sstr + n + 1);
    scanf("%s", orig + 1);
    for (int i = 1; i <= n; i++) sstr2[i] = str2[i] = orig[i] - 'a';
    sort(sstr2 + 1, sstr2 + n + 1);
    for (int i = 1; i <= n; i++) {
        if (sstr[i] != sstr2[i]) {
            printf("NO\n"); return;
        }
    }
    for (int i = 1; i < n; i++) {
        if (sstr[i] == sstr[i+1] || sstr2[i] == sstr2[i+1]) {
            printf("YES\n"); return;
        }
    }
    int inv1 = 0, inv2 = 0;
    for (int i = 1; i < n; i++) {
        for (int j = i + 1; j <= n; j++) {
            if (str[i] < str[j]) inv1++;
            if (str2[i] < str2[j]) inv2++;
        }
    }
    printf("%s\n", inv1 % 2 == inv2 % 2 ? "YES" : "NO");
}

int main()
{
    int q;
    scanf("%d", &q);
    for (int i = 1; i <= q; i++) work();
    return 0;
}