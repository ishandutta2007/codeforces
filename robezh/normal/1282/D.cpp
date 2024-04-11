#include <bits/stdc++.h>
using namespace std;

string rep(string s, int x) {
    string res;
    while(x--) res += s;
    return res;
}

int ask(string str) {
    cout << str << "\n";
    fflush(stdout);
    int x;
    cin >> x;
    return x;
}

int main() {
    int a = ask("a");
    if(a == 0) return 0;

    int len = a + 1;
    if(len > 300) {
        ask(rep("b", len - 1));
        return 0;
    }
    string s = rep("a", len);


    int curres = ask(s);
    if(curres == len) {
        ask(rep("b", len - 1));
        return 0;
    }


    for(int i = 0; i < len - 1; i++) {
        s[i] = 'b';
        int nxt = ask(s);
        if(nxt == 0) return 0;
        if(nxt < curres) {
            curres = nxt;
        }
        else {
            s[i] = 'a';
        }
    }
    s[len - 1] = 'b';
    ask(s);
}