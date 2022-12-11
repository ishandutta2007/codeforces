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

const ll N = 1e6 + 34;

int get_code(string s) {
    int res = 0;
    for (int i = 0; i < s.length(); i++)
        res = res * 2 + (s[i] - '0') % 2;
    return res;
}
int a[N];
int n;
char c, s[100];

int main() {
    init();
    scanf("%d\n", &n);
    while (n--) {
        scanf("%c %s\n", &c, s);
        if (c == '+')
            a[get_code(s)]++;
        else if (c == '-')
            a[get_code(s)]--;
        else
            printf("%d\n", a[get_code(s)]);
    }

    return 0;
}