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
    int n;
    cin >> n;
    vector <int> data;
    for (int i = 0 ; i < n; i++) {
        int x;
        cin >> x;
        if (data.size() > 0) {
            if (gsd(x, data.back()) > 1) {
                data.push_back(1);
            }
        }
        data.push_back(x);
    }
    cout << data.size() - n << endl;
    for (int i = 0; i < data.size(); i++) {
        cout << data[i] << " ";
    }
}