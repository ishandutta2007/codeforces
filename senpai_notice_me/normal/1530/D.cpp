#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdint>
#include <cstddef>
#include <queue>

using namespace std;

constexpr size_t MAXN = (size_t) 2e5 + 5;

int a[MAXN];
int b[MAXN];
bool used[MAXN];

int use_on[MAXN];

int main()
{
    int T; scanf("%d", &T);
    while (T--) {
        int n; scanf("%d", &n);
        for (int i = 1; i <= n; i++) {
            scanf("%d", a + i);
            b[i] = 0;
            used[i] = false;
        }

        int ans = 0;

        for (int i = 1; i <= n; i++) {
            if (!used[a[i]]) {
                ans++;
                b[i] = a[i];

                use_on[b[i]] = i;

                used[b[i]] = true;
            }
        }

        vector<int> unused;
        for (int i = 1; i <= n; i++) {
            if (!used[i]) {
                unused.push_back(i);
            }
        }

        vector<int> same;

        for (int i = 1; i <= n; i++) {
            if (b[i] == 0) {
                b[i] = unused.back();

                use_on[b[i]] = i;

                unused.pop_back();
                if (b[i] == i) {
                    same.push_back(i);
                }
            }
        }

        if (same.size() == 1) {
            int x = same[0];

            while (b[x] == x) {
                int y = use_on[a[x]];

                swap(b[x], b[y]);
                x = y;
            }
        } else {
            for (int i = 0; i + 1 < (int) same.size(); i++) {
                swap(b[same[i]], b[same[i + 1]]);
            }
        }

        printf("%d\n", ans);
        for (int i = 1; i <= n; i++) {
            printf("%d%c", b[i], " \n"[i == n]);
        }
    }

    return 0;
}