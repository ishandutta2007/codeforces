#include <cstdio>
#include <vector>
const int N = 1e5 + 34;
int a[N];
int sum, limit, s;
std::vector<int> ans;
int main() {
    // freopen("a.in", "r", stdin);
    // freopen("a.out", "w", stdout);
    scanf("%d%d", &sum, &limit);
    for (int i = 1; i <= limit; i *= 2)
        for (int j = i; j <= limit; j += i)
            a[j] = i;
    for (int i = 1; i <= limit; i++)
        s += a[i];
    if (s < sum) {
        printf("-1\n");
        return 0;
    }
    for (int i = limit; i > 0; i--) 
        if (sum >= a[i]) {
            sum -= a[i];
            ans.push_back(i);
        }
    printf("%d\n", ans.size());
    for (int i = 0; i < ans.size(); i++)
        printf("%d ", ans[i]);
}