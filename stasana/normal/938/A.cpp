#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <map>
#include <set>

using namespace std;

typedef long double ld;
typedef long long ll;

bool check(char ch) {
    return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' || ch == 'y';
}

int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    cout << s[0];
    for (int i = 1; i < s.length() ; ++i) {
        if (check(s[i]) && check(s[i - 1])) {
            continue;
        }
        cout << s[i];
    }
    return 0;
}