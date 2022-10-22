#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const li INF = 1e18;
const int M = 1e9 + 7;
const int N = 2e5 + 13;


/*

*/

li a[N];
int b[N];
vector<int> ts;
bool used[N];

void dfs(int v) {
    used[v] = true;
    if(b[v] != -1)
        if(!used[b[v]])
            dfs(b[v]);

    ts.push_back(v);
}

int main() {
//    ios::sync_with_stdio(0);
//    cin.tie(0);

    int n;
    cin >> n;

    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for(int i = 0; i < n; i++) {
        cin >> b[i];
        b[i] = (b[i] == -1 ? -1 : b[i] - 1);
    }

    for(int i = 0; i < n; i++) {
        if(!used[i]) {
            dfs(i);
        }
    }

    reverse(ts.begin(), ts.end());

    vector<int> p;

    li ans = 0;
    for(auto v : ts) {
        if(a[v] >= 0) {
            p.push_back(v);
            ans += a[v];
            if(b[v] != -1)
                a[b[v]] += a[v];
        }
    }



    for(int i = n - 1; i >= 0; i--) {
        int v = ts[i];

        if(a[v] < 0) {
            ans += a[v];
            p.push_back(v);
        }
    }

    cout << ans << endl;
    for(auto x : p)
        cout << x + 1 << ' ';
}