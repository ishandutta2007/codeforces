#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <string>
#include <cstring>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <cstdlib>
#include <ctime>

#define ff first
#define ss second

using namespace std;

typedef long long ll;
const int N = 1e3 + 7;

ll n, t, a[N];
bool cur[N], u[N];
int e[N][N], uk;
string s[N];
vector <int> q;

void dfs(int v) {
    if (u[v] || cur[v]) return;
    cur[v] = u[v] = true;
    q.push_back(a[v]);
    for (int i = 0; i < n; i++)
        if (s[v][i] == '1')
            dfs(i);
}

int main() {
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++)
        cin >> s[i];
    for (int i = 0; i < n; i++)
    if (!u[i]) {
        for (int j = 0; j < n; j++)
            cur[j] = false;
        q.clear();
        dfs(i);
        sort(q.begin(), q.end());
        uk = 0;
        for (int j = 0; j < n; j++)
            if (cur[j])
                a[j] = q[uk++];
    }
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    return 0;
}