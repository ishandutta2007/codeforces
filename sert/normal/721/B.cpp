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

void ret(string s) {
    cout << s;
    exit(0);
}

int n, a[N];
int kol, k, len;
char s[N];

int main() {
    init();
    scanf("%d %d\n", &n, &k);
    for (int i = 0; i < n; i++) {
        gets(s);
        a[strlen(s)]++;
    }
    gets(s);
    len = strlen(s);

    for (int i = 0; i < len; i++)
        kol += a[i];

    cout << (kol + 1) + kol / k * 5 << " " << (kol + a[len]) + (kol + a[len] - 1) / k * 5;



    return 0;
}