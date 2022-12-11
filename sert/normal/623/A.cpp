#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int N = 502;

int n, m, v1, v2;
bool u[N][N];
vector <int> vv;
string s;
int c[N];

void dfs(int v, char ch) {
    if (c[v] == 2)
        return;
    if (c[v] == 1) {
        if (ch != s[v] && s[v] != 'd') {
            cout << "No";
            exit(0);
        }
        return;
    }
    c[v] = 1;
    vv.push_back(v);
    s[v] = ch;
    for (int i = 0; i < n; i++)
        if (!u[v][i] && v != i)
            dfs(i, (ch == 'a' ? 'c' : 'a'));
    c[v] = 2;
}

vector <pair<int, int> > e;

int main() {
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> v1 >> v2;
        v1--;
        v2--;
        e.push_back(make_pair(v1, v2));
        u[v1][v2] = u[v2][v1] = true;
    }

    for (int i = 0; i < n; i++)
        s += "d";

    bool fnd = false;
    for (int i = 0; i < n; i++)
    if (s[i] == 'd') {
        vv.clear();
        dfs(i, 'a');
        if (vv.size() > 1) {
            if (fnd) {
                cout << "No";
                return 0;
            }
            fnd = true;
        } else {
            s[vv.back()] = 'b';
        }
    }

    for (pair<int, int> pi: e) {
        if ((s[pi.first] == 'a' && s[pi.second] == 'c') || (s[pi.first] == 'c' && s[pi.second] == 'a')) {
            cout << "No";
            return 0;
        }
    }

    cout << "Yes\n" << s;



    return 0;
}