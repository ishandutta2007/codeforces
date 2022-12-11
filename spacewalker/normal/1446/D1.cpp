#include <bits/stdc++.h>

using namespace std;
constexpr int OFFSET = 200010;

int firstPos[2 * OFFSET + 1];

int main() {
    int n; scanf("%d", &n);
    vector<int> arr(n); for (int i = 0; i < n; ++i) scanf("%d", &arr[i]);
    for (int &v : arr) --v;
    vector<int> freq(n); for (int v : arr) ++freq[v];
    int king = 0;
    for (int i = 1; i < n; ++i) if (freq[i] > freq[king]) king = i;
    int MAXV = min(n - 1, 100);
    int ans = 0;
    for (int i = 0; i <= MAXV; ++i) {
        if (i == king) continue;
        vector<int> takeArr(n + 1);
        for (int j = 0; j < n; ++j)
            takeArr[j+1] = (arr[j] == i ? 1 : (arr[j] == king ? -1 : 0));
        for (int j = 1; j <= n; ++j) takeArr[j] += takeArr[j-1];
        memset(firstPos, -1, sizeof firstPos);
        for (int j = 0; j <= n; ++j) {
            if (firstPos[takeArr[j] + OFFSET] == -1) firstPos[takeArr[j] + OFFSET] = j;
            else ans = max(ans, j - firstPos[takeArr[j] + OFFSET]);
        }
    }
    printf("%d\n", ans);
}