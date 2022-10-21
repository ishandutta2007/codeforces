#include <bits/stdc++.h>
#define pii pair<int, int>
#define fi first
#define se second
#define ll long long

using namespace std;

const int N = 100500;

int a[N], id[N];

bool cmp(int i, int j) {
    return a[i] < a[j];
}

int main() {
    int tcase;
    scanf("%d", &tcase);
    while (tcase--) {
        int n;
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) {
            scanf("%d", &a[i]);
            id[i] = i;
        }
        sort(id + 1, id + n + 1, cmp);
        printf("%d %d\n", id[1], id[n]);
    }

    return 0;
}