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
int main() {
    ios_base::sync_with_stdio(0);
    int z = 0, r = 0, e = 0, o = 0, n = 0;
    int nn;
    cin >> nn;
    while (nn--) {
        char c;
        cin >> c;
        if (c == 'z')
            z++;
        if (c == 'r')
            r++;
        if (c == 'e')
            e++;
        if (c == 'o')
            o++;
        if (c == 'n')
            n++;
    }
    int eo = min(e, o), zr = min(z, r);
    vector<int> ans;
    while (eo and n) {
        eo--;
        n--;
        ans.push_back(1);
    }
    while (eo and zr) {
        eo--;zr--;
        ans.push_back(0);
    }
    for (auto i : ans)
        cout << i << ' ';
}