#include <bits/stdc++.h>
using namespace std;
void init() {
#if __GNUG__ == 4 && __GNUC_MINOR__ == 9 ///my GNU version is 4.9.3
    freopen("a.in", "r", stdin);
    ///freopen("a.out", "w", stdout);
#endif
}
typedef long long ll;
const int N = (int)1e6 + 34;
int n, k, ans, a[N];
int main() {
    init();

    int n;
    string s;
    cin >> n >> s;
    int bal = 0;
    int len = 0;
    int maxlen = 0, kol = 0;
    
    s.push_back('_'); n++;

    for (int i = 0; i < n; i++) {
        if (len > 0 && (s[i] < 'a' || s[i] > 'z') && (s[i] < 'A' || s[i] > 'Z')) {
            if (bal == 0) maxlen = max(maxlen, len);
            if (bal > 0) kol++;
            len = 0;
        }
        if (('a' <= s[i] && s[i] <= 'z') || ('A' <= s[i] && s[i] <= 'Z')) len++;
        if (s[i] == '(') bal++;
        if (s[i] == ')') bal--;
    }

    cout << maxlen << " " << kol;

    return 0;
}