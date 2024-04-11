#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int ask(string s) {
    cout << s << '\n';
    cout.flush();
    int x;
    cin >> x;
    if(x <= 0)
        exit(0);
    return x;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    string cur;
    for(int i = 0; i < 300; i++)
        cur += 'b';
    int x = ask(cur);
    cur = "a";
    for(int i = 0; i < 299; i++)
        cur += 'a';
    int y = ask(cur), len = 600 - x - y;
    y -= (300 - len);
    cur = cur.substr(0, len);
    if(y == 0)
        ask(cur);
    string nxt;
    for(int i = 0; i < len; i++) {
        nxt = cur;
        nxt[i] = 'b';
        int na = ask(nxt);
        if(na < y) {
            y = na;
            cur = nxt;
        }
    }
}