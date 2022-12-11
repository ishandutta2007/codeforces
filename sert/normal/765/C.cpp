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
    set <char> s;
    cin >> code;
    for (char ch: code) {
        s.insert(ch);
    }
    for (char ch = 'b'; ch <= 'z'; ch++) {
        if (s.find(ch) != s.end() && s.find(ch - 1) == s.end()) {
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
    if ((a % k && b < k) || a < k) {
        cout << "-1\n";
        return;
    }
    cout << a / k + b / k;
}

int main() {
    init();

    solveC();

    return 0;
}