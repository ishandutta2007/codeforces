#include <bits/stdc++.h>
using namespace std;

#define N 300300

int n, a[N], b[N];
vector <int> v1, v2;

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i ++) {
        scanf("%d %d", &a[i], &b[i]);
        if (a[i] < b[i]) v1.push_back(i);
        else v2.push_back(i);
    }
    int sz1 = v1.size(), sz2 = v2.size();
    printf("%d\n", max(sz1, sz2));
    if (sz1 < sz2) {
        sort(v2.begin(), v2.end(), [&](int i, int j) {return a[i] < a[j];});
        for (int i = 0; i < sz2; i ++) printf("%d ", v2[i]);
    }
    else {
        sort(v1.begin(), v1.end(), [&](int i, int j) {return a[i] > a[j];});
        for (int i = 0; i < sz1; i ++) printf("%d ", v1[i]);
    }

    return 0;
}