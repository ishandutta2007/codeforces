#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, t, c, count = 0, ret = 0;
    cin >> n >> t >> c;
    for (int i=0; i<n; i++) {
        int a;
        cin >> a;
        if (a > t) {
            if (count >= c)
                ret += count - c + 1;
            count = 0;
        } else
            count++;
    }
    if (count >= c)
        ret += count - c + 1;
    
    cout << ret << endl;
    
    return 0;
}