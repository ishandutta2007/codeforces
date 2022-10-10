#include <bits/stdc++.h>
using namespace std;
  
int main() {
    int n, unchecked = 0, ret = 0;
    string a, b;
    unordered_map<int, int> m;
    cin >> n >> a >> b;
    for (int i=0; i<n; i++)
        if (a[i] == '1' && b[i] != '1')
            m.insert(make_pair(i, 1));
    if (b[0] == '1' && a[0] != '1') {
        if (m.find(1) == m.end())
            unchecked++;
        else {
            ret++;
            m.erase(1);
        }
    }
    for (int i=1; i<n-1; i++)
        if (b[i] == '1' && a[i] != '1') {
            if (m.find(i-1) != m.end()) {
                ret++;
                m.erase(i-1);
            } else if (m.find(i+1) != m.end()) {
                ret++;
                m.erase(i+1);
            } else
                unchecked++;
        }
    if (n > 1 && b[n-1] == '1' && a[n-1] != '1') {
        if (m.find(n-2) == m.end())
            unchecked++;
        else {
            ret++;
            m.erase(n-2);
        }
    }
    
    ret += min(unchecked, (int) m.size()) * 2 + max(unchecked, (int)m.size()) - min(unchecked, (int)m.size());
    cout << ret << endl;
    
    return 0;
}