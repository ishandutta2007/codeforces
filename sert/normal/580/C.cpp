#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 1e6 + 34;

int n, m, v1, v2;
vector <int> es[N];
int term[N];

int go(int v, int num_cats, int pr) {
    if (term[v])
        num_cats++;
    else
        num_cats = 0;
    //cout << v << " " << num_cats << "\n";
    if (num_cats > m)
        return 0;
    if (es[v].size() == 1 && v != 0)
        return 1;
    int ans = 0;
    for (int i = 0; i < es[v].size(); i++)
        if (es[v][i] != pr)
            ans += go(es[v][i], num_cats, v);
    return ans;
}

int main() {
    // freopen("a.in", "r", stdin);
    // freopen("a.out", "w", stdout);
    
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> term[i];
    for (int i = 0; i < n - 1; i++) {
        cin >> v1 >> v2;
        v1--;
        v2--;
        es[v1].push_back(v2);
        es[v2].push_back(v1);
    }

    cout << go(0, 0, -1);

    return 0;
}