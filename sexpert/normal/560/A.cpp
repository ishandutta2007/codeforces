#include <bits/stdc++.h>
using namespace std;

int main() {
    bool b = false;
    int n;
    cin >> n;
    while(n--) {
        int x;
        cin >> x;
        if(x == 1)
            b = true;
    }
    cout << (b ? -1 : 1) << endl;
}