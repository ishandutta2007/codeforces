#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 1e5 + 10;
int cnt[MAXN], fixpt[MAXN], unf[MAXN], col[MAXN], b[MAXN], str[MAXN], n, x, y, freecol;
vector<int> pos[MAXN];

void solve() {
    cin >> n >> x >> y;
    for(int i = 0; i <= n + 5; i++) {
        cnt[i] = fixpt[i] = unf[i] = col[i] = b[i] = str[i] = 0;
        pos[i].clear();
    }
    for(int i = 1; i <= n; i++) {
        cin >> b[i];
        cnt[b[i]]++;
        pos[b[i]].push_back(i);
    }

    int used = 0;   
    for(int i = 1; i <= n + 1; i++) {
        if(cnt[i] == 0)
            freecol = i;
        if(used == x)
            continue;
        while(cnt[i] > 0 && min(cnt[i], n - x - cnt[i]) < min(cnt[i] - 1, n - x - cnt[i] + 1) && used < x) {
            used++;
            cnt[i]--;
            fixpt[i]++;
        } 
    }
    for(int i = 1; i <= n + 1; i++) {
        if(used == x)
            break;
        while(cnt[i] > 0 && min(cnt[i], n - x - cnt[i]) == min(cnt[i] - 1, n - x - cnt[i] + 1) && used < x) {
            used++;
            cnt[i]--;
            fixpt[i]++;
        }
    }
    for(int i = 1; i <= n + 1; i++) {
        if(used == x)
            break;
        while(cnt[i] > 0 && used < x) {
            used++;
            cnt[i]--;
            fixpt[i]++;
        }
    }
    assert(used == x);
    int su = 0;
    for(int i = 1; i <= n + 1; i++) {
        //cout << cnt[i] << " ";
        su += min(cnt[i], n - x - cnt[i]);
    }
    //cout << '\n';
    if(su < y - x) {
        cout << "NO\n";
        return;
    }
    for(int i = 1; i <= n + 1; i++) {
        while(fixpt[i]--) {
            int p = pos[i].back(); pos[i].pop_back();
            col[p] = i;
        }
    }
    int reqd = y - x;
    used = 0;
    vector<int> cols(n + 1);
    iota(cols.begin(), cols.end(), 1);
    vector<int> ord;
    for(auto c : cols) {
        str[c] = ord.size();
        for(int i = 0; i < min(cnt[c], n - x - cnt[c]); i++)
            ord.push_back(pos[c][i]);
        if(used == reqd)
            continue;
        for(int i = 0; i < min(cnt[c], n - x - cnt[c]); i++) {
            unf[c]++;
            used++;
            if(used == reqd)
                break;
        }
    }
    int m = ord.size();
    int ptr = 0;
    for(int cl = 0; cl <= n; cl++) {
        int c = cols[cl];
        for(int i = 0; i < unf[c]; i++) {
            col[ord[(ptr + m / 2) % m]] = c;
            ptr++;
        }
    }
    for(int i = 1; i <= n; i++)
        if(col[i] == 0)
            col[i] = freecol;
    cout << "YES\n";
    for(int i = 1; i <= n; i++)
        cout << col[i] << " ";
    cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--)
        solve();
}