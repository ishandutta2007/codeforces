#include <bits/stdc++.h>
using namespace std;

int main() {
    char hello[] = "hello";
    string s;
    cin >> s;
    int i = 0;
    for (char c : s)
        if (c == hello[i]) {
            i++;
            if (i == 5)
                break;
        }
    if (i == 5)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    
    return 0;
}