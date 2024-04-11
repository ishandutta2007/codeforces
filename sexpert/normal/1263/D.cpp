#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 2e5 + 10;
int rep[MAXN], comps;

int find(int u) {
    return rep[u] == -1 ? u : rep[u] = find(rep[u]);
}

void join(int u, int v) {
    u = find(u), v = find(v);
    if(u == v)
        return;
    rep[v] = u;
    comps--;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    fill(rep, rep + MAXN, -1);
    int n;
    cin >> n;
    comps = n;
    vector<int> v(n);
    for(int i = 0; i < n; i++) {
        string s;
        cin >> s;
        int msk = 0;
        for(auto c : s)
            msk |= (1 << (c - 'a'));
        v[i] = msk;
    }
    for(int c = 0; c < 26; c++) {
        vector<int> jo;
        for(int i = 0; i < n; i++)
            if(v[i] & (1 << c))
                jo.push_back(i);
        for(int i = 1; i < jo.size(); i++)
            join(jo[i], jo[i - 1]);
    }
    cout << comps << '\n';
}