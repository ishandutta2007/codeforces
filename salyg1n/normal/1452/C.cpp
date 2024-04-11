#include<iostream>
#include<vector>
#include<algorithm>

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

int main() {
        int t;
        cin >> t;
        for (int i = 0; i < t; ++i) {
                string s;
                cin >> s;
                int a = 0, b = 0, ans = 0;
                for (auto c : s) {
                        if (c == '(')
                                a++;
                        if (c == '[')
                                b++;
                        if (c == ')' && a > 0) {
                                ans++;
                                a--;
                        }
                        if (c == ']' && b > 0) {
                                ans++;
                                b--;
                        }
                }
                cout << ans << "\n";
        }
        return 0;
}