#include <bits/stdc++.h>
using namespace std;
int n, c, l, r, tme;
int p[100], t[100];
int main() {
    //freopen("a.in", "r", stdin);
    scanf("%d %d\n", &n, &c);
    for (int i = 0; i < n; i++) scanf("%d", p + i);
    for (int i = 0; i < n; i++) scanf("%d", t + i);
    tme = 0;
    for (int i = 0; i < n; i++) {
        tme += t[i];
        l += max(0, p[i] - tme * c);
    }
    tme = 0;
    for (int i = n - 1; i >= 0; i--) {
        tme += t[i];
        r += max(0, p[i] - tme * c);
    }
    if (l == r)
        cout << "Tie\n";
    else if (l < r)
        cout << "Radewoosh\n";
    else
        cout << "Limak";
}