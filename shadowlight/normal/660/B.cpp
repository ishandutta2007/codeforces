#include <iostream>
#include <cstdio>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

int gsd(int a, int b) {
    if (b == 0) return a;
    return gsd(b, a % b);
}


int main() {
    int n, m;
    cin >> n >> m;
    int it = 1;
    vector <vector <int> > data(4, vector <int> (n, 0));
    for (int i = 0; i < 2 * n; i++) {
        if (it > m) break;
        data[it % 2][i / 2] = it;
        it++;
    }
    for (int i = 0; i < 2 * n; i++) {
        if (it > m) break;
        data[it % 2 + 2][i / 2] = it;
        it++;
    }
    for (int i = 0; i < n; i++) {
        if (data[3][i] != 0) cout << data[3][i] << " ";
        if (data[1][i] != 0) cout << data[1][i] << " ";
        if (data[2][i] != 0) cout << data[2][i] << " ";
        if (data[0][i] != 0) cout << data[0][i] << " ";
    }
}