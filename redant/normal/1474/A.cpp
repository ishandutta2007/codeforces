#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        string s; cin >> s;
        int last = -1;
        for (char c : s) {
            int ca = 1;
            int cb = c - '0';
            if (ca + cb == last) {
                ca = 1 - ca;
            }
            cout << ca << "";
            last = ca + cb;
        }
        cout << "\n";
    }

    return 0;
}