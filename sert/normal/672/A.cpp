#include <bits/stdc++.h>
using namespace std;
const int N = 190;
typedef long long ll;

int x, a, b, n;
string s;

string its(int x) {
    string res;
    while (x > 0) {
        res += char('0' + x % 10);
        x /= 10;
    }
    reverse(res.begin(), res.end());
    return res;
}

int main() {
    //freopen("a.in", "r", stdin);

    for (int i = 1; i < 1000; i++)
        s += its(i);
    cin >> x;
    cout << s[x - 1];

    return 0;
}