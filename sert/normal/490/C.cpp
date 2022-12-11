#include <bits/stdc++.h>

#define ff first
#define ss second

using namespace std;

typedef long long ll;
typedef long double ld;
const int N = 1e6 + 34;
const int M = 1003;

string s;
ll n, a, b, p[N], sf[N], st[N];

int main() {
    // freopen("a.in", "r", stdin);
    // freopen("a.out", "w", stdout);

    cin >> s >> a >> b;
    n = s.length();
    for (int i = 0; i < n; i++) {
        p[i] = ((i ? p[i - 1] : 0) * 10 + s[i] - '0') % a;
    }
    st[0] = 1;
    for (int i = 1; i <= n; i++)
        st[i] = (st[i - 1] * 10) % b;

    for (int i = n - 1; i >= 0; i--)
        sf[i] = (sf[i + 1] + st[n - i - 1] * (s[i] - '0')) % b;

    // for (int i = 0; i < n; i++) cout << p[i] << " "; cout << "\n";
    // for (int i = 0; i < n; i++) cout << sf[i] << " "; cout << "\n";

    for (int i = 1; i < n; i++)
        if (p[i - 1] == 0 && sf[i] == 0 && s[0] != '0' && s[i] != '0') {
            printf("YES\n");
            for (int j = 0; j < i; j++) printf("%c", s[j]);
            printf("\n");
            for (int j = i; j < n; j++) printf("%c", s[j]);
            printf("\n");
            return 0;
        }

    cout << "NO\n";

    //return 0;
}