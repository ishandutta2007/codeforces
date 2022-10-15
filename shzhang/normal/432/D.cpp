#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <utility>

using namespace std;

char s[100005];
int Z[100005];
int n;
int len[100005];

int main()
{
    scanf("%s", s + 1);
    n = strlen(s + 1);
    Z[1] = n;
    int x = 1, y = 1;
    for (int i = 2; i <= n; i++) {
        Z[i] = max(0, min(Z[i-x+1], y-i+1));
        while (i + Z[i] <= n && s[i+Z[i]] == s[Z[i]+1]) {
            x = i; y = i + Z[i]; Z[i]++;
        }
        len[Z[i]]++;
    }
    for (int i = n; i >= 1; i--) {
        len[i] += len[i+1];
    }
    vector<pair<int, int> > ans;
    for (int i = n; i >= 1; i--) {
        if (i + Z[i] > n) {
            ans.push_back(make_pair(n - i + 1, len[n - i + 1] + 1));
        }
    }
    printf("%d\n", (int)ans.size());
    for (int i = 0; i < ans.size(); i++) {
        printf("%d %d\n", ans[i].first, ans[i].second);
    }
    return 0;
}