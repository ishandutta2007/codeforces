#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    vector<int> one, two, three;
    cin >> n;
    for (int i=1; i<=n; i++) {
        int t;
        cin >> t;
        if (t == 1)
            one.push_back(i);
        else if (t == 2)
            two.push_back(i);
        else
            three.push_back(i);
    }
    
    int w = min(one.size(), min(two.size(), three.size()));
    cout << w << endl;
    for (int i=0; i<w; i++)
        cout << one[i] << " " << two[i] << " " << three[i] << endl;
    
    return 0;
}