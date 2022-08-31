#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

#define debug(x) cerr << #x << " = " << x << ", line = " << __LINE__ << endl

void setIO() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

const int MX = 100005;

string s, t;
int nxt[MX][26];

int solve() {
    int n = s.length();
    memset(nxt[n], 0, sizeof nxt[0]);
    for (int i = n - 1; i >= 0; i--) {
        memcpy(nxt[i], nxt[i+1], sizeof nxt[i]);
        nxt[i][s[i]-'a'] = i + 1;
        // for (int j = 0; j < 26; j++) {
        //     cout << nxt[i][j] << " ";
        // }
        // cout << endl;
    }

    int r = 1;
    int p = 0;
    for (int i = 0; i < t.length(); i++) {
        int c = t[i] - 'a';
        if (nxt[0][c] == 0) return -1;
        p = nxt[p][c];
        if (p == 0) { i--; r++; }
        // cout << "p = " << p << endl;
    }

    return r;
}

int main() {
    setIO();
    int tt; cin>>tt;
    while(tt--) {
        cin>>s>>t;
        cout<<solve()<<"\n";
    }
    
    return 0;
}