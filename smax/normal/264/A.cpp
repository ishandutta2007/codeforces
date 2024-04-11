#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    
    vector<int> left, right;
    for (int i=0; i<s.length(); i++) {
        if (s[i] == 'l')
            left.push_back(i+1);
        else
            right.push_back(i+1);
    }
    
    for (int i : right)
        cout << i << endl;
    for (auto it=left.rbegin(); it!=left.rend(); it++)
        cout << *it << endl;
    
    return 0;
}