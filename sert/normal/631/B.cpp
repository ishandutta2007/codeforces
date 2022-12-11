#include <bits/stdc++.h>
using namespace std;
const int N = 5012;
int rt[N], rc[N], ct[N], cc[N];
int n, m, k, c, t, num;
int main() {
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 1; i <= k; i++) {
        scanf("%d%d%d", &t, &num, &c); num--;
        if (t == 1) {
            rt[num] = i;
            rc[num] = c;
        } else {
            ct[num] = i;
            cc[num] = c;
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            if (rt[i] > ct[j])
                cout << rc[i] << " ";
            else
                cout << cc[j] << " ";
        cout << "\n";
    }
}