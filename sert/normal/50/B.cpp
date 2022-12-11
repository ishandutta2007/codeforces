#include <bits/stdc++.h>
using namespace std;
int main() {
    string s;
    cin >> s;
    sort(s.begin(), s.end());
    s += "!";
    long long k = 1, ans = 0;
    for (int i = 1; i < s.length(); i++) 
        if (s[i] == s[i - 1])
            k++;
        else {
            ans += k * k;
            k = 1;
        }
    cout << ans;
}