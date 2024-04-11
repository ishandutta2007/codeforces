#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int row[10], n;
    fill(row, row + 10, 0);
    cin >> n;
    while(n--) {
        char c;
        cin >> c;
        if(c == 'L') {
            for(int i = 0; i < 10; i++) {
                if(row[i] == 0) {
                    row[i] = 1;
                    break;
                }
            }
        }
        else if(c == 'R') {
            for(int i = 9; i >= 0; i--) {
                if(row[i] == 0) {
                    row[i] = 1;
                    break;
                }
            }
        }
        else
            row[c - '0'] = 0;
    }
    for(int i = 0; i < 10; i++)
        cout << row[i];
    cout << endl;
}