#include <string>
#include <fstream>;
#include <cstdio>
#include <iostream>

using namespace std;

string s, ans = "0";
int p1, p2;

int main() {
    cin >> s;
    for (char ch = '0'; ch <= '9'; ch += 2)
        for (int i = 0; i < s.length(); i++)
            if (s[i] == ch) {
                swap(s[i], s[s.length() - 1]);
                ans = max(ans, s);
                swap(s[i], s[s.length() - 1]);
                break;
            }
    for (char ch = '0'; ch <= '9'; ch += 2)
        for (int i = s.length() - 1; i >= 0; i--)
            if (s[i] == ch) {
                swap(s[i], s[s.length() - 1]);
                ans = max(ans, s);
                swap(s[i], s[s.length() - 1]);
                break;
            }
    if (ans == "0")
        cout << "-1";
    else
        cout << ans;
}