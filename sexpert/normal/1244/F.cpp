#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 2e5 + 100;
vector<int> adj[MAXN];
int dw[MAXN], db[MAXN];
const int INF = 1e9 + 5;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    vector<int> red;
    int ctr = 1, rot = 0;
    for(int i = 1; i < n; i++) {
        if(s[i] == s[i - 1])
            ctr++;
        else {
            red.push_back(ctr);
            ctr = 1;
        }
    }
    red.push_back(ctr);
    if(red.size() == 1) {
        cout << s << '\n';
        return 0;
    }
    if(red.size() % 2) {
        rot = red.back();
        red[0] += red.back();
        red.pop_back();
    }
    //for(auto x : red)
    //    cout << x << " ";
    //cout << endl;
    int m = *max_element(red.begin(), red.end());
    if(m == 1) {
        if(k % 2)
            cout << s.substr(1) << s[0] << '\n';
        else
            cout << s << '\n';
        return 0;
    }
    int sz = red.size();
    for(int i = 0; i < sz; i++) {
        adj[i].push_back((i + 1) % sz);
        adj[i].push_back((i + sz - 1) % sz);
    }
    queue<int> qb, qw;
    fill(db, db + MAXN, INF);
    fill(dw, dw + MAXN, INF);
    for(int i = 0; i < sz; i++) {
        if(red[i] == 1)
            continue;
        if(i % 2) {
            qb.push(i);
            db[i] = 0;
        }
        else {
            qw.push(i);
            dw[i] = 0;
        }
    }
    while(!qb.empty()) {
        int u = qb.front(); qb.pop();
        for(auto v : adj[u])
            if(db[v] == INF) {
                db[v] = db[u] + 1;
                qb.push(v);
            }
    }
    while(!qw.empty()) {
        int u = qw.front(); qw.pop();
        for(auto v : adj[u])
            if(dw[v] == INF) {
                dw[v] = dw[u] + 1;
                qw.push(v);
            }
    }
    string res;
    for(int i = 0; i < sz; i++) {
        if(red[i] > 1) {
            for(int j = 0; j < red[i]; j++)
                res += (i % 2 ? 'B' : 'W');
        }
        else {
            if(min(dw[i], db[i]) > k) {
                res += ((i + k) % 2 ? "B" : "W");
                continue;
            }
            if(dw[i] < db[i])
                res += 'W';
            else
                res += 'B';
        }
    }
    if(s[0] != 'W') {
        for(auto &c : res) {
            if(c == 'W')
                c = 'B';
            else
                c = 'W';
        }
    }
    cout << res.substr(rot) << res.substr(0, rot) << endl;
}