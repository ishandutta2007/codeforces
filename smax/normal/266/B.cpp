#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, t;
    string s;
    cin >> n >> t >> s;
    
    for (int i=0; i<t; i++) {
        int index = 0;
        while (index < n - 1) {
            if (s[index] == 'B' && s[index+1] == 'G') {
                swap(s[index], s[index+1]);
                index++;
            }
            index++;
        }
    }
    
    cout << s << endl;
    
    return 0;
}