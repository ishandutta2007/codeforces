#include <bits/stdc++.h>
using namespace std;

template <class T> bool chkmin(T &a, T b) { return a > b ? a = b, 1 : 0; }
template <class T> bool chkmax(T &a, T b) { return a < b ? a = b, 1 : 0; }
const int inf = 1e9 + 7;
int n;
string s;
char ch;

int main() {
    scanf("%d", &n);
    int mn = -inf, mx = inf;
    while (n --) {
        int x;
        cin >> s >> x >> ch;
        if (s == ">=" && ch == 'Y' || s == "<" && ch == 'N') chkmax(mn, x);
        else if (s == ">" && ch == 'Y' || s == "<=" && ch == 'N') chkmax(mn, x + 1);
        else if (s == "<" && ch == 'Y' || s == ">=" && ch == 'N') chkmin(mx, x - 1);
        else chkmin(mx, x);
    }
    if (mn <= mx) printf("%d\n", mn);
    else puts("Impossible");
    return 0;
}