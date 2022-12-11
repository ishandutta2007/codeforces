#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll md = 1e9 + 7;
typedef long double ld;
const int N = 1e6 + 34;

char ss[N];
string s[N];
int n, mx, sp, ls, rs;
bool lf;

int main() {
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);

    while (gets(ss)) {
        s[n++] = ss;
        mx = max(mx, (int)s[n - 1].length());
    }
    for (int i = 0; i < mx + 2; i++) printf("*"); printf("\n");
    for (int i = 0; i < n; i++) {
        printf("*");
        sp = mx - (int)s[i].length();
        ls = sp / 2;
        rs = sp - ls;
        if (ls != rs && s[i].length() > 0) {
            if (lf)
                swap(ls, rs);
            lf = !lf;
        }
        for (int j = 0; j < ls; j++) printf(" ");
        printf("%s", s[i].c_str());
        for (int j = 0; j < rs; j++) printf(" ");
        printf("*\n");
    }
    for (int i = 0; i < mx + 2; i++) printf("*"); printf("\n");



    return 0;
}