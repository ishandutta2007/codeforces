#include <bits/stdc++.h>
using namespace std;
const int N = 1000005;
char s[N] , t[N];
int n , m;
int cnt[10];
string res;
char p[N] , q[N];

string h[11];

int main() {
    scanf("%s%s" , s , t);
    n = strlen(s);
    m = strlen(t);
    for (int i = 0 ; i < n ; ++ i) {
        ++ cnt[s[i] - '0'];
    }

    if (n == 2 && cnt[0] == 1 && cnt[1] == 1) {
        puts("0");
        return 0;
    }

    int x = -1 , len;
    for (int i = 1 ; i <= n ; ++ i) {
        len = 1;
        if (i > 9) ++ len;
        if (i > 99) ++ len;
        if (i > 999) ++ len;
        if (i > 9999) ++ len;
        if (i > 99999) ++ len;
        if (i > 999999) ++ len;
        if (i + len == n) {
            x = i;
            break;
        }
    }

    int u = n - 1 , v = x;
    while (v) {
        q[u --] = v % 10 + '0';
        -- cnt[v % 10];
        v /= 10;
    }

    bool flag = 0;
    for (int i = 0 ; i < m ; ++ i) {
        -- cnt[t[i] - '0'];
        if (cnt[t[i] - '0'] < 0) {
            flag = 1;
        }
    }
    if (!flag && x >= m) {

        for (int i = 0 ; i < 10 ; ++ i) {
            h[i] += ('0' + i);
        }
        h[10] = t;
        int pos = 10;
        for (int i = 9 ; i >= 0 ; -- i) {
            if (h[i] + h[i + 1] > h[i + 1] + h[i]) {
                swap(h[i] , h[i + 1]);
                pos = i;
            } else {
                break;
            }
        }
        static int wtf[11];
        for (int i = 0 ; i <= 10 ; ++ i) {
            if (i == pos) {
                wtf[i] = 1;
            } else {
                wtf[i] = cnt[h[i][0] - '0'];
            }
        }

        int b = 0;
        for (int i = 0 ; i <= 10 ; ++ i) {
            if (wtf[i] && h[i][0] != '0') {
                wtf[i] --;
                for (auto c : h[i]) {
                    q[b ++] = c;
                }
                break;
            }
        }
        if (b > 0) {
            for (int i = 0 ; i <= 10 ; ++ i) {
                while (wtf[i]) {
                    wtf[i] --;
                    for (auto c : h[i]) {
                        q[b ++] = c;
                    }
                }
            }
            assert(strlen(q) == n);
            if (res.empty()) {
                res = q;
            } else {
                res = min(res , (string)q);
            }
        }

        for (int i = 0 ; i <= 10 ; ++ i) {
            if (i == pos) {
                wtf[i] = 1;
            } else {
                wtf[i] = cnt[h[i][0] - '0'];
            }
        }

        b = 0;
        for (int i = 0 ; i <= 10 ; ++ i) {
            if (i != pos && wtf[i] && h[i][0] != '0') {
                wtf[i] --;
                for (auto c : h[i]) {
                    q[b ++] = c;
                }
                break;
            }
        }
        if (b > 0) {
            for (int i = 0 ; i <= 10 ; ++ i) {
                while (wtf[i]) {
                    wtf[i] --;
                    for (auto c : h[i]) {
                        q[b ++] = c;
                    }
                }
            }
            assert(strlen(q) == n);
            if (res.empty()) {
                res = q;
            } else {
                res = min(res , (string)q);
            }
        }
    }
    for (int i = 0 ; i < len ; ++ i) {
        res.pop_back();
    }
    cout << res << endl;
}