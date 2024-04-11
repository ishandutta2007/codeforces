#include <bits/stdc++.h>
using namespace std;

const int K = 26;

int n, k;
string s, a, b;

int per[2][4][K];
bool used[2][4][K];
bool bad[2][4];

int next(int i, int c, int type) {
    if((type != 2 && c < a[i]) || (type != 1 && c > b[i])) return -1;
    int nt = type;
    if(c > a[i]) nt |= 2;
    if(c < b[i]) nt |= 1;
    return nt;
}

void set_char(int x, int tp, int i, int c){
//    cout << "setting char " << tp << ", " << i << ", " << c << endl;
    per[x&1][tp][i] = c;
    used[x&1][tp][c] = true;
}

void fill(int x, int t){
    int cur = 0;
    for(int i = 0; i < k; i++) {
        if(per[x&1][t][i] == -1){
            while(used[x&1][t][cur]) cur++;
            set_char(x, t, i, cur);
        }
    }
}

pair<int, int> solve() {
    memset(per, -1, sizeof(per));
    memset(used, false, sizeof(used));
    memset(bad, true, sizeof(bad));
    bad[1][0] = false;
    cin >> k >> s >> a >> b;
    n = s.length();
    for(int i = 0; i < n; i++) s[i] -= 'a', a[i] -= 'a', b[i] -= 'a';

    for(int i = 0; i < n; i++) {
        int msk = (i&1);
        fill(bad[msk], bad[msk] + 4, true);
        for(int tp = 0; tp < 3; tp ++) {
            if(bad[!msk][tp]) continue;
            for(int c = 0; c < k; c++) {
                if((per[!msk][tp][s[i]] == -1 && !used[!msk][tp][c]) || (per[!msk][tp][s[i]] == c)){
                    int nxt = next(i, c, tp);
                    if(nxt == -1) continue;
                    bad[msk][nxt] = false;
                    for(int j = 0; j < k; j++) {
                        used[msk][nxt][j] = used[!msk][tp][j];
                        per[msk][nxt][j] = per[!msk][tp][j];
                    }
                    set_char(i, nxt, s[i], c);
                    if(nxt == 3) return {i, nxt};
                }
            }
        }
    }
    for(int i = 0; i < 3; i++) if(!bad[(n-1)&1][i]) return {n-1, i};
    return {-1, -1};
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie();

    int T;
    cin >> T;
    while(T--) {
        auto res = solve();
        if(res.second == -1) cout << "NO\n";
        else {
            fill(res.first, res.second);
            cout << "YES\n";
            for(int i = 0; i < k; i++) cout << (char)(per[res.first&1][res.second][i] + 'a');
            cout << "\n";
        }
    }

}