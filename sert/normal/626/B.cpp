#include <bits/stdc++.h>
using namespace std;
void ret(string s) {
    cout << s;
    exit(0);
}
string s;
int n, r, g, b;
int main() {
    cin >> n >> s;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'G') g++;
        if (s[i] == 'B') b++;
        if (s[i] == 'R') r++;
    }
    if (r > 0 && g > 0 && b > 0) ret("BGR");
    if (r > 1 && g > 1) ret("BGR");
    if (r > 1 && b > 1) ret("BGR");
    if (b > 1 && g > 1) ret("BGR");
    if (r == 0 && g == 0) ret("B");
    if (r == 0 && b == 0) ret("G");
    if (b == 0 && g == 0) ret("R");
    if (r == 1 && g == 1) ret("B");
    if (r == 1 && b == 1) ret("G");
    if (b == 1 && g == 1) ret("R");
    if (r > 1) ret("BG");
    if (g > 1) ret("BR");
    if (b > 1) ret("GR");
}