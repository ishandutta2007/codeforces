#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, ret = 0, numCops = 0;
    cin >> n;
    for (int i=0; i<n; i++) {
        int j;
        cin >> j;
        if (j == -1 && numCops == 0)
            ret++;
        else if (j == -1 && numCops > 0)
            numCops--;
        else
            numCops += j;
    }
    cout << ret << endl;
    
    return 0;
}