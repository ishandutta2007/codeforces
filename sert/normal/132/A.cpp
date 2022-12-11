#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll md = 1e9 + 7;
typedef long double ld;
const int N = 1e6 + 34;

int n, a[N], b[N];
int st, fn;

int rev(int x) {
    int res = 0;
    for (int i = 0; i < 8; i++) {
        res = res * 2 + x % 2;
        x /= 2;
    }
    return res;
}

int main() {
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);

    string s;
    getline(cin, s);
    for (int i = 0; i < s.length(); i++)
        b[i] = rev(s[i]);
    //reverse(s.begin(), s.end());
    //vector <int> v;
    int pr = 0, cur;
    for (int i = 0; i < s.length(); i++) {
        cout << ((i ? b[i - 1] : 0) - b[i] + 256) % 256 << "\n";
    }


    return 0;
}