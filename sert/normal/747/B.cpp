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

const int N = 1e3 + 34;

int a[1000];

int main() {
    init();

    int n;
    string s;
    cin >> n >> s;
    for (int i = 0; i < n; i++) {
        a[s[i]]++;
    }

    if (max(max(a['G'], a['A']), max(a['C'], a['T'])) > n / 4 || n % 4) {
        cout << "===\n";
        return 0;
    }

    for (int i = 0; i < n; i++) {
        if (s[i] == '?') {
            if (a['G'] < n / 4) {s[i] = 'G'; a['G']++;}
            else if (a['C'] < n / 4) {s[i] = 'C'; a['C']++;}
            else if (a['A'] < n / 4) {s[i] = 'A'; a['A']++;}
            else if (a['T'] < n / 4) {s[i] = 'T'; a['T']++;}
        }
    }

    cout << s;

    return 0;
}