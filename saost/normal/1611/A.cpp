#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
int t;
string s;

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> t;
    while (t--) {
        cin >> s;
        if (s.back() % 2 == 0) cout << 0 << '\n';
        else if (s[0] % 2 == 0) cout << 1 << '\n';
        else {
            bool ok = false;
            for(char c : s) if (c % 2 == 0) { cout << 2 << '\n'; ok = true; break; }
            if (!ok) cout << -1 << '\n';
        }
    }
}