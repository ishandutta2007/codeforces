#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> v;
    for(int i = 1; i <= 11; i++) {
        int x;
        cin >> x;
        v.push_back(x);
    }
    for(int i = 1; i <= 11; i++) {
        int u = v.back();
        v.pop_back();
        double a = sqrt(abs(u));
        double b = u*u*u*5.0;
        double result = a + b;
        if(400.0 < result) {
            cout << "f(" << u << ") = MAGNA NIMIS!\n";
        }
        else {
            cout << "f(" << u << ") = " << fixed << setprecision(2) << result << '\n';
        }
    }
}