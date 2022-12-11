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

const int N = (int)1e5 + 34;

int a[N], k[N], o[N];
vector <int> v;
int p[500][N];

int main() {
    init();
    string s;
    cin >> s;
    int n = 27;
    int p1 = -1, p2 = -1;
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            if (s[i] == s[j]) {
                p1 = i;
                p2 = j;
            }

    if (p1 + 1 == p2) {
        cout << "Impossible";
        return 0;
    }

    string a[2] = {"1234567890000", "1234567890000"};

    int d = (p2 - p1 - 1) / 2;
    int c = d;
    int r = 1;

    a[r][c] = s[p1];
    for (int i = p1 + 1; i < p2; i++) {
        if (r == 1) c--; else c++;
        if (c < 0) r = c = 0;
        a[r][c] = s[i];
    }

    for (int i = 0; i < p1; i++) s.push_back(s[i]);

    for (int i = p2 + 1; i < (int)s.length(); i++) {
        if (r == 0) c++; else c--;
        if (c >= 13) {
            r = 1;
            c = 12;
        }
        a[r][c] = s[i];
    }

    cout << a[0] << "\n" << a[1] << "\n";

    return 0;
}