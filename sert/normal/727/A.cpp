#include <bits/stdc++.h>
using namespace std;
void init() {
#if __GNUG__ == 4 && __GNUC_MINOR__ == 9 ///my GNU version is 4.9.3
    freopen("a.in", "r", stdin);
    ///freopen("a.out", "w", stdout);
#endif
}
typedef long long ll;
typedef long double ld;

const int N = 1e6 + 34;

int a, b;
vector <int> c;

void go(int x) {
    if (x < a) return;
    if (x == a) {
        cout << "YES\n";
        c.push_back(x);
        reverse(c.begin(), c.end());
        cout << c.size() << "\n";
        for (int i = 0; i < c.size(); i++)
            cout << c[i] << " ";
        exit(0);
    }

    c.push_back(x);
    if (x % 10 == 1) {
        go(x / 10);
    }

    if (x % 2 == 0) {
        go(x / 2);
    }
    c.pop_back();
}

int main() {
    //init();
    cin >> a >> b;
    go(b);
    cout << "NO";

    return 0;
}