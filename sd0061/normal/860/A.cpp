#include <bits/stdc++.h>
using namespace std;

const int N = 3005;

int n;
char str[N];

bool isv(char c) {
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

vector<string> v;

int main() {
    scanf("%s" , str);
    set<char> h;
    string s;
    for (int i = 0 ; str[i] ; ++ i) {
        h.insert(str[i]);
        if (!isv(str[i])) {
            if (s.size() >= 2 && !isv(s[s.size() - 2]) &&
                !isv(s[s.size() - 1]) && (
                    s[s.size() - 2] != s[s.size() - 1] ||
                    s[s.size() - 2] != str[i] ||
                    s[s.size() - 1] != str[i] )) {
                v.push_back(s);
                s.clear();
                h.clear();
                h.insert(str[i]);
            }
        }
        s += str[i];
    }
    if (s.size()) v.push_back(s);
    for (auto w : v) cout << w + " ";
    puts("");
}