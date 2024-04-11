#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e9;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    vector<int> ret{1};
    while (ret.back() <= MAX / 3)
        ret.push_back(ret.back() * 3);
    
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        
        if (n > (int) ret.size()) {
            cout << "NO\n";
        } else {
            cout << "YES\n";
            for (int i=0; i<n; i++)
                cout << ret[i] << " ";
            cout << "\n";
        }
    }
    
    return 0;
}