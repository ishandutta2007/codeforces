#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 1e5 + 5;

int rep[MAXN], col[MAXN], k[3];
bool eq[MAXN];

void init() {
    fill(rep, rep + MAXN, -1);
}

int find(int u) {
    return (rep[u] == -1) ? u : rep[u] = find(rep[u]);
}

void join(int u, int v) {
    u = find(u), v = find(v);
    if(u != v)
        rep[v] = u;
}

string ask(vector<int> v) {
    if(v.size() % 2)
        v.pop_back();
    if(v.empty()) return "";
    cout << "Q " << v.size()/2;
    for(auto x : v)
        cout << " " << x;
    cout << '\n';
    cout.flush();
    string res;
    cin >> res;
    if(res == "-1")
        exit(0);
    return res;
}

void test_case() {
    k[0] = k[1] = k[2] = 0;
    for(int i = 0; i < MAXN; i++) eq[i] = false;
    int n;
    cin >> n;
    if(n == -1)
        exit(0);
    init();
    vector<int> v;
    for(int i = 1; i + 1 <= n; i += 2) v.push_back(i), v.push_back(i + 1);
    string s;
    s = ask(v);
    for(int i = 0; i < s.size(); i++) {
        if(s[i] == '1')
            join(2*i + 1, 2*i + 2);
    }
    v.clear();
    for(int i = 2; i + 1 <= n; i += 2) v.push_back(i), v.push_back(i + 1);
    s = ask(v);
    for(int i = 0; i < s.size(); i++) {
        if(s[i] == '1')
            join(2*i + 2, 2*i + 3);
    }
    vector<int> red;
    red.push_back(find(1));
    for(int i = 2; i <= n; i++) {
        int u = find(i);
        if(u != red.back())
            red.push_back(u);
    }
    int m = red.size();
    v.clear();
    for(int l = 0; 4*l + 2 < m; l++) {
        v.push_back(red[4*l + 2]), v.push_back(red[4*l]);
        if(4*l + 3 < m)
            v.push_back(red[4*l + 3]), v.push_back(red[4*l + 1]);
    }
    s = ask(v);
    for(int i = 0; i < s.size(); i++) {
        if(s[i] == '1') {
            if(i % 2 == 1)
                eq[4*(i/2) + 3] = true;
            else
                eq[4*(i/2) + 2] = true;
        }
    }
    v.clear();
    for(int l = 0; 4*l + 4 < m; l++) {
        v.push_back(red[4*l + 4]), v.push_back(red[4*l + 2]);
        if(4*l + 5 < m)
            v.push_back(red[4*l + 5]), v.push_back(red[4*l + 3]);
    }
    s = ask(v);
    for(int i = 0; i < s.size(); i++) {
        if(s[i] == '1') {
            if(i % 2)
                eq[4*(i/2) + 5] = true;
            else
                eq[4*(i/2) + 4] = true;
        }
    }
    col[red[0]] = 0;
    if(m > 1)
        col[red[1]] = 1;
    for(int i = 2; i < m; i++) {
        col[red[i]] = (col[red[i - 1]] + 1) % 3;
        if((eq[i] && col[red[i]] != col[red[i - 2]]) || (!eq[i] && col[red[i]] == col[red[i - 2]]))
            col[red[i]] = (col[red[i]] + 1) % 3;
    }
    for(int i = 1; i <= n; i++) {
        col[i] = col[find(i)];
        k[col[i]]++;
    }
    cout << "A " << k[0] << " " << k[1] << " " << k[2] << '\n';
    for(int i = 1; i <= n; i++)
        if(col[i] == 0) cout << i << " ";
    cout << '\n';
    for(int i = 1; i <= n; i++)
        if(col[i] == 1) cout << i << " ";
    cout << '\n';
    for(int i = 1; i <= n; i++)
        if(col[i] == 2) cout << i << " ";
    cout << '\n';
    cout.flush();
}

int main() {
    //ios_base::sync_with_stdio(false);
    //cin.tie(0);

    int t;
    cin >> t;
    while(t--)
        test_case();
}