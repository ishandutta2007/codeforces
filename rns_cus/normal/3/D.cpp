#include <bits/stdc++.h>
using namespace std;

#define N 100100

char s[N];

typedef long long ll;


int main() {
    scanf("%s", s);
    int n = strlen(s);
    int cnt = 0;
    ll ans = 0;
    typedef pair <int, int> pii;
    set <pii> S;
    for (int i = 0; i < n; i ++) {
        if (s[i] == '(') cnt ++;
        else if (s[i] == ')') cnt --;
        else {
            int x, y;
            scanf("%d %d", &x, &y);
            ans += y; cnt --;
            s[i] = ')';
            S.insert(pii(x - y, i));
        }
        while (cnt < 0 && !S.empty()) {
            auto it = S.begin();
            ans += it -> first;
            cnt += 2, s[it->second] = '(';
            S.erase(it);
        }
        if (cnt < 0) break;
    }
    if (cnt) puts("-1");
    else printf("%I64d\n%s\n", ans, s);

    return 0;
}