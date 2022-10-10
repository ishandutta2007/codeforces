#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    
    int ret = 0;
    while (n > 0) {
        ret++;
        n--;
        if (ret % m == 0)
            n++;
    }
    
    cout << ret << endl;
    
    return 0;
}