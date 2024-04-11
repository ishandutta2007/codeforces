#include <bits/stdc++.h>
using namespace std;

#define N 300300

int n, sum[N];
char s[N];

typedef tuple <int, int, int> ti;
ti tp;

void update(int x, int l, int r) {
    if (get<0>(tp) < x) tp = ti(x, l, r);
}

int main() {
    scanf("%d %s", &n, s + 1);
    int X = 0;
    for (int i = 1; i <= n; i ++) {
        sum[i] = sum[i-1];
        if (s[i] == '(') sum[i] ++;
        else sum[i] --;
        X = min(X, sum[i]);
    }
    if (sum[n] != 0) {
        puts("0");
        puts("1 1");
        return 0;
    }
    vector <int> vec;
    vec.push_back(0);
    for (int i = 1; i <= n; i ++) {
        if (sum[i] == X) vec.push_back(i);
    }
    int sz = vec.size(), c = sz - 1;
    tp = ti(c, 1, 1);
    vec.push_back(n), sz ++;
    for (int i = 1; i < sz; i ++) {
        int l, r;
        for (l = vec[i-1] + 1; l < vec[i]; l ++) if (s[l] == '(') break;
        for (r = vec[i]; r > vec[i-1]; r --) if (s[r] == ')') break;
        if (l < r) {
            int cnt = 0;
            for (int j = l; j < r; j ++) if (sum[j] == X + 1) cnt ++;
            update(cnt, l, r);
            l = vec[i-1], r = vec[i];
            vector <int> tmp;
            tmp.push_back(l);
            for (int j = l + 1; j < r; j ++) if (sum[j] == X + 1) tmp.push_back(j);
            tmp.push_back(r);
            int ssz = tmp.size();
            for (int j = 1; j < ssz; j ++) {
                int l, r;
                for (l = tmp[j-1] + 1; l < tmp[j]; l ++) if (s[l] == '(') break;
                for (r = tmp[j]; r > tmp[j-1]; r --) if (s[r] == ')') break;
                if (l < r) {
                    int cnt = 0;
                    for (int j = l; j < r; j ++) if (sum[j] == X + 2) cnt ++;
                    update(c + cnt, l, r);
                }
            }
        }
    }

    if (X + 1 <= 0) {
        int l, r;
        for (l = 1; ; l ++) if (sum[l] < X + 1) break;
        for (r = n; ; r --) if (sum[r] < X + 1) break; r ++;
        if (l < r) {
            int cnt = 0;
            for (int i = 1; i < l; i ++) if (sum[i] == X + 1) cnt ++;
            for (int i = r; i <= n; i ++) if (sum[i] == X + 1) cnt ++;
            update(cnt, l, r);
        }

    }

    if (X + 2 <= 0) {
        int l, r;
        for (l = 1; ; l ++) if (sum[l] < X + 2) break;
        for (r = n; ; r --) if (sum[r] < X + 2) break; r ++;
        if (l < r) {
            int cnt = 0;
            for (int i = 1; i < l; i ++) if (sum[i] == X + 2) cnt ++;
            for (int i = r; i <= n; i ++) if (sum[i] == X + 2) cnt ++;
            update(c + cnt, l, r);
        }
    }
    printf("%d\n%d %d\n", get<0>(tp), get<1>(tp), get<2>(tp));

    return 0;
}