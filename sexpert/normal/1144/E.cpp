#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    vector<int> v1, v2, v;
    string s;
    cin >> n;
    cin >> s;
    for(auto c : s)
        v1.push_back(c - 'a');
    cin >> s;
    for(auto c : s)
        v2.push_back(c - 'a');
    for(int i = 0; i < n; i++)
        v.push_back(v1[i] + v2[i]);
    for(int i = n - 1; i >= 1; i--)
        if(v[i] > 25) {
            v[i] -= 26;
            v[i - 1] += 1;
        }

    for(int i = 0; i < n; i++) {
        cout << (char)('a' + v[i]/2);
        if(v[i] % 2)
            v[i + 1] += 26;
    }
    cout << endl;
}