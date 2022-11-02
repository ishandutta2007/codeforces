#include <bits/stdc++.h>
#define sz(x) (int((x).size()))
#define pb push_back
#define eb emplace_back
#define all(x) (x).begin(), (x).end()
template<typename T> bool domax(T &a, T b) { return (b > a ? (a = b, true) : false); }
template<typename T> bool domin(T &a, T b) { return (b < a ? (a = b, true) : false); }
typedef long long ll;

const int maxn = 500*1000+5;

int n, c;
std::vector<int> s[maxn];
std::vector<std::pair<int,int>> v;

void die() {
    printf("-1\n");
    exit(0);
}

int main() {
    scanf("%d%d", &n, &c);
    for (int i = 0; i < n; i++) {
        int l;
        scanf("%d", &l);
        s[i].resize(l);
        for (int j = 0; j < l; j++) {
            scanf("%d", &s[i][j]);
            s[i][j]--;
        }
    }
    for (int i = 0; i+1 < n; i++) {
        int diff = -1;
        for (int j = 0; j < sz(s[i]) && j < sz(s[i+1]); j++) {
            if (s[i][j] != s[i+1][j]) {
                diff = j;
                break;
            }
        }
        if (diff == -1) {
            if (sz(s[i+1]) < sz(s[i])) die();
        } else if (s[i][diff] != s[i+1][diff]) {
            int a = s[i][diff], b = s[i+1][diff];
            if (a < b) v.eb(c-b, c-a);
            else {
                v.eb(c-b, c);
                v.eb(0, c-a);
            }
        }
    }
    std::sort(all(v));
    int last = 0;
    for (auto &x : v) {
        if (last < x.first) {
            printf("%d\n", last);
            return 0;
        }
        domax(last, x.second);
    }
    if (last < c) printf("%d\n", last);
    else printf("-1\n");
}