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

unordered_set <string> st;

int a, b, c;

int main() {
    init();

    int n, m;
    string s;
    char ss[1000];

    scanf("%d %d\n", &n, &m);

    for (int i = 0; i < n; i++) {
        gets(ss);
        s = ss;
        st.insert(s);
    }

    for (int i = 0; i < m; i++) {
        gets(ss);
        s = ss;
        if (st.find(s) != st.end())
            c++;
    }

    a = n - c;
    b = m - c;

    if (a + c % 2 > b) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }

    return 0;
}