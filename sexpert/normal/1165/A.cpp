

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
int main() {
    int n, x, y;
    cin  >> n >> x >> y;
    string s;
    cin >> s;
    reverse(s.begin(), s.end());
    int ans = 0;
    for(int i = 0; i < y; i++) ans += (s[i] == '1');
    ans += (s[y] == '0');
    for(int i = y + 1; i < x; i++) ans += (s[i] == '1');
    cout << ans << endl;
}