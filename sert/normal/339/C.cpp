#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 1e6 + 34;
int n, m, v1, v2;
string s;
int a[N], len;
vector <int> v;

void go(int my, int ot, int st, int ls) {
    if (st == m) {
        cout << "YES\n";
        for (int i = 0; i < v.size(); i++)
            cout << v[i] << " ";
        exit(0);
    }
    v.push_back(-1);
    for (int i = 0; i < len; i++)
        if (a[i] != ls && my + a[i] > ot) {
            v.back() = a[i];
            go(ot, my + a[i], st + 1, a[i]);
        }
    v.pop_back();
}

int main() {
    // freopen("a.in", "r", stdin);
    // freopen("a.out", "w", stdout);
    
    cin >> s;
    cin >> m;
    for (int i = 0; i < s.length(); i++)
        if (s[i] == '1')
            a[len++] = i + 1;

    go(0, 0, 0, -1);

    cout << "NO\n";

    return 0;
}