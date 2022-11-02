#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int T;
    cin >> T;
    for (int t = 0; t < T; t++) {
        int Y, X;
        cin >> Y >> X;
        string s;
        cin >> s;
        vector<int> ycount(X);
        int xcount = 0;
        vector<bool> xset(X);
        int firstrowcount = 0;
        for (int i = 0; i < Y*X; i++) {
            //int y = i / X;
            int x = i % X;
            if (s[i] == '1') {
                firstrowcount++;
            }
            if (i >= X && s[i - X] == '1') {
                firstrowcount--;
            }
            if (firstrowcount) {
                ycount[x]++;
            }
            if (s[i] == '1') {
                if (!xset[x]) {
                    xset[x] = true;
                    xcount++;
                }
            }
            cout << ycount[x] + xcount << " ";
        }
        cout << "\n";
    }
}