#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 2e5 + 5;
string fi[MAXN], se[MAXN], ans[MAXN];
vector<int> adj[MAXN];
int comp[MAXN], tin[MAXN], low[MAXN], ncomps, curt;
vector<int> st;

void dfs(int s) {
    tin[s] = low[s] = ++curt;
    st.push_back(s);
    for(auto v : adj[s]) {
        if(!tin[v]) {
            dfs(v);
            low[s] = min(low[s], low[v]);
        }
        else if(!comp[v])
            low[s] = min(low[s], tin[v]);
    }
    if(low[s] == tin[s]) {
        int z;
        ncomps++;
        do {
            z = st.back(); st.pop_back();
            comp[z] = ncomps;
        } while(z != s);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        string s, t;
        cin >> s >> t;
        fi[i] = s.substr(0, 3);
        se[i] = s.substr(0, 2) + t[0];
    }
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            if(fi[i] == fi[j]) {
                adj[2*i].push_back(2*i + 1);
                adj[2*j].push_back(2*j + 1);
            }
            if(fi[i] == se[j]) {
                adj[2*i].push_back(2*j);
                adj[2*j + 1].push_back(2*i + 1);
            }
            if(se[i] == fi[j]) {
                adj[2*i + 1].push_back(2*j + 1);
                adj[2*j].push_back(2*i);
            }
            if(se[i] == se[j]) {
                adj[2*i + 1].push_back(2*j);
                adj[2*j + 1].push_back(2*i);
            }
        }
    }
    for(int i = 0; i < 2*n; i++)
        if(!comp[i])
            dfs(i);
    for(int i = 0; i < n; i++) {
        if(comp[2*i] == comp[2*i + 1]) {
            cout << "NO\n";
            return 0;
        }
        if(comp[2*i] < comp[2*i + 1])
            ans[i] = fi[i];
        if(comp[2*i] > comp[2*i + 1])
            ans[i] = se[i];
    }
    cout << "YES\n";
    for(int i = 0; i < n; i++)
        cout << ans[i] << '\n';
}