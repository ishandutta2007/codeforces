#include <iostream>

using namespace std;

int main(){
    string s = "abc";
    int t; cin >> t;
    while (t--) {
        int n, k; cin >> n >> k;
        for (int i = 0; i < n; i++)
            cout << s[i%3];
        cout << "\n";
    }
    return 0;
}