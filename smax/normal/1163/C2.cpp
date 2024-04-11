#include <bits/stdc++.h>
using namespace std;

int x[1000], y[1000];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n;
    cin >> n;
    for (int i=0; i<n; i++)
        cin >> x[i] >> y[i];

    long long ret = 0, numLines = 0;
    map<pair<int, int>, set<long long>> mp;
    for (int i=0; i<n; i++)
        for (int j=i+1; j<n; j++) {
            int a = y[j] - y[i], b = x[j] - x[i];
            int d = __gcd(a, b);
            a /= d, b /= d;
            if (a < 0 || (a == 0 && b < 0))
                a = -a, b = -b;

            long long c = (long long) a * x[i] - (long long) b * y[i];
            if (!mp[{a, b}].count(c)) {
                ret += numLines - mp[{a, b}].size();
                numLines++;
                mp[{a, b}].insert(c);
            }
        }

    cout << ret << "\n";

    return 0;
}