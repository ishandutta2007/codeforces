#include <bits/stdc++.h>

using namespace std;

int main() {
    vector<int> a(4);
    for(int i = 0; i < 4; i++)
         cin >> a[i];
    
    for(int mask = 1; mask < 15; mask++) {
        int s = 0, s1 = 0;
        for(int i = 0; i < 4; i++)
        if(mask & (1 << i))
            s += a[i];
        else
            s1 += a[i];
            
        if(s == s1) {
            cout << "YES";
            return 0;
        }
    }
    
    cout << "NO";
}