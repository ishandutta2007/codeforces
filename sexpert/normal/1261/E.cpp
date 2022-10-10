#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;

int grid[1005][1005];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> v(n);
    vector<ii> wut;
    for(int i = 0; i < n; i++) {
        cin >> v[i];
        wut.push_back({-v[i], i});
    }
    sort(wut.begin(), wut.end());
    int m = *max_element(v.begin(), v.end());
    int a = m + 1;
    cout << a << '\n';
    for(int i = 0; i < n; i++) {
        int c = -wut[i].first, j = wut[i].second;
        int p = i % a;
        while(c > 0) {
            grid[p][j] = 1;
            c--;
            p = (p + 1) % a;
        }
    }
    for(int i = 0; i < a; i++) {
        for(int j = 0; j < n; j++)
            cout << grid[i][j];
        cout << '\n';
    }
}