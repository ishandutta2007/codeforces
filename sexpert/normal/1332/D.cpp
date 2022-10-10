#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int s;
    cin >> s;
    int p2 = 1;
    while(p2 <= s)
        p2 *= 2;
    cout << "3 3\n";
    cout << s + p2 << " " << s << " 0\n";
    cout << p2 << " " << s + p2 << " 0\n";
    cout << "0 " << s << " " << s << '\n';
}