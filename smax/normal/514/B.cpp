#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int n, x0, y0;
    unordered_set<double> slopes;
    cin >> n >> x0 >> y0;
    for (int i=0; i<n; i++) {
        int x, y;
        cin >> x >> y;
        if (x == x0)
            slopes.insert(DBL_MAX);
        else
            slopes.insert((double) (y - y0) / (x - x0));
    }
    
    cout << slopes.size() << endl;
    
    return 0;
}