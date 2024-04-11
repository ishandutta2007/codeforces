#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n; vector<int> ans;
    scanf("%d", &n);
    for (int i = max(n - 150, 1); i <= n; i++) {
        char s[15];
        sprintf(s, "%d", i);
        int dsum = 0;
        for (int x = 0; s[x]; x++) {
            dsum += s[x] - '0';
        }
        if (i + dsum == n) {
            ans.push_back(i);
        }
    }
    printf("%d\n", (int)ans.size());
    for (int i = 0; i < ans.size(); i++) printf("%d\n", ans[i]);
    return 0;
}