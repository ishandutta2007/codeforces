#include <bits/stdc++.h>

#define MAXA 200000

using namespace std;

vector<int> a;
vector<int> aleft(MAXA + 1, 20000000);
vector<int> arigh(MAXA + 1, -1);
vector<int> col(MAXA + 1);
vector<int> siz(MAXA + 1, 0);
vector<vector<int>> clic;
int cur;
int n;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    for (int i = 1; i <= MAXA; i++) {
        col[i] = i;
    }
    cin >> n >> cur;
    a.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        siz[a[i]]++;
        aleft[a[i]] = min(aleft[a[i]], i);
        arigh[a[i]] = max(arigh[a[i]], i);
    }
    cur = a[0];
    a.push_back(0);
    int cli = 0;
    clic.push_back(vector<int>(1, siz[a[0]]));
    for (int i = 0; i < n; i++) {
        if (col[a[i]] == cur) {
            if (i == arigh[cur]) {
                cur = a[i + 1];
                cli++;
                clic.push_back(vector<int>(1, siz[a[i + 1]]));
            }
            continue;
        }
        //cout << i << " " << arigh[cur] << " " << cur << " " << col[a[i]] << endl;
        clic[cli].push_back(siz[a[i]]);
        col[a[i]] = cur;
        arigh[cur] = max(arigh[cur], arigh[a[i]]);
    }
    int ans = 0;
    //cout << cli << endl;
    for (int i = 0; i < cli; i++) {
        sort(clic[i].begin(), clic[i].end());
        for (int j = 0; j < clic[i].size() - 1; j++)
            ans += clic[i][j];
    }
    cout << ans << '\n';
    return 0;
}