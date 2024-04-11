#include <bits/stdc++.h>
using namespace std;
#define TASKNAME "dynasties"
void init() {
#ifdef MOI_KOD_IDEALEN
    freopen("a.in", "r", stdin);
    ///freopen("a.out", "w", stdout);
#else
    //freopen(TASKNAME".in", "r", stdin);
    //freopen(TASKNAME".out", "w", stdout);
#endif
}
typedef long long ll;
typedef long double ld;

void solveA() {
    int n;
    cin >> n;
    cout << (n % 2 ? "contest" : "home");
}

void solveB() {
    string code;
    map <char, int> m;
    cin >> code;
    for (char ch: code) {
        if (m.find(ch) == m.end())
            m[ch] = m.size() - 1;
    }
    for (char ch = 'a'; ch <= 'z'; ch++) {
        if (m.find(ch) != m.end() && m[ch] != ch - 'a') {
            cout << "NO\n";
            return;
        }
    }

    cout << "YES\n";
}

void solveC() {
    int k, a, b;
    cin >> k >> a >> b;
    if (a < b) {
        swap(a, b);
    }
    if ((a % 11 && b < 11) || a < 11) {
        cout << "-1\n";
        return;
    }
    cout << a / 11 + b / 11;
}

int main() {
    init();

    solveB();

    return 0;
}