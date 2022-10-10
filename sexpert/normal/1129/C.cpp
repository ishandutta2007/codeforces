#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll MOD = 1e9 + 7;
ll tot = 0;

struct xtrie {
    int type;
    int dp;
    xtrie *left, *right, *back;

    xtrie(xtrie *b = nullptr, int t = -1) {
        type = t;
        back = b;
        left = nullptr;
        right = nullptr;
        dp = ((t == -1) ? 1 : 0);
    }

    void add(string &s, int pos = 0) {
        if(pos == s.size())
            return;
        if(s[pos] == '0') {
            if(!left) {
                left = new xtrie(this, 0);
                left->calc();
            }
            left->add(s, pos + 1);
        }
        else {
            if(!right) {
                right = new xtrie(this, 1);
                right->calc();
            }
            right->add(s, pos + 1);
        }
    }

    void calc() {
        int up = 0;
        string s = "";
        xtrie *pos = this;
        ll d = 0;
        while(pos->type != -1 && up <= 4) {
            s += ('0' + pos->type);
            pos = pos->back;
            up++;
            if(up < 4)
                d = (d + (ll)pos->dp)%MOD;
            if(up == 4) {
                if(s != "0011" && s != "0101" && s != "1110" && s != "1111")
                    d = (d + (ll)pos->dp)%MOD;
            }
        }
        dp = d;
        tot = (tot + (ll)dp)%MOD;
    }
};

int main() {
    int n;
    cin >> n;
    string s;
    for(int i = 0; i < n; i++) {
        char c;
        cin >> c;
        s += c;
    }
    reverse(s.begin(), s.end());
    xtrie trie;
    for(int p = n - 1; p >= 0; p--) {
        string t = s.substr(p);
        trie.add(t);
        cout << tot << endl;
    }
}