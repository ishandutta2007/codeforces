#include <cstdio>
#include <vector>

using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    vector<int> p(n);
    for (int i = 1; i < n; i++) {
        scanf("%d", &p[i]);
        p[i]--;
    }
    vector<int> ans;
    int cur = n - 1;
    while (cur != 0) {
        ans.push_back(cur + 1);
        cur = p[cur];
    }
    printf("1");
    for (int i = (int)ans.size() - 1; i >= 0; i--)
        printf(" %d", ans[i]);
    printf("\n");
    return 0;
}