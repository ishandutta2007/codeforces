#include <bits/stdc++.h>

using namespace std;
#define TASKNAME "cactus"
void init() {
#if __gnu_linux__ == 1
    assert(freopen("a.in", "r", stdin));
    //freopen("a.out", "w", stdout);
#else
    //freopen(TASKNAME".in", "r", stdin);
    //freopen(TASKNAME".out", "w", stdout);
#endif
}

typedef long long ll;
typedef long double ld;
const int N = (int)2e5 + 34;
const ll INF = (ll)1e9 + 34;
const ll md = (ll)1e9 + 7;

int main() {
    init();
    set <string> s;
    string str;
    int n;
    cin >> n;
    getline(cin, str);
    while (n--) {
        getline(cin, str);
        s.insert(str);
    }

    cout << s.size();

    return 0;
}