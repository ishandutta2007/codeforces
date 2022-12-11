#include <iostream>
#include <cstring>
#include <vector>
#include <string>

using namespace std;

typedef long long ll;

int main() {
    int h1, a1, h2, a2, c;
    cin >> h1 >> a1 >> c >> h2 >> a2;
    vector<int> a;
    while (h2 > a1) {
        if (h1 <= a2) {
            h1 = h1 + c;
            a.push_back(1);
        } else {
            a.push_back(0);
            h2 -= a1;
        }
        h1 -= a2;
    }
    cout << a.size() + 1 << endl;
    for (int i = 0; i < a.size(); ++i) {
        if (a[i] == 0) {
            cout << "STRIKE" << endl;
        } else {
            cout << "HEAL" << endl;
        }
    }
    cout << "STRIKE";
    return 0;
}