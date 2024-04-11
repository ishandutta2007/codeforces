#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, v;
    cin >> n >> v;
    
    int pos = 1, ret = min(v, n - 1);
    while (n - pos > v)
        ret += ++pos;
    
    cout << ret << endl;
    
    return 0;
}