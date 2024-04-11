#include "list"
#include <iostream>
#include <vector>
#include <fstream>
#include <map>
#include "algorithm"
#include <iomanip>
#include "cmath"
#include "set"
#include <climits>
#define all(x) (x).begin(), (x).end()

using namespace std;
void solve(){
    int n;
    cin >> n;
    vector<string> pole(n);
    for(auto &i : pole)
        cin >> i;
    bool tob = false;
    for (int sdv = 0; sdv < 3; ++sdv) {
        for (int sdv2 = 0; sdv2 < 3; ++sdv2) {
            if (sdv == sdv2)
                continue;
            int cnt = 0, k = 0;
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    if (pole[i][j] != '.')
                        k++;
                    if (pole[i][j] == 'X' and ((i - j) % 3 + 3) % 3 == sdv)
                        cnt++;
                }
            }
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    if (pole[i][j] == 'O' and ((i - j) % 3 + 3) % 3 == sdv2)
                        cnt++;
                }
            }
            if (cnt <= k / 3) {
                for (int i = 0; i < n; ++i) {
                    for (int j = 0; j < n; ++j) {
                        if (pole[i][j] == 'X' and ((i - j) % 3 + 3) % 3 == sdv)
                            pole[i][j] = 'O';
                    }
                }
                for (int i = 0; i < n; ++i) {
                    for (int j = 0; j < n; ++j) {
                        if (pole[i][j] == 'O' and ((i - j) % 3 + 3) % 3 == sdv2)
                            pole[i][j] = 'X';
                    }
                }
                tob = true;
                break;
            }
        }
        if(tob)
            break;
    }
    for(auto i : pole)
        cout << i << '\n';
}
int main() {
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        solve();
    }
}