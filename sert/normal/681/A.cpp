 #include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5000 + 34;
typedef long double ld;

int n, a, b;
string s;

int main() {
    cin >> n;
    while (cin >> s >> b >> a) {
        if (b >= 2400 && a > b) {
            cout << "YES\n";
            return 0;
        }
    }
    cout << "NO\n";
    return 0;
}