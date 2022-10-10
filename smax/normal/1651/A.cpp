#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        
        /*
        vector<int> matches(1 << n);
        iota(matches.begin(), matches.end(), 1);
        while (matches.size() > 1) {
            vector<int> nmatches;
            for (int i=0; i<(int)matches.size(); i+=2) {
                int x = matches[i], y = matches[i+1];
                if ((x + y) % 2)
                    nmatches.push_back(min(x, y));
                else
                    nmatches.push_back(max(x, y));
            }
            matches.swap(nmatches);
        }
        cout << matches[0] << "\n";
        */
        
        cout << (1 << n) - 1 << "\n";
    }
    
    return 0;
}