#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int N = 3e5 + 34;

int x, st;
pair<int, int> a[N];
int pr[N];
pair<int, int> ans[N];
int len;


int main() {
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        pr[i] = -1;
        scanf("%d", &a[i].first);
        a[i].second = i;
    }
    sort(a, a + n);
    for (int i = 1; i < n; i++)
        if (a[i].first == a[i - 1].first)
            pr[a[i].second] = a[i - 1].second;

    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        if (pr[i] >= st) {
            ans[len++] = make_pair(st + 1, i + 1);
            st = i + 1;
        }
    }

    if (st == 0) {
        printf("-1");
        return 0;
    }

    ans[len - 1].second = n;

    printf("%d\n", len);
    for (int i = 0; i < len; i++)
        printf("%d %d\n", ans[i].first, ans[i].second);


    return 0;
}