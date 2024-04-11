#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
typedef long long LL;

int main() {
    string s , t;
    cin >> s >> t;
    if (s == t) {
        cout << -1 << endl;
    } else {
        cout << max(s.size() , t.size()) << endl;
    }

}