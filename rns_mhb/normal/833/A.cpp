#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int T;
int a, b;
set<int> s;

void init() {
    for (int i = 1; i <= 1000000; i ++) {
        ll x = 1ll * i * i * i;
        s.insert(x);
    }
}

int main() {
    init();
    scanf("%d", &T);
    while (T --) {
        scanf("%d %d", &a, &b);
        bool ans = 1;
        if (1ll * a * a % b != 0) ans = 0;
        if (1ll * b * b % a != 0) ans = 0;
        if (s.find(1ll * a * b) == s.end()) ans = 0;
        if (ans) puts("Yes");
        else puts("No");
    }
}