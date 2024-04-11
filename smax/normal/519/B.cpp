#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int n;
    unordered_map<int, int> m1, m2;
    cin >> n;
    for (int i=0; i<n; i++) {
        int a;
        cin >> a;
        if (m1.find(a) != m1.end())
            m1[a]++;
        else
            m1.insert(make_pair(a, 1));
    }
    for (int i=0; i<n-1; i++) {
        int b;
        cin >> b;
        if (m1[b] > 1)
            m1[b]--;
        else
            m1.erase(b);
        if (m2.find(b) != m2.end())
            m2[b]++;
        else
            m2.insert(make_pair(b, 1));
    }
    cout << m1.begin()->first << endl;
    for (int i=0; i<n-2; i++) {
        int c;
        cin >> c;
        if (m2[c] > 1)
            m2[c]--;
        else
            m2.erase(c);
    }
    cout << m2.begin()->first << endl;
    
    return 0;
}