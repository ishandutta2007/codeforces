#include <bits/stdc++.h>

#define ff first
#define ss second

using namespace std;

typedef long long ll;
typedef long double ld;
const int N = 512;

string s, ss;

string my_insert(int pos, char ch) {
    string res;
    if (pos == 0) res += ch;
    for (int i = 0; i < s.length(); i++) {
        res += s[i];
        if (pos == i + 1)
            res += ch;
    }
    return res;
}

bool is_pal(string s) {
    for (int i = 0; i < s.length() / 2; i++)
        if (s[i] != s[s.length() - i - 1])
            return false;
    return true;
}

int main() {
	// freopen("a.in", "r", stdin);
	// freopen("a.out", "w", stdout);

    cin >> s;
    for (int i = 0; i <= s.length(); i++)
        for (char ch = 'a'; ch <= 'z'; ch++) {
            ss = my_insert(i, ch);
            if (is_pal(ss)) {
                cout << ss;
                return 0;
            }
        }

    cout << "NA";
    
    //return 0;
}