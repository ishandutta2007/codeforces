#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> a;

int main() {
    string s;
    cin >> s;
    
    int n = 4;
    
    vector<vector<bool>> a(n, vector<bool>(n, false));
    for(auto c : s) {
        if(c == '1') {
            if(!a[0][0]) {
                a[0][0] = a[0][1] = true;
                cout << 1 << ' ' << 1 << endl;
            } else {
                cout << 1 << ' ' << 3 << endl;
                a[0][0] = a[0][1] = false;
            }
        } else {
            if(!a[3][3]) {
                cout << 3 << ' ' << 4 << endl;
                a[3][3] = a[2][3] = true;
            } else {
                cout << 1 << ' ' << 4 << endl;
                a[3][3] = a[2][3] = false;
            }
        }
    }
}