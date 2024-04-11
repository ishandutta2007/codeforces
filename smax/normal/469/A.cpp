#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    set<int> levels;
    for (int i=0; i<2; i++) {
        int p;
        cin >> p;
        for (int j=0; j<p; j++) {
            int a;
            cin >> a;
            levels.insert(a);
        }
    }
    if (levels.size() == n)
        cout << "I become the guy." << endl;
    else
        cout << "Oh, my keyboard!" << endl;
    
    return 0;
}