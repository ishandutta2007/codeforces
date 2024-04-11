#include <cstdio>
#include <queue>
#include <vector>
#include <algorithm>

const int inf = 999999999;

int N, K;
int a[205];
int ans = -inf;

int f(int l, int r) {
    std::priority_queue<int> q;
    for (int i = 0; i < l; i++) q.push(a[i]);
    for (int i = r; i < N; i++) q.push(a[i]);

    std::vector<int> v;
    for (int i = l; i < r; i++) v.push_back(a[i]);
    std::sort(v.begin(), v.end());
    
    int k = 0;
    for (int i = 0; i < r-l; i++) {
        if (!q.empty() && q.top() > v[i] && k < K) {
            v[i] = q.top();
            q.pop();
            k++;
        }
    }

    int ret = 0;
    for (int i = 0; i < r-l; i++)
        ret += v[i];
    return ret;
}

int main()
{
    scanf("%d%d", &N, &K);
    for (int i = 0; i < N; i++) scanf("%d", &a[i]);
    for (int l = 0; l < N; l++) for (int r = l+1; r <= N; r++)
        ans = std::max(ans, f(l, r));
    printf("%d\n", ans);
}