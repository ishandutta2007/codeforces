#include <bits/stdc++.h>

#define ff first
#define ss second
#define sl (l1 + l2 + l3)
#define sr (r1 + r2 + r3)

using namespace std;

typedef long long ll;

string int_to_str(int x) {
    if (x == 0) return "0";
    string ans;
    ans.clear();
    while (x) {
        ans = char(x % 10 + '0') + ans;
        x /= 10;
    }
    return ans;
}

bool check(string s, string k) {
    int l = 0;
    for (int i = 0; i < s.length(); i++)
        if (s[i] == k[l]) {
            l++;
            if (l == k.length())
                return true;
        }
    return false;
}

int main() {
    //freopen("a.in", "r", stdin);
    string s;
    cin >> s;
    for (int i = 0; i < 1000; i += 8)
        if (check(s, int_to_str(i))) {
            cout << "YES\n" << i << "\n";
            return 0;
        }
    cout << "NO\n";
    return 0;
}