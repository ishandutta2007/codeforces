#include <bits/stdc++.h>
using namespace std;

int cur[20];

int main() {
    for(int i = 0; i < 20; i++)
        cur[i] = (1 << i);
    int s, l;
    cin >> s >> l;
    vector<int> v;
    int idx = 19;
    while(idx >= 0) {
        if(s < (1 << idx) || cur[idx] > l) {
            idx--;
            continue;
        }
        s -= (1 << idx);
        v.push_back(cur[idx]);
        cur[idx] += (1 << (idx + 1));
    }
    if(s != 0) {
        cout << -1 << endl;
        return 0;
    }
    cout << v.size() << endl;
    for(auto x : v)
        cout << x << " ";
    cout << endl;
}