#include<bits/stdc++.h>
using namespace std;

int main() {
    bitset <300> v;
    v.reset();
    v['a'] = v['e'] = v['i'] = v['o'] = v['u'] = 1;
    multiset <char> ms;
    set <char> ss;
    string s;
    cin >> s;
    for(int i = 0; i < s.length(); i ++) {
        if(v[s[i]]) {
            putchar(s[i]);
            ms.clear();
            ss.clear();
        }
        else {
            ms.insert(s[i]);
            ss.insert(s[i]);
            if(ms.size() >= 3 && ss.size() >= 2) {
                putchar(' ');
                ms.clear(), ss.clear();
                ms.insert(s[i]), ss.insert(s[i]);
            }
            putchar(s[i]);
        }
    }
    putchar('\n');
}