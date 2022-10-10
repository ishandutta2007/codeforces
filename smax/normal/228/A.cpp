#include <bits/stdc++.h>
using namespace std;

int main() {
    set<int> shoes;
    for (int i=0; i<4; i++) {
        int n;
        cin >> n;
        shoes.insert(n);
    }
    cout << (shoes.size() < 4 ? 4 - shoes.size() : 0) << endl;
    
    return 0;
}