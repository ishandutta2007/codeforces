#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    bool f = 0;
    cin >> n;
    while (n --) {
        string s;
        int a , b;
        cin >> s >> a >> b;
        if (a >= 2400 && a < b) {
            f = 1;
        }
    }
    puts(f ? "YES" : "NO");
}