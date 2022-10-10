#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int n;
    unordered_map<int, int> xm, ym;
    map<pair<int, int>, int> pm;
    
    cin >> n;
    for (int i=0; i<n; i++) {
        int x, y;
        cin >> x >> y;
        if (xm.count(x))
            xm[x]++;
        else
            xm.insert(make_pair(x, 1));
        if (ym.count(y))
            ym[y]++;
        else
            ym.insert(make_pair(y, 1));
        pair<int, int> p = make_pair(x, y);
        if (pm.count(p))
            pm[p]++;
        else
            pm.insert(make_pair(p, 1));
    }
    
    long long ret = 0;
    for (auto p : xm)
        ret += (long long) p.second * (long long) (p.second - 1) / 2;
    for (auto p : ym)
        ret += (long long) p.second * (long long) (p.second - 1) / 2;
    for (const auto &p : pm)
        ret -= (long long) p.second * (long long) (p.second - 1) / 2;
    
    cout << ret << endl;
    
    return 0;
}