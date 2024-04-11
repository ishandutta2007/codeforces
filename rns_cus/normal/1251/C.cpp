#include <bits/stdc++.h>
using namespace std;

#define N 300100

char s[N];

int main() {
    int T;
    scanf("%d", &T);
    while (T --) {
        scanf("%s", s);
        vector <int> e, o, r;
        for (int i = 0; s[i]; i ++) if (s[i] & 1) o.push_back(s[i]); else e.push_back(s[i]);
        r.resize(e.size() + o.size());
        merge(e.begin(), e.end(), o.begin(), o.end(), r.begin());
        for (auto x : r) putchar(x); puts("");
    }

    return 0;
}