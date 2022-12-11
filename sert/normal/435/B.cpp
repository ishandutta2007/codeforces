#include <iostream>
#include <map>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <cmath>

using namespace std;

typedef long long ll;

map <pair<string, int>, string> m;

bool cmp(const string &s1, const string &s2) {
    return (s1.size() == s2.size() ? s1 < s2 : s1.size() < s2.size());
}

string go(string n, ll k) {
    if (k == 0) return n;
    int ps, kk;
    if (m.find(make_pair(n, k)) != m.end())
        return m[make_pair(n, k)];
    string ans = n, t;
    for (int i = 1; i < n.size(); i++) {
        if (n[i] > n[i - 1]) {
            ps = i;
            kk = k;

            //cerr << n << "\n";

            while (ps > 0 && n[ps] > n[ps - 1] && kk > 0) {
                swap(n[ps], n[ps - 1]);
                ps--;
                kk--;
            }
            t = go(n, kk);
            if (cmp(ans, t))
                ans = t;
            for (int j = ps + 1; j <= i; j++)
                swap(n[j - 1], n[j]);

            //cerr << n << "\n";
        }
    }
    return m[make_pair(n, k)] = ans;
}

int main() {
    //freopen("a.in", "r", stdin);
    string n;
    ll k;
    cin >> n >> k;

    if (k >= (n.length() - 1) * n.length() / 2) {
        for (int i = 0; i < int(n.length()); i++)
            for (int j = 0; j < int(n.length()) - i - 1; j++)
                if (n[j] < n[j + 1])
                    swap(n[j], n[j + 1]);
        cout << n;
        return 0;
    }

    cout << go(n, k);

    return 0;
}