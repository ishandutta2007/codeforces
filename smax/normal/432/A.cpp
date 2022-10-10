#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k, students = 0;
    cin >> n >> k;
    for (int i=0; i<n; i++) {
        int y;
        cin >> y;
        if (y + k <= 5)
            students++;
    }
    
    cout << students / 3 << endl;
    
    return 0;
}