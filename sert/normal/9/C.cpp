#include <cstdio>
#include <algorithm>
#include <iostream>
#include <set>
#include <cstring>
#include <string>
#include <vector>

using namespace std;

typedef long long ll;
const ll N = 134;

string s, n;
ll k, p;

int main() {

    ///freopen("a.in", "r", stdin);

    cin >> n;
    s = "0";
    for (int i = 1; true; i++) {
        //cerr << s << "\n";
        p = s.length() - 1;
        while (s[p] == '1') {
            p--;
            if (p == -1)
                break;
        }
        for (int j = p + 1; j < s.length(); j++)
            s[j] = '0';
        if (p == -1) s = "1" + s;
        else s[p] = '1';
        if (s.length() > n.length() || (s.length() == n.length() && s > n)) {
            cout << i - 1;
            return 0;
        }
    }

    return 0;
}