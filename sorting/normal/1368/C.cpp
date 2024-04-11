#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<pair<int, int>> cells;

    cells.push_back({0, 0});
    for(int i = 1; i <= n + 1; ++i){
        cells.push_back({i, i - 1});
        cells.push_back({i - 1, i});
        cells.push_back({i, i});
    }

    cout << cells.size() << "\n";
    for(auto p: cells)
        cout << p.first << " " << p.second << "\n";
}