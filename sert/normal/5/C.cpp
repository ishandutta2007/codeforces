#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll md = 1e9 + 7;
typedef long double ld;
const int N = 1e6 + 34;

char s[N];
int d[N * 2], lst[N * 2];
pair <int, int> r[N * 2];
int len, rl;
int a[N * 2], n;
int sum, mx, kol = 1;

int main() {
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);

    gets(s);
    n = strlen(s);
    r[rl++] = make_pair(-1, -1);
    for (int i = 0; i < n; i++)
        if (s[i] == '(') {
            a[len++] = i;
            r[rl++] = make_pair(-1, i);
        } else {
            if (len == 0)
                r[rl++] = make_pair(-1, -1);
            else {
                len--;
                while (r[rl - 1].second >= a[len])
                    rl--;
                r[rl++] = make_pair(i - a[len] + 1, a[len]);
            }
        }

    r[rl++] = make_pair(-1, -1);
    //for (int i = 0; i < rl; i++) cerr << r[i].first << " "; cerr << "\n";

    for (int i = 0; i < rl; i++)
        if (r[i].first > 0)
            sum += r[i].first;
        else if (sum > 0) {
            if (sum == mx) kol++;
            if (sum > mx) {
                mx = sum;
                kol = 1;
            }
            sum = 0;
        }

    cout << mx << " " << kol;

    return 0;
}