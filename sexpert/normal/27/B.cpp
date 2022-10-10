#include <bits/stdc++.h>
using namespace std;

vector<int> adj[55];
int t, seen[55];

bool conn(int s) {
    seen[s] = 1;
    if(s == t)
        return true;
    for(auto v : adj[s]) {
        if(!seen[v] && conn(v))
            return true;
    }
    return false;
}

int main() {
    set<pair<int, int>> st;
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        for(int j = i + 1; j <= n; j++) {
            st.insert({i, j});
        }
    }
    for(int t = 0; t < n*(n - 1)/2 - 1; t++) {
        int x, y;
        cin >> x >> y;
        adj[y].push_back(x);
        st.erase({min(x, y), max(x, y)});
    }
    auto p = *st.begin();
    int s = p.first;
    t = p.second;
    if(conn(s))
        cout << t << " " << s << endl;
    else
        cout << s << " " << t << endl;
}