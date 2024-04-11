#include <bits/stdc++.h>
using namespace std;

int main() {
    int s, n;
    pair<int, int> a[1000];
    cin >> s >> n;
    for (int i=0; i<n; i++)
        cin >> a[i].first >> a[i].second;
    sort(a, a+n);
    
    bool win = true;
    for (int i=0; i<n; i++)
        if (s > a[i].first)
            s += a[i].second;
        else {
            win = false;
            break;
        }
    
    if (win)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    
    return 0;
}