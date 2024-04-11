#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int a, ta, b, tb;
    cin >> a >> ta >> b >> tb;
    int h, m;
    scanf("%d:%d", &h, &m);
    m += 60*h;
    
    auto cnt = [&](int l, int r) -> int {
        return (r - 300)/b - (l == 300 ? -1 : (l - 1 - 300)/b);
    };
    cout << cnt(max(60*5, m - tb + 1), min(m + ta - 1, 24*60 - 1)) << '\n';
}