#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int
main()
{
    ios_base::sync_with_stdio(false);
    string s;
    cin >> s;
    int a, b;
    cin >> a >> b;
    int n = int(s.length());
    vector< int > beg(n), end(n);
    for (int i = 0, sum = 0; i < n; ++i) {
        sum = (sum * 10 + s[i] - '0') % a;
        beg[i] = sum;
    }
    for (int i = n - 1, sum = 0, mod = 1; i >= 0; --i) {
        sum = (sum + mod * (s[i] - '0')) % b;
        mod = (mod * 10) % b;
        end[i] = sum;
    }
    int ind = -1;
    for (int i = 0; i < n - 1 && ind == -1; ++i) {
        if (beg[i] == 0 && end[i + 1] == 0 && s[i + 1] != '0') {
            ind = i + 1;
        }
    }
    if (ind == -1) {
        cout << "NO\n";
    } else {
        cout << "YES\n";
        cout << s.substr(0, ind) << '\n';
        cout << s.substr(ind) << '\n';
    }
    return 0;
}