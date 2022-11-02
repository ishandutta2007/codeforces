#include <bits/stdc++.h>
using namespace std;

#define N 100100

int n;
char a[N], b[N];

int main() {
    int T;
    scanf("%d", &T);
    while (T --) {
        scanf("%d %s %s", &n, a + 1, b + 1);
        vector <int> ans;
        for (int i = n, j = 1, c = 0; i >= 1; i --) {
            int x = a[j] ^ c;
            if (x == b[i]) ans.push_back(1);
            ans.push_back(i);
            if (c) j -= i - 1;
            else j += i - 1;
            c ^= 1;
        }
        int sz = ans.size();
        printf("%d", sz);
        for (int i = 0; i < sz; i ++) printf(" %d", ans[i]); puts("");
    }

    return 0;
}