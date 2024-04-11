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
    int n, q;
    cin >> n;
    vector<pair<int, int>> numpos(n);
    for (int i = 0; i < n; ++i) {
        cin >> numpos[i].second;
    }
    cin >> q;
    vector<int> elel;
    for (int i = 0; i < q; ++i) {
        int a;
        cin >> a;
        if (a == 1) {
            int p, x;
            cin >> p >> x;
            p--;
            numpos[p] = {elel.size(), x};
        } else {
            int x;
            cin >> x;
            elel.push_back(x);
        }
    }
    vector<int> suffnum(elel.size() + 1);
    for (int j = (int)elel.size() - 1; j >= 0; --j) {
        suffnum[j] = max(suffnum[j + 1], elel[j]);
    }
    for (int i = 0; i < n; ++i) {
      //  cerr << numpos[i].second << ' ' << numpos[i].first << endl;
        cout << max(numpos[i].second, suffnum[numpos[i].first]) << ' ';
    }
}