#include <bits/stdc++.h>
using namespace std;

const int N = (int)1e5 + 50;

int n;
string str;
int q;

struct BIT {
    //BIT is 0-indexed!!!
    int bit[N];
    void add(int x, int val) {
        for(int i = x; i < n; i |= i + 1) bit[i] += val;
    }

    int get(int x) {
        int res = 0;
        for(int i = x; i >= 0; i = (i & (i + 1)) - 1)  res += bit[i];
        return res;
    }

    int get(int l, int r) {
        return get(r) - get(l - 1);
    }
} bit[4][11][10];

int ch[256];

void change(int i, char c, int val) {
    for(int k = 1; k <= 10; k++) {
        bit[ch[c]][k][i%k].add(i, val);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ch['A'] = 0, ch['T'] = 1, ch['G'] = 2, ch['C'] = 3;

    cin >> str;
    n = str.length();
    for(int i = 0; i < n; i++) change(i, str[i], 1);
    int q;
    cin >> q;
    while(q--) {
        int type;
        cin >> type;
        if(type == 1) {
            int i; cin >> i; i--;
            char c; cin >> c;
            change(i, str[i], -1);
            str[i] = c;
            change(i, str[i], 1);
        }
        else {
            int l, r; cin >> l >> r; l--, r--;
            string qs; cin >> qs;
            int k = qs.length();
            int res = 0;
            for(int i = 0; i < k; i++) res += bit[ch[qs[i]]][k][(l+i)%k].get(l, r);
            cout << res << endl;
        }
    }
}