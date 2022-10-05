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
#define int long long
signed main() {
    ios_base::sync_with_stdio(0);
    string s;
    cin >> s;
    char minch = 'z';
    for (auto i : s) {
        if (i > minch)
            cout << "Ann\n";
        else
            cout << "Mike\n";
        minch = min(minch, i);
    } 
}