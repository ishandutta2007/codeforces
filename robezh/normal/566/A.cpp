#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> P;
const int M = (int)8e5 + 50, B = 26, N = (int)1e5 + 50;


struct Trie {
    int nxt[M][B];
    int sz[M];
    vector<int> nums[2][M];
    int cnt;

    void init() {
        memset(nxt, -1, sizeof(nxt));
        cnt = 1;
    }

    void add(string &str, int i, int tp) {
        int cur = 0;
        for(char c : str) {
            sz[cur]++;
            if(nxt[cur][c - 'a'] == -1) nxt[cur][c - 'a'] = cnt++;
            cur = nxt[cur][c-'a'];
        }
        sz[cur]++;
        nums[tp][cur].push_back(i);
    }
} trie;

int n;
string nam[N], pse[N];
map<int, int> mp[2];
int res = 0;
vector<P> ps;

P dfs(int v, int st1, int st2, int d) {
    int sz1 = 0, sz2 = 0;
    for(int j = 0; j < 26; j++) {
        if(trie.nxt[v][j] == -1) continue;
        P p = dfs(trie.nxt[v][j], st1 + sz1, st2 + sz2, d + 1);
        sz1 += p.first, sz2 += p.second;
    }
    for(int x : trie.nums[0][v]) mp[0][st1 + (sz1++)] = x;
    for(int x : trie.nums[1][v]) mp[1][st2 + (sz2++)] = x;
    auto it1 = mp[0].lower_bound(st1);
    auto it2 = mp[1].lower_bound(st2);
    while(it1 != mp[0].end() && it2 != mp[1].end() && it1 -> first < st1 + sz1 && it2 -> first < st2 + sz2) {
        ps.push_back({it1 -> second, it2 -> second});
        res += d;
        it1 = mp[0].erase(it1);
        it2 = mp[1].erase(it2);
    }
    return {sz1, sz2};
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    trie.init();
    for(int i = 0; i < n; i++) {
        cin >> nam[i];
        trie.add(nam[i], i, 0);
    }
    for(int i = 0; i < n; i++) {
        cin >> pse[i];
        trie.add(pse[i], i, 1);
    }
    dfs(0, 0, 0, 0);
    cout << res << "\n";
    for(auto p : ps) cout << p.first + 1 << " " << p.second + 1 << "\n";

}