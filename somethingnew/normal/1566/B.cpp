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
    string s;
    cin >> s;
    int t = 0;
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == '0') {
            t = 1;
            for (int j = i; j < s.size(); ++j) {
                if (s[j] == '1')
                    break;
                s[j] = '1';
            }
            break;
        }
    }
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == '0') {
            cout << "2\n";
            return;
        }
    }
    cout << t << '\n';
}
int main() {
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        solve();
    }
}