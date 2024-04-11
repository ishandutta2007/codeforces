#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> v;
    int n, g;
    cin >> n;
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if(i == 0)
            g = x;
        else
            g = __gcd(g, x);
        v.push_back(x);
    }
    int m = *max_element(v.begin(), v.end());
    cout << (((m/g - v.size()) % 2) ? "Alice\n" : "Bob\n");
}