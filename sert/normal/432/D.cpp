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

int z[N], a[N];

void cnt_z(string s) {
    int n = s.length();
    z[0] = n;
    s.push_back('!');
    int l = 0, r = 0;
    for (int i = 1; i < n; i++) {
        z[i] = min(max(r - i, 0), z[i - l]);
        while (s[z[i]] == s[i + z[i]])
            z[i]++;
        if (i + z[i] > r) {
            r = i + z[i];
            l = i;
        }
    }
}

int main() {
    init();
    string s;
    cin >> s;
    cnt_z(s);

    int n = s.length();
    for (int i = 0; i < n; i++)
        a[z[i]]++;

    vector <pair<int, int> > v;

    int pr = n + 1, ans = 0;
    for (int i = n; i >= 1; i--) {
        if (z[n - i] == i) {
            for (int j = pr - 1; j >= i; j--)
                ans += a[j];
            pr = i;
            v.push_back(make_pair(i, ans));
        }
    }
    reverse(v.begin(), v.end());

    cout << v.size() << "\n";
    for (pair<int, int> q: v) {
        cout << q.first << " " << q.second << "\n";
    }



    return 0;
}