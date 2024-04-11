#include <bits/stdc++.h>
using namespace std;

int main() {
    int x, y, mov = 0;
    cin >> x >> y;
    vector<int> v {y, y, y};
    while(v[0] < x) {
        mov++;
        v[0] = min(v[1] + v[2] - 1, x);
        sort(v.begin(), v.end());
    }
    cout << mov << endl;
}