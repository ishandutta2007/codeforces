#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int n, m;
    unordered_set<int> row, col;
    cin >> n >> m;
    for (int i=0; i<m; i++) {
        int x, y;
        cin >> x >> y;
        row.insert(x);
        col.insert(y);
        cout << (long long) (n - row.size()) * (long long) (n - col.size()) << " ";
    }
    
    return 0;
}