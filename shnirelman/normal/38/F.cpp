#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int N = 1e5 + 13;
const int INF = 1e9;

struct Res {
    int res1, res2;
    bool win;
    bool calc;
    
    Res() : calc(false), res1(0), res2(0), win(false) {};
};

vector<pii> g[N];
int a[N];
Res dp[N];

void dfs(int v) {
    if(dp[v].calc) 
        return;
    
    //cout << v << endl;
    
    for(auto [u, w] : g[v]) {
        dfs(u);
        
        
        
        Res res = dp[u];
        res.res2 += w;
        swap(res.res1, res.res2);
        res.win = !res.win;
    //cout << v << ' ' << u << ' ' << w << ' ' << res.res1 << ' ' << res.res2 << ' ' 
    //    << res.calc << endl;
        if(!dp[v].calc) {
            dp[v] = res;
            continue;
        }
    
        if(res.win && !dp[v].win) {
            dp[v] = res;
            continue;
        }
        
        if(!res.win && dp[v].win)
            continue;
        
        if(res.res1 > dp[v].res1) {
            dp[v] = res;
            continue;
        }
        
        if(res.res1 == dp[v].res1 && res.res2 < dp[v].res2) {
            dp[v] = res;
            continue;
        }
    }
    
    if(!dp[v].calc) {
        //cout << "not calc " << v << endl;
        dp[v].res1 = dp[v].res2 = 0;
        dp[v].win = false;
        dp[v].calc = true;
    }
    
    //cout << v << ' ' << dp[v].res1 << ' ' << dp[v].res2 << ' ' << dp[v].win << endl;
}

int main() {
//    ios_base::sync_with_stdio(0);
//    cin.tie(0);
    int n;
    cin >> n;
    
    vector<string> s(n);
    map<string, pii> mp;
    for(int i = 0; i < n; i++) {
        cin >> s[i];
        set<string> st;
        for(int j = 0; j < s[i].size(); j++) {
            string t = "";
            for(int l = j; l < s[i].size(); l++) {
                t += s[i][l];
                st.insert(t);
            }
        }
        
        for(auto x : st)
            mp[x].f++;
    }
    
    mp[""] = {0, 0}; 
    int cur = 0;
    for(auto it = mp.begin(); it != mp.end(); it++) {
        it->s.s = cur;
        //cout << it->f << ' ' << cur << endl;
        a[cur] = 0;
        int mx = 0;
        for(auto c : it->f) {
            a[cur] += c - 'a' + 1;
            mx = max(mx, c - 'a' + 1);
        }
        
        a[cur] = a[cur] * mx + it->s.f;
        
        //cout << it->f << ' ' << a[cur] << endl;
        
        cur++;
    }
    
    
    
    for(auto [t, p] : mp) {
        int v = p.s;
        for(char c = 'a'; c <= 'z'; c++) {
            string t1 = t + c;
            if(mp.count(t1)) {
                int u = mp[t1].s;
                g[v].emplace_back(u, a[u]);
                //cout << v << ' ' << u << ' ' << a[u] << endl;
            }
            
            
            t1 = c + t;
            if(mp.count(t1)) {
                int u = mp[t1].s;
                g[v].emplace_back(u, a[u]);
                //cout << v << ' ' << u << ' ' << a[u] << endl;
            }
            
        }
    }
    
    int v = mp[""].s;
    
    dfs(v);
    
    cout << (dp[v].win ? "First" : "Second") << endl;
    cout << dp[v].res1 << ' ' << dp[v].res2 << endl;
    
    
}