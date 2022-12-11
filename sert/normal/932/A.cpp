#include <bits/stdc++.h>
using namespace std;

void init() {
#ifdef FIRE_MIND
    freopen("a.in", "r", stdin);
#else
#endif
}

int main() {
    init();
    string s;
    cin >> s;
    cout << s;
    reverse(s.begin(), s.end());
    cout << s;
    return 0;
}