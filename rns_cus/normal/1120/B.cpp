#include <bits/stdc++.h>
using namespace std;

#define N 100100

int n;
char s[N], t[N];
long long ans, a[N], b[N];

int main() {
    scanf("%d %s %s", &n, s, t);
    for (int i = 0; i < n; i ++) a[i] = s[i], b[i] = t[i];
    for (int i = 0; i < n; i += 2) {
        ans += a[i] - b[i];
        ans -= a[i+1] - b[i+1];
    }
    if (ans) return puts("-1"), 0;
    vector <int> vec, tmp;
    for (int i = 0; i < n - 1; i ++) {
        ans += abs(a[i] - b[i]);
        if (vec.size() >= 100000) {
            a[i+1] += b[i] - a[i];
            continue;
        }
        tmp.clear();
        while (a[i] < b[i]) tmp.push_back(i + 1), a[i] ++, a[i+1] ++;
        while (a[i] > b[i]) tmp.push_back(-i - 1), a[i] --, a[i+1] --;
        for (int j = i + 1; ; j ++) {
            if (j >= n) assert(0);
            if ('0' <= a[j] && a[j] <= '9') break;
            while (a[j] < '0') tmp.push_back(j + 1), a[j] ++, a[j+1] ++, ans ++;
            while (a[j] > '9') tmp.push_back(-j - 1), a[j] --, a[j+1] --, ans ++;
        }
        for (int k = tmp.size() - 1; k >= 0; k --) vec.push_back(tmp[k]);

    }
    if (vec.size() >= 100000) vec.resize(100000);
    printf("%lld\n", ans);
    for (int i = 0; i < vec.size(); i ++) printf("%d %d\n", abs(vec[i]), vec[i] / abs(vec[i]));

    return 0;
}