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
    for (int sdv = 0; sdv < 3; ++sdv) {
        int cnt = 0, k = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if(pole[i][j] != '.')
                    k++;
                if(pole[i][j] != '.' and ((i - j) % 3 + 3) % 3 == sdv)
                    cnt++;
            }
        }
        if(cnt <= k / 3){
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    if(pole[i][j] != '.' and ((i - j) % 3 + 3) % 3 == sdv)
                        pole[i][j] = 'O';
                }
            }
            break;
        }
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