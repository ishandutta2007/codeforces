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
const int INF = 1e9 + 34;

string s1, s;
int p, d;

int main() {
    init();

    cin >> s1;
    while (s1[p] != 'e') {
        s.push_back(s1[p++]);
    }

    p++;
    while (p < s1.length()) {
        d = d * 10 + s1[p++] - '0';
    }

    int n = s.length();

    p = 1;
    for (int i = 0; i < d; i++) {
        if (p + 1 == s.length())
            s.push_back('0');
        swap(s[p], s[p + 1]);
        p++;
    }
    if (s.back() == '.') s.pop_back();

    if (s.back() == '0' && s[s.length() - 2] == '.') {
        s.pop_back();
        s.pop_back();
    }

    cout << s;


    return 0;
}