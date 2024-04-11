#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, h[30];
    unordered_map<int, int> a;
    cin >> n;
    for (int i=0; i<n; i++) {
        int x;
        cin >> h[i] >> x;
        if (a.find(x) != a.end())
            a[x]++;
        else
            a.insert(make_pair(x, 1));
    }
    
    int ret = 0;
    for (int i=0; i<n; i++)
        if (a.find(h[i]) != a.end())
            ret += a[h[i]];
    
    cout << ret << endl;
    
    return 0;
}